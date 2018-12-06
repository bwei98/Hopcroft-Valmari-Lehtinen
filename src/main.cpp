#include <cstdlib>
#include <iostream>
#include <iterator>
#include <chrono>
#include "../include/dfa.h"
#include "../include/examples.h"
#include "../include/hopcroft.h"

int main(int argc, char *argv[])
{
    DFA firstone = EX::hw05();

    std::vector< std::vector<int> > H = Hopcroft::partition(firstone);

    std::cout<<"\n\nANSWER H IS ";
    for (auto const& i: H) {
      std::cout<< "(";
      for (auto const& j: i) {
          std::cout << j << " ";
      }
      std::cout<< ") ";
    }
    std::cout << std::endl;
    DFA A = Hopcroft::part2DFA(H, firstone);

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

    DFA ring1 = EX::ring(1000);
    DFA ring2 = EX::ring(10000);
    DFA ring3 = EX::ring(50000);

    Hopcroft::partition(ring1);
    std::cout<<"ring1 done"<<std::endl;
    Hopcroft::partition(ring2);
    std::cout<<"ring2 done"<<std::endl;

    Hopcroft::partition(ring3);

    std::cout << "Hello World" << std::endl;
    std::cout << "Hello World" << std::endl << std::endl;
/*
auto start = std::chrono::steady_clock::now();
     DFA B = EX::rand(10,2);
     B.hopcroft();
auto end = std::chrono::steady_clock::now();
auto diff = end - start;
 std::cout << "10: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;


 start = std::chrono::steady_clock::now();
      DFA B2 = EX::rand(100,2);
      hopcroft();
 end = std::chrono::steady_clock::now();
 diff = end - start;
  std::cout << "100: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

   start = std::chrono::steady_clock::now();
       DFA B3 = EX::rand(1000,2);
       B3.hopcroft();
   end = std::chrono::steady_clock::now();
   diff = end - start;
   std::cout << "1000: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
        DFA B4 = EX::rand(10000,2);
        B4.hopcroft();
    end = std::chrono::steady_clock::now();
    diff = end - start;
  std::cout << "10000: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;


     start = std::chrono::steady_clock::now();
         DFA B5 = EX::rand(100000,2);
         B5.hopcroft();
     end = std::chrono::steady_clock::now();
     diff = end - start;
    std::cout << "100000: " <<std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    //std::vector< std::vector<int> > HB = B.hopcroft();

    std::cout<<"Hop done"<<std::endl;

//    DFA B2 = B.hopPartition2DFA(HB);

    std::cout<<"\nnum states: "<<B2.num_states()<<std::endl;
*/

    return 0;
}
