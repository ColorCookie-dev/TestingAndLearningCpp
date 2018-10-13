/*
unions.c
*/
#include <stdio.h>

union intParts {
  int theInt;
  char Bytes[sizeof(int)];
};

int main() {
  union intParts parts;
  parts.theInt = 34554534;


  int theInt = 34556;
  printf("%c\n", ((char*)&theInt)[0]);

  return 0;
}
