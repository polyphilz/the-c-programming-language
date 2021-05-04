#include <stdio.h>

int main() {
  printf("  °c      °f\n");
  float celsius, fahr;

  int lower = -20;
  int upper = 300;
  int step = 20;
 
  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    printf("%6.1f   %3.0f\n", celsius, fahr);
    celsius += step;
  }
}
