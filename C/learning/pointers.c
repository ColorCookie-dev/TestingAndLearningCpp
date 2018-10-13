#include <stdio.h>

int main() {
  int a = 9;
  int *ptr = &a;

  int my_array[5] = {1, 2, 3, 4, 5};

  int *my_array_ptr = my_array;

  printf("%x ---> %d\n", ptr, *ptr);

  for (;my_array_ptr < &my_array[5]; my_array_ptr++) {
    printf("%d\n", *my_array_ptr);
  }

  return 0;
}
