#include <stdio.h>

int main() {
  int c;

  while (1) {
    if ((c = getchar()) == EOF) {
      printf("%d", c);
      break;
    }
  }
}
