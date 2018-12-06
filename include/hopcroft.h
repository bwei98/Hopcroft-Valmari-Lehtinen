#include <cstdlib>
#include <vector>

class Hopcroft{
  public:
    static std::vector< std::vector<int> > partition (DFA);
    static DFA part2DFA (std::vector< std::vector<int> >, DFA);
};
