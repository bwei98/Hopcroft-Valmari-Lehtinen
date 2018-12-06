#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include "../include/dfa.h"

DFA::DFA (int initial, std::vector<int> Q, std::vector<int> F, int* trans, int sigma) {
  q0 = initial;
  states = Q;
  finals = F;
  transitions = trans;
  alphabet_size = sigma;
}

std::vector<int> DFA::getStates() { return states; }

std::vector<int> DFA::getFinals() { return finals; }

int DFA::init() { return q0; }

int DFA::alph() { return alphabet_size; }

int* DFA::getTrans() { return transitions; }

int DFA::num_states() { return states.size(); }

int DFA::num_finals() { return finals.size(); }
