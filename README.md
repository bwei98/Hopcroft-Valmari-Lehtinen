# Hopcroft and Valmari-Lehtinen

Created by Brian Wei as final project for 15-354 Computational Discrete Math

Implements Hopcroft and Valmari-Lehtinen algorithms for DFA minimisation.  To use, enter "make" to create executable and "bin/runner" to run it.  Prompts will provide additional instructions.  There shouldn't be any additional dependencies which require download.  To experiment with additional DFAs, construct one manually in examples.cpp and add it to the list of options in main.cpp.

This implementation of Valmari-Lehtinen uses the code presented in "Fast brief practical DFA minimization" (Valmari 2011) with only slight midifications.  How the algorithm works exactly is beyond me.  The implementation of Hopcroft relies on the pseudocode from the lecture notes and wikipedia.

The performance of the algorithms have asymptotic run time, on a DFA with n states, alphabet size s, and m transitions, of Hopcroft: O(ns log n) and Valmari: O(n + m log n) as presented in their respective papers.  This turns out to be the same since m = ns.  However, from actually running the minimisation algorithms, Valmari runs significantly faster (2-3 times) on small DFAs and even better on larger ones.  Relative to their own performances, Hopcroft is much worse on DFAs that are already minimised or close to minimised while Valmari runs better on those.
