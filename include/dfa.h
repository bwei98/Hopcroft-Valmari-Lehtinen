#include <cstdlib>
#include <iostream>
#include <vector>

class DFA{
    int q0;
    std::vector<int> states;
    std::vector<int> finals;
    int* transitions;
    int alphabet_size;
  /* Format of transition matrix: T[i,j] represents the state that i goes to on
    input j */

  public:
      DFA (int, std::vector<int>, std::vector<int>, int*, int);
      DFA (int, int);
      std::vector<int> getStates (void);
      int* getTrans (void);
      std::vector<int> getFinals (void);
      int alph (void);
      int init (void);
      int num_states (void);
      int num_finals (void);
      std::vector< std::vector<int> > hopcroft (void);
      DFA hopPartition2DFA(std::vector< std::vector<int> >);
};
