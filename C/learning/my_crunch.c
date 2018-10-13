/*
This file needs work. This is an incomplete file!

This code mainly tries to replicate crunch, the wordlist generator. But only
focuses on the "-t" in the real crunch program. To know more about "-t" parameter
in the real crunch type "man crunch" in the terminal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
 
  char *letters = *(argv+1);             // Characters to be used
  char *pattern = *(argv+2);            // pattern to generate wordlists
  char ** changable_c = malloc(sizeof(*pattern));

  // getting all the pointers to the changable values
  int j = 0;
  for (int i=0; i < (sizeof(pattern)/sizeof(*pattern))+1; i++) {
    if (pattern[i] == '@') {
      *(changable_c+j) = (pattern+i);
      j++;
    }
  }

  // generating the wordlist
  j = 0;
  for (int i = 0; i < (sizeof(changable_c)/sizeof(*changable_c))+1; i++) {
    for (;j < (sizeof(letters)/sizeof(*letters)); j++) {
      *(*changable_c+i) = *(letters+j);
      printf("%s\n", pattern);
    }
  }

  // Clearing up the space
  free(changable_c);

}
