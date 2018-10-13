#include <stdio.h>


// Factorial calculator
long long fact(long long num) {
  if (num == 0) {
    return 1;
  }
  return (num*fact(num-1));
}


int main() {
  long long num;

  while (1) {
    printf("Enter a number: ");
    if (scanf("%lld", &num) == 1) {
      break;
    }
    printf("[-] Please type an integer!\n");
    num = 0;
  }

  printf("%lld\n", fact(num));
}
