/*
Introductory examples of pointers in C
*/

# include <stdio.h>

void passByValue(int x);
void passByReference(int *x);
//changing the value of a pointer
void example1();
void example2();
//showcasing size of pointer
void example3();
//pointer arithmetic example
void example4();
void example5();
void example6();

int main() {
  example1();
  example2();
  example3();
  example4();
  example5();
  example6();
}

/*
NOTE:
the unary operator & gives the address of an object
  p = &c;
assigns the address of c to the variable p
p is said to "point to c"
it only applies to objects in memory: variables and array elements
it cannot be applied to expressions, constants, or register variables

the * operator is indirection/dereferencing
when applied to a pointer, it accesses the object the pointer points to
*/
void passByValue(int x) {
  x++;
  printf("Inside passByValue function, the local variable is modified\n");
  printf("x = %d\n", x);
}

void passByReference(int *x) {
  x++;
}

void example1() {
  int x = 1;
  passByValue(x);
  printf("Outside pass by value, and the original variable in main is not modified\n");
  printf("x = %d\n", x);
  passByReference(&x);
  printf("Pass by reference, the function modifies the value located at that address, so x in main is now:\n");
  printf("x = %d\n", x);
}

void example2() {
  printf("example 2:\n");
  int *p;
  int x = 5;
  p = &x; //p is now pointing to x
  *p = 0; //sets value of x to zero
  *p++; //increments value at p
  *p += 1; //also increments value at p
  printf("x = %d\n", x);
  printf("p = %d\n", *p);
}

void example3() {
  //showing the different sizes of data types
  int arri[] = {1,2,3};
  int *ptri = arri;
  //assuming a compiler where an int takes 4 bytes
  //should output 12, 4 bytes for each int in the array
  printf("size of arri = %d\n", sizeof(arri));
  //assuming a compiler where a pointer takes 4 bytes
  //should output 4
  printf("size of ptri = %d\n", sizeof(ptri));

  char arrc[] = {1,2,3};
  char *ptrc = arrc;
  //char is 1 byte
  printf("size of arrc = %d\n", sizeof(arrc));
  //size of ptrc is 4 bytes
  printf("size of ptrc = %d\n", sizeof(ptrc));
}

void example4() {
  float a[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
  //p1 points to arr[0]
  float *p1 = &a[0];
  //p2 points to arr[3] due to pointer arithmetic
  float *p2 = p1 + 3;
  //output: 90.5
  printf("*p2 = %f\n", *p2);
  //output: 3
  //when we subtract two pointers, then we got number of elements between the two
  printf("p2 - p1 = %d\n", p2 - p1);
}

void example5() {
  int a[] = {10, 20, 30, 40, 50, 60};
  int *p1 = a;
  int *p2 = a + 5;
  //p1 points to a[0] and p2 points to a[5], or the 6th element in the array
  //output: 5
  printf("Number of elements between p1 and p2 are: %d\n",
    (p2 - p1));
  //(char*)p2 casts p2 as a char pointer, which is one byte
  //according to pointer arithmetic, num of blocks in between equals
  // diff between two pointers(address) / sizeof(each element of corresponding pointer)
  // so 5 * (sizeof(int)/sizeof(char))
  //output: 20
  printf("Number of bytes between two points are: %d\n",
    (char*)p2 - (char*)p1);
}
