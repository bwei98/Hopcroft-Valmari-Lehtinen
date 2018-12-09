#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../include/dfa.h"
#include "../include/valmari.h"


/* Refinable partition */
std::vector<int> M;
std::vector<int> W;
int w = 0;  // temporary worksets

struct partition{
	int z;
	std::vector<int> E, L, S, F, P;

	void init( int n ){
		z = bool( n );  E = std::vector<int>(n);
		L = std::vector<int> (n); S = std::vector<int> (n);
		F = std::vector<int> (n); P = std::vector<int> (n);
		for( int i = 0; i < n; ++i ){
			E[i] = L[i] = i; S[i] = 0; }
		if( z ){ F[0] = 0; P[0] = n; }
	}

	void mark( int e ){
		int s = S[e], i = L[e], j = F[s]+M[s];
		E[i] = E[j]; L[E[i]] = i;
		E[j] = e; L[e] = j;
		if( !M[s]++ ){ W[w++] = s; }
	}

	void split(){
		while( w ){
			int s = W[--w], j = F[s]+M[s];
			if( j == P[s] ){M[s] = 0; continue;}
			if( M[s] <= P[s]-j ){
				F[z] = F[s]; P[z] = F[s] = j; }
			else{
				P[z] = P[s]; F[z] = P[s] = j; }
			for( int i = F[z]; i < P[z]; ++i ){
				S[E[i]] = z; }
			M[s] = M[z++] = 0;
		}
	}

};

partition
	B,     // blocks (consist of states)
	C;     // cords (consist of transitions)

int
	nn,    // number of states
	mm,    // number of transitions
	ff,    // number of final states
	q0;    // initial state
std::vector<int>
	T,    // tails of transitions
	L,    // labels of transitions
	H;    // heads of transitions

bool cmp( int i, int j ){
	return L[i] < L[j]; }

/* Adjacent transitions */
std::vector<int> A, F;
void make_adjacent( std::vector<int> &K ){
	int q, t;
	for( q = 0; q <= nn; ++q ){ F[q] = 0; }
	for( t = 0; t < mm; ++t ){ ++F[K[t]]; }
	for( q = 0; q < nn; ++q )F[q+1] += F[q];
	for( t = mm; t--; ){ A[--F[K[t]]] = t; }
}

/* Removal of irrelevant parts */
int rr = 0;   // number of reached states

inline void reach( int q ){
	int i = B.L[q];
	if( i >= rr ){
		B.E[i] = B.E[rr]; B.L[B.E[i]] = i;
		B.E[rr] = q; B.L[q] = rr++; }
}

void rem_unreachable( std::vector<int> &T, std::vector<int> &H ){
	make_adjacent( T ); int i, j;
	for( i = 0; i < rr; ++i ){
		for( j = F[B.E[i]];
				 j < F[B.E[i] + 1]; ++j ){
			reach( H[A[j]] ); } }
	j = 0;
	for( int t = 0; t < mm; ++t ){
		if( B.L[T[t]] < rr ){
			H[j] = H[t]; L[j] = L[t];
			T[j] = T[t]; ++j; } }
	mm = j; B.P[0] = rr; rr = 0;
}

  /* Main program */
  void Valmari::win(DFA myDFA) {
    int nn = myDFA.getStates().size();
    int mm = myDFA.alph() * nn;
    int q0 = myDFA.init();

    std::vector<int> finals = myDFA.getFinals();

    int ff = finals.size();

    std::cout<<nn<<" "<<mm<<" "<<q0<<" "<<ff<<std::endl;

    /* Read sizes and reserve most memory */
    T = std::vector<int>(mm);
    L = std::vector<int>(mm);
    H = std::vector<int>(mm);
    B.init( nn );
    A = std::vector<int> (mm);
    F = std::vector<int> (nn+1);

    for (int c = 0, count = 0; c < myDFA.alph(); ++c) {
      for (int q = 0; q < nn; ++q, ++count) {
        T[count] = q; L[count] = c;
        H[count] = myDFA.getTrans()[q * myDFA.alph() + c];
      }
    }

    reach( q0 ); rem_unreachable( T, H );
    // for(int i = 0; i < H.size(); i++)
    //   std::cout<<T[i]<<" "<<L[i]<<" "<<H[i]<<std::endl;

    for (int q : finals) {
      if( B.L[q] < B.P[0] ) {
        reach( q ); }
    }
    ff = rr; rem_unreachable( H, T );


    /* Make initial partition */
    	W = std::vector<int> ( mm+1 );
      M = std::vector<int> ( mm+1);
    	M[0] = ff;
    	if( ff ){ W[w++] = 0; B.split(); }

    	/* Make transition partition */
    	C.init( mm );
    	if( mm ){
    		C.z = M[0] = 0; int a = L[C.E[0]];
    		for( int i = 0; i < mm; ++i ){
    			int t = C.E[i];
    			if( L[t] != a ){
    				a = L[t]; C.P[C.z++] = i;
    				C.F[C.z] = i; M[C.z] = 0; }
    			C.S[t] = C.z; C.L[t] = i; }
    		C.P[C.z++] = mm;
    	}

    	/* Split blocks and cords */
    	make_adjacent( H );
    	int b = 1, c = 0, i, j;
    	while( c < C.z ){
    		for( i = C.F[c]; i < C.P[c]; ++i ){
    			B.mark( T[C.E[i]] ); }
    		B.split(); ++c;
    		while( b < B.z ){
    			for( i = B.F[b]; i < B.P[b]; ++i ){
    				for(
    					j = F[B.E[i]];
    					j < F[B.E[i]+1]; ++j
    				){
    					C.mark( A[j] ); } }
    			C.split(); ++b; }
    	}

    /* Count the numbers of transitions
    and final states in the result */
    int mo = 0, fo = 0;
    for( int t = 0; t < mm; ++t ) {
      if( B.L[T[t]] == B.F[B.S[T[t]]] ){++mo; } }
    for( int b = 0; b < B.z; ++b ){
      if( B.F[b] < ff ){ ++fo; } }



    /* Print the result */
    std::cout<<"first line of results"<<std::endl;
    std::cout << B.z <<' '<< mo<<' '<< B.S[q0] <<' '<< fo <<'\n';

    std::cout<<"first for loop"<<std::endl;

    for( int t = 0; t < mm; ++t ) {
      if( B.L[T[t]] == B.F[B.S[T[t]]] ) {
        std::cout << B.S[T[t]] <<' '<< L[t]<<' '<< B.S[H[t]] <<'\n';
      } }

      std::cout<<"2nd for loop"<<std::endl;

      for( int b = 0; b < B.z; ++b ) {
        if( B.F[b] < ff ){std::cout << b <<'\n'; }
      }

      //return myDFA;
    }
