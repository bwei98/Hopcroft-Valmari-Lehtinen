#include <iostream>
#include <chrono>
#include "../include/dfa.h"
#include "../include/examples.h"
#include "../include/hopcroft.h"
#include "../include/valmari.h"

int main(int argc, char *argv[])
{
  int printres;
  std::cout<<"Would you like all the DFAs printed? (0 = no, 1 = yes)\n";
  std::cout<<"Note that Valmari will remove rejecting sink states.\n";
  std::cin>>printres;
  int choice;
  std::cout<<"\n Which DFA would you like to minimise? (Enter the number)\n"<<
  "(1) HW 05 Problem 3\n"<<
  "(2) Lecture 10 Slide 27\n"<<
  "(3) Wikipedia (DFA minimisation article)\n"<<
  "(4) Ring 100\n"<<
  "(5) Random DFA"<<std::endl;
  std::cin>>choice;
  DFA D = EX::rand(1,1);
  std::string name;
  switch(choice){
    case 1: { free(D.getTrans()); D = EX::hw05(); name = "hw05"; break; }
    case 2: { free(D.getTrans()); D = EX::lect10(); name = "lect10"; break; }
    case 3: { free(D.getTrans()); D = EX::wikipedia(); name = "wikipedia"; break; }
    case 4: { free(D.getTrans()); D = EX::ring(100); name = "ring100"; break; }
    case 5: {
        free(D.getTrans());
        int n, s;
        std::cout<<"How many states?"<<std::endl;
        std::cin>>n;
        std::cout<<"Size of alphabet?"<<std::endl;
        std::cin>>s;
        D = EX::rand(n,s);
        name = "random DFA";
        break;
      }
  }

  auto start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > HOP = Hopcroft::partition(D);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA VAL = Valmari::minimise(D);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  DFA HOPs = EX::rand(1,1);
  if(printres){
    std::cout<<"Initial DFA was:"<<std::endl;
    D.print(name);
    std::cout<<"Hopcroft Minimised is:"<<std::endl;
    DFA HOPs = Hopcroft::part2DFA(HOP, D);
    HOPs.print("Hopcroft");
    std::cout<<"Valmari-Lehtinen Minimised is:"<<std::endl;
    VAL.print("Valmairi");
  }

  return 0;
}
