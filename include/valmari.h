#include <cstdlib>
#include <vector>

class Valmari{
  public:
    static DFA win (DFA);
    static std::vector< std::vector<int> > partition (DFA);
    static DFA part2DFA (std::vector< std::vector<int> >, DFA);
};
