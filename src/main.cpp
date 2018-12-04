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
      trans[i] = (i+1) % 4;
    for(int i = 0; i < Q.size(); ++i){
      std::cout<<i<<" :";
      for(int j = 0; j < sigma; ++j)
        std::cout<<trans[i * sigma + j] << " ";
      std::cout<<std::endl;
    }


    DFA firstone (q0, Q, F, trans, sigma);
    std::cout << "num states = " << firstone.num_states() << std::endl;

    // for (auto const& i: Q) {
    //     std::cout << i << " ";
    // }
    std::cout << std::endl;

    std::vector< std::vector<int> > H = firstone.hopcroft();

    std::cout<<"\n\nANSWER H IS ";
    for (auto const& i: H) {
      std::cout<< "(";
      for (auto const& j: i) {
          std::cout << j << " ";
      }
      std::cout<< ") ";
    }
    std::cout << std::endl;
    DFA A = firstone.hopPartition2DFA(H);

    std::cout<<A.init()<<std::endl;
    for (auto const& i: A.getFinals()) {
        std::cout << i << " ";
    }std::cout<<std::endl;

    for(int i = 0; i < A.getStates().size(); ++i){
      std::cout<<i<<" :";
      for(int j = 0; j < sigma; ++j)
        std::cout<<A.getTrans()[i * sigma + j] << " ";
      std::cout<<std::endl;
    }


    std::cout << "Hello World" << std::endl;
    std::cout << "Hello World" << std::endl;


    return 0;
}
