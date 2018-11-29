#include <cstdlib>
#include <iostream>
#include <set>
#include "../include/dfa.h"


DFA::DFA (int initial, std::set<int> Q, std::set<int> F, char *trans, char *sigma) {
  q0 = initial;
  states = Q;
  finals = F;
  transitions = trans;
  alphabet = sigma;
}

int DFA::num_states() {
  return states.size();
}
