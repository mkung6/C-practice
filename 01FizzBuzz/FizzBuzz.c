/*
Write a program that prints the numbers from 1 to 100.
But for the multiples of three print "Fizz" instead of the number
and for the multiples of five print "Buzz".
For the numbers which are multiples of both three and five print "FizzBuzz".
*/

# include <stdio.h>

void solutionOne();
void solutionTwo();

int main() {
  printf("SOLUTION ONE:\n");
  solutionOne();
  printf("SOLUTION TWO:\n");
  solutionTwo();
}

void solutionOne() {
  for (int i = 1; i <= 100; i++) {
    if (i % 3 != 0 && i % 5 != 0) {
      printf("%d\n",i);
    }
    if (i % 3 == 0) {
      printf("Fizz");
      // a solution to placing the newline character here to clean up output
      if (i % 5 != 0) {
        printf("\n");
      }
    }
    if (i % 5 == 0) {
      printf("Buzz\n");
    }
  }
}

// a solution to clean up the code to make it more readable and easier to follow
void solutionTwo() {
  for (int i = 1; i <= 100; i++) {
    // check if it's a multiple of 3 and 5 first in order to skip the other comparisons
    if (i % 15 == 0) {
      printf("FizzBuzz\n");
    }
    else if (i % 3 == 0) {
      printf("Fizz\n");
    }
    else if (i % 5 == 0) {
      printf("Buzz\n");
    }
    else {
      printf("%d\n",i);
    }
  }
}
