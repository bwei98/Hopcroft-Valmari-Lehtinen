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
      std::vector<int> getStates (void);
      int* getTrans (void);
      std::vector<int> get_finals (void);
      std::vector<int> final_bits (void);
      int alph (void);
      int init (void);
      int num_states (void);
      int num_finals (void);
      void print (std::string);
};
