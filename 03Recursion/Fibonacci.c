/*
Write a recursive function that computes the nth fibonacci number
*/

# include <stdio.h>

int fib(int n);

int main() {
  int n;
  printf("Enter number: ");
  scanf("%d", &n);
  printf("The fib number: %d\n", fib(n));

  return 0;
}

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n-1) + fib(n-2);
}

int fibTernary(int n) {
  return (n < 2) ? n : fibTernary(n - 1) + fibTernary(n - 2);
}
