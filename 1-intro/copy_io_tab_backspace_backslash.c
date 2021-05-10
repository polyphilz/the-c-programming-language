#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {  // This probably won't work
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      printf("%c", c);
    }
  }
}
