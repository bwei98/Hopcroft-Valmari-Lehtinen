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

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA hw05 = EX::hw05();
  std::cout<<"Example 1: DFA in HW 05 Problem 3"<<std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > hw05HOP = Hopcroft::partition(hw05);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA hw05VAL = Valmari::win(hw05);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA lect10 = EX::lect10();
  std::cout<<"Example 2: DFA in Lecture 10 Slide 27"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > l10HOP = Hopcroft::partition(lect10);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA l10VAL = Valmari::win(lect10);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA wiki = EX::wikipedia();
  std::cout<<"Example 3: DFA in from Wikipedia"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > wikiHOP = Hopcroft::partition(wiki);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA wikiVAL = Valmari::win(wiki);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA astarb = EX::astarb();
  std::cout<<"Example 4: A 6-state DFA for a*b"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > abHOP = Hopcroft::partition(astarb);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA abVAL = Valmari::win(astarb);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA r100 = EX::ring(100);
  std::cout<<"Example 5: Ring of size 100"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > r100HOP = Hopcroft::partition(r100);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA r100VAL = Valmari::win(r100);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA r1000 = EX::ring(1000);
  std::cout<<"Example 6: Ring of size 1000"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > r1000HOP = Hopcroft::partition(r1000);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA r1000VAL = Valmari::win(r1000);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA r21 = EX::rand(100,1);
  std::cout<<"Example 7: Random 100 state DFA, with unary alphabet"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > r21HOP = Hopcroft::partition(r21);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA r21VAL = Valmari::win(r21);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  std::cout<<"-----------------------------------------"<<std::endl;
  DFA r25 = EX::rand(1000,5);
  std::cout<<"Example 8: Random 100 state DFA, with size 5 alphabet"<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  std::vector< std::vector<int> > r25HOP = Hopcroft::partition(r25);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tHopcroft took "<<
    std::chrono::duration <double, std::milli> (end-start).count()<<
    " ms."<<std::endl;
  start = std::chrono::high_resolution_clock::now();
  DFA r25VAL = Valmari::win(r25);
  end = std::chrono::high_resolution_clock::now();
  std::cout<<"\tValmari took "<<
  std::chrono::duration <double, std::milli> (end-start).count()<<
  " ms."<<std::endl;

  return 0;
}
