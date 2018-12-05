#include <cstdlib>
#include <iostream>
#include <iterator>
#include "../include/dfa.h"
#include "../include/examples.h"

int main(int argc, char *argv[])
{
    DFA firstone = EX::hw05();

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

    std::cout<<"q0 = "<<A.init()<<std::endl<<"F = ";
    for (auto const& i: A.getFinals()) {
        std::cout << i << " ";
    }std::cout<<std::endl;

    for(int i = 0; i < A.getStates().size(); ++i){
      std::cout<<i<<" :";
      for(int j = 0; j < A.alph(); ++j)
        std::cout<<A.getTrans()[i * A.alph() + j] << " ";
      std::cout<<std::endl;
    }


    std::cout << "Hello World" << std::endl;
    std::cout << "Hello World" << std::endl << std::endl;

    DFA B (5, 2);
/*    std::cout<<"Finals are ";
    for (auto const& i: B.getFinals()) {
        std::cout << i << " ";
    }std::cout<<std::endl;
    std::cout<<"q0 = "<<B.init()<<std::endl;
    std::cout<<"States are ";
    for (auto const& i: B.getStates()) {
        std::cout << i << " ";
    }std::cout<<std::endl;

    for(int i = 0; i < B.getStates().size(); ++i){
      std::cout<<i<<" :";
      for(int j = 0; j < 2; ++j)
        std::cout<<B.getTrans()[i * 2 + j] << " ";
      std::cout<<std::endl;
    }
*/
    std::cout<<"creation"<<std::endl;

    std::vector< std::vector<int> > HB = B.hopcroft();
    DFA B2 = B.hopPartition2DFA(HB);

    std::cout<<"\n\nnum states: "<<B2.num_states()<<std::endl;


    return 0;
}
