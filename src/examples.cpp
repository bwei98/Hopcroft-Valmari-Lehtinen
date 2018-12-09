#include <vector>
#include <ctime>
#include "../include/dfa.h"
#include "../include/examples.h"

// This is the 13-state DFA presented in HW 05, Prob 3
DFA EX::hw05() {
  int q0 = 0;
  int states[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
  std::vector<int> Q (states, states+13);
  int finals[6] = {3,5,7,8,9,10};
  std::vector<int> F (13,0);
  for(int i : finals) {F[i] = 1;}
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

DFA EX::lect10() {
  int q0 = 0;
  int states[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  std::vector<int> Q (states, states+15);
  std::vector<int> F (15,0);
  F[12] = 1; F[13] = 1;
  int sigma = 2;
  int *trans = (int*)std::calloc(Q.size() * sigma, sizeof(int));

  trans[0] = 1; trans[1] = 2; trans[2] = 3; trans[3] = 4;
  trans[4] = 5; trans[5] = 6; trans[6] = 7; trans[7] = 8;
  trans[8] = 9; trans[9] = 10; trans[10] = 11; trans[11] = 12;
  trans[12] = 13; trans[13] = 14; trans[14] = 7; trans[15] = 8;
  trans[16] = 9; trans[17] = 10; trans[18] = 11; trans[19] = 12;
  trans[20] = 13; trans[21] = 14; trans[22] = 7; trans[23] = 8;
  trans[24] = 9; trans[25] = 10; trans[26] = 11; trans[27] = 12;
  trans[28] = 13; trans[29] = 14;

  DFA M (q0, Q, F, trans, sigma);
  return M;
}

DFA EX::ring(int size) {
  int q0 = 0;
  std::vector<int> Q;
  int sigma = 1;
  std::vector<int> F(size, 0); F[0] = 1;
  int *trans = (int*)std::calloc(size, sizeof(int));
  for (int i = 0; i < size; i++){
    Q.push_back(i);
    trans[i] = (i + 1) % size;
  }
  DFA M (q0, Q, F, trans, sigma);
  return M;
}

DFA EX::wikipedia() {
  int q0 = 0;
  int states[6] = {0,1,2,3,4,5};
  std::vector<int> Q (states, states+6);
  std::vector<int> F(6,0);
  F[2] = 1; F[3] = 1; F[4] = 1;
  int sigma = 2;
  int *trans = (int*)std::calloc(Q.size() * sigma, sizeof(int));
  trans[0] = 1; trans[1] = 2;
  trans[2] = 0; trans[3] = 3;
  trans[4] = 4; trans[5] = 5;
  trans[6] = 4; trans[7] = 5;
  trans[8] = 8; trans[9] = 5;
  trans[10] = 5; trans[11] = 5;

  DFA M (q0, Q, F, trans, sigma);
  return M;
}

DFA EX::astarb() {
  int q0 = 0;
  int states[6] = {0,1,2,3,4,5};
  std::vector<int> Q (states, states+6);
  int sigma = 2;
  std::vector<int> F (6,0);
  F[2] = 1; F[3] = 1;
  int *trans = (int*)std::calloc(12, sizeof(int));
  trans[0] = 1; trans[1] = 2; trans[2] = 1; trans[3] = 3;
  trans[4] = 4; trans[5] = 5; trans[6] = 5; trans[7] = 4;
  trans[8] = 4; trans[9] = 4; trans[10] = 5; trans[11] = 5;

  DFA M (q0, Q, F, trans, sigma);
  return M;
}

DFA EX::rand(int num_states, int alpha){
  std::srand(std::time(0));
  std::vector<int> Q;
  std::vector<int> F(num_states, 0);
  for(int i = 0; i < num_states; ++i){
    Q.push_back(i);
    if(std::rand() % 2) F[i] = 1;
  }
  int q0 = std::rand() % num_states;
  int transition_size = num_states * alpha;
  int* trans = (int*)std::calloc(transition_size, sizeof(int));
  for(int state = 0; state < num_states; state++)
  for(int tran_num = 0; tran_num <= alpha; tran_num++){
    int r = std::rand() % num_states;
    trans[state * alpha + tran_num] = r;
  }
  DFA M (q0, Q, F, trans, alpha);
  return M;
}
