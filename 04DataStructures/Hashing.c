/*
Building a hash set from scratch in C
Storing student name and their test score

We learn:
1. How to use structs and struct array
2. char is already an int in C and doesn't have to be type cast (see hashFunction)
3. Basic operations for hash set: insert, search, delete

Constraints: Name must be a unique value as it is the primary key
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define SIZE 100
# define PRIME 127

/**
Basic data structure to hold key/value pair
key -> name
value -> score
*/
struct testScore {
  char *name;
  int score;
};

struct testScore* hashArray[SIZE];
struct testScore* score;
int hashFunction(char name[]);
void insert(char name[], int score);
struct testScore* search(char name[]);
void displayScores();
void delete(char name[]);

/**
A basic hash function
Add up the char values
Multiply it by a large prime to obtain a unique number
% by the size of the array to get a valid index number
*/
int hashFunction(char name[]) {
  int converted;
  int i;
  converted = 0;

  for (i = 0; i < strlen(name); i++) {
    converted += name[i];
  }
  // using abs() to ensure no index out of bounds
  return abs((converted * PRIME) % SIZE);
}

/**
Insert a key/value pair into our hash set
*/
void insert(char name[], int testScore) {
  struct testScore* score = (struct testScore*) malloc(sizeof(struct testScore));
  int hashIndex;

  score->name = name;
  score->score = testScore;
  hashIndex = hashFunction(name);

  // if index is not null, or hasn't been deleted
  // then increment to the next index to resolve collision
  while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->score != -1) {
    hashIndex++;
    hashIndex %= SIZE;
  }

  hashArray[hashIndex] = score;
}

struct testScore* search(char name[]) {
  int hashIndex;
  hashIndex = hashFunction(name);

  while(hashArray[hashIndex] != NULL) {
    if(hashArray[hashIndex]->name == name) {
      return hashArray[hashIndex];
    }
    hashIndex++;
    hashIndex %= SIZE;
  }
  return NULL;
}

void displayScores() {
  int i;
  int count = 01;
  for(i = 0; i < SIZE; i++) {
    if (hashArray[i] != NULL && hashArray[i]->score != -1) {
      printf("%d\tName: %s\tScore: %d\n", count, hashArray[i]->name, hashArray[i]->score);
      count++;
    }
  }
  printf("\n");
}

void delete(char name[]) {
  struct testScore* nameToDelete = search(name);
  //if name exists, set name to dummy value and score to sentinel value
  if (nameToDelete != NULL) {
    nameToDelete->name = "";
    nameToDelete->score = -1;
  }
}

int main() {
  // run unit tests
  insert("Alice", 95);
  insert("John", 90);
  insert("Kathy", 92);
  insert("Fred", 92);
  displayScores();
  delete("John");
  insert("Matt", 93);
  displayScores();
  return 0;
}
