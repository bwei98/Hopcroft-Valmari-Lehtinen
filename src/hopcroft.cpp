#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../include/dfa.h"
#include "../include/hopcroft.h"

std::vector< std::vector<int> > Hopcroft::partition(DFA M){
  //P := {F, Q \ F}; O(n)
  std::vector<int> F = M.final_bits();
  std::vector<int> Q (M.num_states(), 1);
  std::vector<int> Fc (Q.size());
  for(int i = 0; i < Q.size(); ++i) Fc[i] = !F[i];
  std::vector< std::vector<int> >  P;
  P.insert(P.begin(), F); P.insert(P.begin() + 1, Fc);

  //  Ws := {F};
  std::vector< std::vector<int> > Ws;
  Ws.push_back(F);

  //while (Ws is not empty);
  while (Ws.size() > 0) {
    //choose and remove a set A from W;
    std::vector<int> A = Ws.front();
    Ws.erase(Ws.begin());

    //for each c in Σ do; O(s) iterations
    for (int c = 0; c < M.alph(); ++c){
      //let X be the set of states for which a transition on c leads to a state in A
      std::vector<int> X(Q.size());
      for(int q = 0; q < Q.size(); ++q)
      X[q] = A[M.getTrans()[M.alph() * q + c]];

      //for each set Y in P for which X ∩ Y is nonempty and Y \ X is nonempty do
      for (int y = P.size()-1; y >= 0 ; --y) {
        std::vector<int> Y = P[y], XintY(Q.size()), YsubX(Q.size());
        int sz_XintY = 0, sz_YsubX = 0;
        for(int q = 0; q < Q.size(); ++q) {
          sz_XintY += XintY[q] = Y[q] && X[q];
          sz_YsubX += YsubX[q] = Y[q] && !X[q];
        }
        if(sz_XintY && sz_YsubX) {
          //replace Y in P by the two sets X ∩ Y and Y \ X;
          P.erase(P.begin()+y);
          P.push_back(XintY); P.push_back(YsubX);

          //if Y is in W;
          int i = 0;
          for ( ; i < Ws.size(); ++i) if (Ws[i] == Y) break;
          if (i != Ws.size()) {
            //replace Y in W by the same two sets;
            Ws.erase(Ws.begin() + i);
            Ws.push_back(XintY); Ws.push_back(YsubX);
          } else {
            //if |X ∩ Y| > |Y \ X|;
            if (sz_XintY > sz_YsubX) //add Y \ X to W;
            Ws.push_back(YsubX);
            else //add X ∩ Y to W;
            Ws.push_back(XintY);
          }
        }
      }
    }
  }
  return P;
}

DFA Hopcroft::part2DFA(std::vector< std::vector<int> > P, DFA original) {
  for(int i = 0; i < P.size(); ++i) {
    std::vector<int> V;
    for(int j = 0; j < P[i].size(); ++j)
      if(P[i][j]) V.push_back(j);
        P[i] = V;
  }
  std::vector<int> finals = original.final_bits();
  int initial;
  std::vector<int> fin (P.size(), 0);
  std::vector<int> Q;
  int transition_size = original.alph() * P.size();
  int* trans = (int*)std::calloc(transition_size, sizeof(int));
  for (int i = 0; i < P.size(); ++i) {
    Q.push_back(i);
    fin[i] = finals[P[i][0]];
    for (int j = 0; j < P[i].size(); ++j)
      if (P[i][j] == original.init()) initial = i;
    for (int j = 0; j < original.alph(); ++j) {
      int dest = original.getTrans()[original.alph() * P[i][0] + j];
      bool done = false;
      for (int k = 0; k < P.size(); ++k) {
        if (done) break;
        for (int l = 0; l < P[k].size(); ++l)
          if (P[k][l] == dest) {
            trans[original.alph() * i + j] = k;
            done = true;
            break;
          }
      }
    }
  }

  return DFA(initial, Q, fin, trans, original.alph());
}
