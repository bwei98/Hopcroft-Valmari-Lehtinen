class EX{
  public:
    static DFA hw05 (void); // This is the 13-state DFA presented in HW 05, Prob 3
    static DFA lect10 (void); //This is the 15-state DFA presented in Lec 10, Slide 27
    static DFA ring (int); // generates a ring with unary alphabet
    static DFA wikipedia (void); //dfa pictured on wikipedia page for DFA minimisation
    static DFA astarb (void); //DFA accepting a*b
    static DFA rand (int, int); //random dfa with args numstates and alphabet size
};
