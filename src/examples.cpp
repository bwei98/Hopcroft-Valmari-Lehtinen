#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../include/dfa.h"
#include "../include/examples.h"

// This is the 13-state DFA presented in HW 05, Prob 3
DFA EX::hw05(){
  int q0 = 0;
  int states[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
  std::vector<int> Q (states, states+13);
  int finals[6] = {3,5,7,8,9,10};
  std::vector<int> F (finals, finals+6);
  int sigma = 2;
  int *trans = (int*)std::calloc(Q.size() * sigma, sizeof(int));

  trans[0] = 1; trans[1] = 2; trans[2] = 3; trans[3] = 4;
  trans[4] = 5; trans[5] = 6; trans[6] = 7; trans[7] = 11;
  trans[8] = 11; trans[9] = 9; trans[10] = 8; trans[11] = 12;
  trans[12] = 11; trans[13] = 10; trans[14] = 12; trans[15] = 11;
  trans[16] = 11; trans[17] = 11; trans[18] = 12; trans[19] = 12;
  trans[20] = 11; trans[21] = 11; trans[22] = 11; trans[23] = 12;
  trans[24] = 12; trans[25] = 11;

  DFA M (q0, Q, F, trans, sigma);
  return M;
}
