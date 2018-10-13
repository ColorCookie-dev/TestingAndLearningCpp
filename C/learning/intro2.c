#include <stdio.h>

void increase();

static unsigned long long increment = 0;

int main() {

  while (1) {
    increase();
    printf("%lld\n", increment);
  }

}

void increase() {
  increment++;
}
