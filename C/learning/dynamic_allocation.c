// This file is used to understand the concept of dynamic allocation

#include <stdlib.h>      // Main library to include in this file
#include <stdio.h>
#include <string.h>


typedef struct {
  char *name;
  int age;
} people;


int main() {
  people *myperson = malloc(sizeof(people));     // allocates a dynamic location in the memory of the size of the struct person
  myperson->name = "New Learner!";
  myperson->age = 34;

  printf("name: %s, age: %d\n", myperson->name, myperson->age);

  free(myperson);

  return 0;
}
