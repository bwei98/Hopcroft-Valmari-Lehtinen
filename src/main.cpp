#include <cstdlib>
#include <iostream>
#include "../include/dfa.h"

int main(int argc, char *argv[])
{
    int q0 = 0;
    int states[4] = {0,1,2,3};
    std::set<int> Q (states, states+4);
    int finals[2] = {2,3};
    std::set<int> F (finals, finals+2);
    int *trans = (int*)std::calloc(16, sizeof(int));
    for(int i = 0; i < 16; i++)
      trans[i] = -1;
    int sigma = 1;

    DFA firstone (q0, Q, F, trans, sigma);
    std::cout << "num states = " << firstone.num_states() << std::endl;

    std::cout << "Hello World" << std::endl;
    std::free(trans);
    return 0;
}
