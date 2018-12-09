#include <vector>
#include <iostream>
#include "../include/dfa.h"

DFA::DFA (int initial, std::vector<int> Q, std::vector<int> F, int* trans, int sigma) {
  q0 = initial;
  states = Q;
  finals = F;
  transitions = trans;
  alphabet_size = sigma;
}

std::vector<int> DFA::getStates() { return states; }

std::vector<int> DFA::final_bits() { return finals; }

std::vector<int> DFA::get_finals() {
  std::vector<int> fin;
  for(int i = 0; i < num_states(); ++i)
    if(finals[i]) fin.push_back(i);
  return fin;
}

int DFA::init() { return q0; }

int DFA::alph() { return alphabet_size; }

int* DFA::getTrans() { return transitions; }

int DFA::num_states() { return states.size(); }

int DFA::num_finals() { return finals.size(); }

void DFA::print(std::string name) {
  std::cout<<"Printing DFA "<<name<<"..."<<
    "\n Alphabet Size:"<< alphabet_size<<
    "\n Initial State:"<< q0<<
    "\n Number of states:"<< num_states()<<
    "\n Final states:";
    for (auto const& j: get_finals()) {
           std::cout << j << " ";
    }
    std::cout<<"\n Transitions: "<<std::endl;
    for(int q = 0; q < num_states(); ++q){
      std::cout<<q<<": ";
      for(int i = 0; i < alphabet_size; ++i)
        std::cout<<transitions[q*alphabet_size + i]<<" ";
    std::cout<<std::endl;
    }
    std::cout<<"End of DFA"<<std::endl;
}
