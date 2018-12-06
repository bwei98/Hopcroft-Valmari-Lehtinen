#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../include/dfa.h"
#include "../include/hopcroft.h"

std::vector< std::vector<int> > Hopcroft::partition(DFA M){ //O(n^2 s log n)
  //P := {F, Q \ F}; O(n)
  std::vector<int> F = M.getFinals();
  std::vector<int> Q = M.getStates();
  std::vector<int> Fc(Q.size());
  for (int i = 0; i < Fc.size(); i++) Fc[i] = -1;
  std::set_difference(Q.begin(), Q.end(), F.begin(),  F.end(), Fc.begin());
  for (int i = Fc.size() - 1; i >= 0; --i)
    if (Fc[i] == -1) Fc.pop_back(); else break;
  std::vector< std::vector<int> >  P;
  P.insert(P.begin(), F); P.insert(P.begin() + 1, Fc);

  //  Ws := {F}; O(n)
  std::vector< std::vector<int> > Ws;
  Ws.push_back(F);

  //while (Ws is not empty); O(log n) iterations
  while (Ws.size() > 0) {

    //choose and remove a set A from W; O(1)
    std::vector<int> A = Ws.front();
    Ws.erase(Ws.begin());

    //for each c in Σ do; O(s) iterations
    for (int c = 0; c < M.alph(); ++c){
      //let X be the set of states for which a transition on c leads to a state in A
      std::vector<int> X;
      for (int q = 0; q < Q.size(); q++) {
        for (int qa = 0; qa < A.size(); qa++) {
          if (M.getTrans()[M.alph() * q + c] == A[qa])
            X.push_back(q);
        }
      }

      //for each set Y in P for which X ∩ Y is nonempty and Y \ X is nonempty do
        // O(n) iterations
      for (int y = P.size()-1; y >= 0; --y) {
        // O(n) to compute Y
        std::vector<int> Y = P[y];
        std::vector<int> XintY(std::min(X.size(),Y.size()));
        std::vector<int> YsubX(Y.size());
        for (int i = 0; i < XintY.size(); ++i) XintY[i] = -1;
        for (int i = 0; i < YsubX.size(); ++i) YsubX[i] = -1;
        std::set_intersection (X.begin(), X.end(), Y.begin(), Y.end(), XintY.begin());
        std::set_difference (Y.begin(), Y.end(), X.begin(), X.end(), YsubX.begin());
        for (int i = XintY.size() - 1; i >= 0; --i)
          if (XintY[i] == -1) XintY.pop_back(); else break;
        for (int i = YsubX.size() - 1; i >= 0; --i)
          if (YsubX[i] == -1) YsubX.pop_back(); else break;
        if (!XintY.empty() && !YsubX.empty()) {
          //replace Y in P by the two sets X ∩ Y and Y \ X; O(1)
          P.erase(P.begin()+y);
          P.push_back(XintY); P.push_back(YsubX);

          //if Y is in W; O(n)
          int i = 0;
          for ( ; i < Ws.size(); i++) if (Ws[i] == Y) break;
          if (i != Ws.size()) {
            //replace Y in W by the same two sets; O(1)
            Ws.erase(Ws.begin() + i);
            Ws.push_back(XintY);
            Ws.push_back(YsubX);
          } else {
            //if |X ∩ Y| <= |Y \ X|; O(1)
            if (XintY.size() <= YsubX.size()) //add X ∩ Y to W; O(1)
              Ws.push_back(XintY);
            else //add Y \ X to W; O(1)
              Ws.push_back(YsubX);

          }
        }
      }
    }
  }
  return P;
}

DFA Hopcroft::part2DFA(std::vector< std::vector<int> > P, DFA original) {
  int initial;
  std::vector<int> fin;
  std::vector<int> Q;
  int transition_size = original.alph() * P.size();
  int* trans = (int*)std::calloc(transition_size, sizeof(int));
  for (int i = 0; i < P.size(); ++i) {
    Q.push_back(i);
    for (int j = 0; j < original.getFinals().size(); ++j) {
      if (P[i][0] == original.getFinals()[j]) {
        fin.push_back(i);
        break;
      }
    }
    for (int j = 0; j < P[i].size(); ++j) {
      if (P[i][j] == original.init()) initial = i;
      // else std::cout<<"Hopcroft failed"<<std::endl;
    }
    for (int j = 0; j < original.alph(); ++j) {
      int dest = original.getTrans()[original.alph() * P[i][0] + j];
      bool done = false;
      for (int k = 0; k < P.size(); ++k) {
        if (done) break;
        for (int l = 0; l < P[k].size(); ++l) {
          if (P[k][l] == dest) {
            trans[original.alph() * i + j] = k;
            done = true;
            break;
          }
        }
      }
    }
  }

  return DFA(initial, Q, fin, trans, original.alph());
}
