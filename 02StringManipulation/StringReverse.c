/*
Write a function that reverses a string.
*/

# include <stdio.h>
# include <string.h>

# define TEMP_SIZE 100

char * reverse(char s[]);
char * reverseNumberTwo(char s[]);

char * reverse(char s[]) {
  // initialize a temporary char array with a size to hold one char
  char temp[1];
  for (int i = 0; i < strlen(s) / 2; i++) {
    temp[0] = s[i];
    // needs to be strlen() - i - 1 because otherwise
    // strlen() - i will access the \0 at the end of the char array
    s[i] = s[strlen(s) - i - 1];
    s[strlen(s) - i - 1] = temp[0];
  }
  return s;
}

char * reverseNumberTwo(char s[]) {
  // another way to reverse a string by writing better for loop conditions
  // and by using int temp instead of char temp[]
  // char is considered a 1 byte integer type, so you can store the char code in an int
  int temp, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
  return s;
}

int main() {
  char unitTestOne[] = "abc";
  char unitTestTwo[] = "";
  char unitTestThree[] = "a";
  char unitTestFour[] = "tacocat";
  char unitTestFive[] = "really long string";
  // copy the string to print it for reference first
  // because char array is passed by value and will be reversed
  // as the printf() is being evaluated
  char temp[TEMP_SIZE];
  strcpy(temp, unitTestOne);
  printf("String: %s\nReversed: %s\n",temp,reverse(unitTestOne));
  strcpy(temp, unitTestTwo);
  printf("String: %s\nReversed: %s\n",temp,reverse(unitTestTwo));
  strcpy(temp, unitTestThree);
  printf("String: %s\nReversed: %s\n",temp,reverse(unitTestThree));
  strcpy(temp, unitTestFour);
  printf("String: %s\nReversed: %s\n",temp,reverse(unitTestFour));
  strcpy(temp, unitTestFive);
  printf("String: %s\nReversed: %s\n",temp,reverse(unitTestFive));

  strcpy(temp, unitTestOne);
  printf("String: %s\nReversed: %s\n",temp,reverseNumberTwo(unitTestOne));
}
