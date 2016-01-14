================================================================================
README
================================================================================

--------------------------------------------------------------------------------
FILE DESCRIPTIONS
--------------------------------------------------------------------------------
all.c - contains all 3 algorithms
      - runs algorithms with inputs from files
      - outputs results to a file called maxsums.txt

enumeration.c - contains enumeration algorithm
              - runs the algorithm with randomly generated inputs
              - times the runtime

betterenumeration.c - contains better enumeration algorithm
                    - runs the algorithm with randomly generated inputs
                    - times the runtime

dynamicprogramming.c - contains dynamic algorithm
                     - runs the algorithm with randomly generated inputs
                     - times the runtime

WriteUp1.pdf - contains the write up for the assignment

--------------------------------------------------------------------------------
RUNNING THE PROGRAM
--------------------------------------------------------------------------------

to run the program with inputs from the given validation.txt file and output the
maxsums to maxsums.txt, execute:
    gcc ./all.c
    ./a.out

to run and time each algorithm for 100-900 and 1000-9000 randomly generated
numbers, execute:
    gcc ./<algorithmname>.c
    ./a.out
where <algorithmname> is either enumeration, betterenumeration, or
dynamicprogramming

note: running the indevidual algorithms with timing will only output runtimes
  to the screen, not the max sums.

