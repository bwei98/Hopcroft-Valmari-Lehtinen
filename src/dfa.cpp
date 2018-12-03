#include <cstdlib>
#include <iostream>
#include <set>
#include<ctime>
#include "../include/dfa.h"


DFA::DFA (int initial, std::set<int> Q, std::set<int> F, int* trans, int sigma) {
  q0 = initial;
  states = Q;
  finals = F;
  transitions = trans;
  alphabet_size = sigma;
}

DFA::DFA (int num_states, int alphabet_size) {
  std::srand(std::time(0));
  std::set<int> Q, F;
  for(int i = 0; i < num_states; i++){
    Q.insert(i);
    if(std::rand() % 2) F.insert(i);
  }
  states = Q;
  finals = F;
  q0 = std::rand() % num_states;
  int transition_size = num_states * num_states;
  int* trans = (int*)std::calloc(transition_size, sizeof(int));
  for(int i = 0; i < transition_size; i++) trans[i] = -1;
  for(int i = 0; i < transition_size; i++){
    int num = 0;
    while(num < alphabet_size)
    {
      int r = std::rand() % num_states;
      if(trans[num_states * i + r] != -1){
        trans[num_states * i + r] = num;
        num++;
      }
    }
  }
  transitions = trans;
  alphabet_size = alphabet_size;
}

int DFA::num_states() {
  return states.size();
}
