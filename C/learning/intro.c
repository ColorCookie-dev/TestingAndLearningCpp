#include <stdio.h>
#include <string.h>


int sum(int a, int b);

int main()
{
  printf("Hello world!\n");

  // var init
  int a = 12, b = 23;
  float c = 15.236453645325342434232;
  printf("%f\n", a+b+c);

  // arrays
  int my_array[5];
  my_array[0] = 10000.9435;
  my_array[1] = 20;
  my_array[2] = 40;
  my_array[3] = 50;
  my_array[4] = 560;
  my_array[5] = 550;
  my_array[6] = 540;

  // printing the values in the array
  for (int i = 0; i < 30; i++) {         // a for loop
    printf("%d\n",my_array[i]);
  }

  // muti-dimensional arrays
  int multi_dim[3][2][1] = {
    {{2}, {3}},
    {{4}, {5}},
    {{6}, {7}}
  };

  printf("%d\n", multi_dim[2][1][0]);

  // Strings
  char name[] = "Hamilton";
  printf("%s\n", name);

  if (strncmp(name, "Hamilton", strlen("Hamilton")) == 0) { // 0 is reurned if strings match
    printf("%s\n", "This worked!");
  }

  printf("%d\n", sum(3, 4));

  return 0;
}


// summing
int sum(int a, int b)
{
  return a+b;
}
