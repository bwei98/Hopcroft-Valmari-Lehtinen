#include <cstdlib>
#include <iostream>
#include <set>

class DFA{
    int q0;
    std::set<int> states;
    std::set<int> finals;
    int alphabet_size;
    int* transitions;

  public:
      DFA (int, std::set<int>, std::set<int>, int*, int);
      DFA (int, int);
      int num_states (void);
};
