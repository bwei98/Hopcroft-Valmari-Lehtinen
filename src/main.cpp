#include <cstdlib>
#include <iostream>
#include <iterator>
#include <chrono>
#include "../include/dfa.h"
#include "../include/examples.h"
#include "../include/hopcroft.h"
#include "../include/valmari.h"

int main(int argc, char *argv[])
{
  int printres;
  std::cout<<"Would you like result DFAs printed? (0 = no, 1 = yes)\n";
  std::cout<<"Note that this will create LOTS of output!";
  std::cin>>printres;
  int choice;
  std::cout<<"\n Which DFA would you like to minimize? (Enter the number)\n"<<
  "(1) HW 05 Problem 3\n"<<
  "(2) Lecture 10 Slide 27\n"<<
  "(3) Wikipedia (DFA minimization article)\n"<<
  "(4) Ring 100\n"<<
  "(5) Ring 1000\n"<<
  "(6) Random DFA"<<std::endl;
  std::cin>>choice;
  DFA D = EX::rand(1,1);
  switch(choice){
    case 1: { D = EX::hw05(); break; }
    case 2: { D = EX::lect10(); break; }
    case 3: { D = EX::wikipedia(); break; }
    case 4: { D = EX::ring(100); break; }
    case 5: { D = EX::ring(1000); break; }
    case 6: {
        int n, s;
        std::cout<<"How many states?"<<std::endl;
        std::cin>>n;
        std::cout<<"Size of alphabet?"<<std::endl;
        std::cin>>s;
        D = EX::rand(n,s);
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
  DFA VAL = Valmari::win(D);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;
  free(D.getTrans()); free(VAL.getTrans());

  return 0;
}
