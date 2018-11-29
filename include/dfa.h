#include <cstdlib>
#include <iostream>
#include <set>

class DFA{
    int q0;
    std::set<int> states;
    std::set<int> finals;
    char *transitions;
    char *alphabet;

  public:
      DFA (int, std::set<int>, std::set<int>, char*, char*);
      int num_states (void);
};
