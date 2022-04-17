#include <stdio.h>

void print_table(int lower, int upper, int step);
float convert_fahr_to_celsius(float fahr);

int main() {
  print_table(0, 300, 20);

  return 0;
}

void print_table(int lower, int upper, int step) {
  printf(" °f    °c\n");
  float fahr, celsius;
 
  fahr = lower;
  while (fahr <= upper) {
    celsius = convert_fahr_to_celsius(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr += step;
  }
}

float convert_fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
