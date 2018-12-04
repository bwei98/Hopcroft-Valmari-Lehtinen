#include <cstdlib>
#include <iostream>
#include <iterator>
#include "../include/dfa.h"

int main(int argc, char *argv[])
{
    int q0 = 0;
    int states[4] = {0,1,2,3};
    std::vector<int> Q (states, states+4);
    int finals[2] = {2,3};
    std::vector<int> F (finals, finals+2);
    int sigma = 1;
    int *trans = (int*)std::calloc(Q.size() * sigma, sizeof(int));
    for(int i = 0; i < sigma * Q.size(); i++)
      trans[i] = -1;

    DFA firstone (q0, Q, F, trans, sigma);
    std::cout << "num states = " << firstone.num_states() << std::endl;


    for (auto const& i: Q) {
        std::cout << i << " ";
    }

    std::cout << "Hello World" << std::endl;
    std::cout << "Hello World" << std::endl;

    for (auto const& i: firstone.getStates()) {
        std::cout << i << " ";
    }

    return 0;
}
