#include <stdio.h>

int main() {
  int lc, c;  // `lc` is last seen character; `c` is current character

  while ((c = getchar()) != EOF) {
    if (c == ' ' && lc == ' ')
      ;
    else
      printf("%c", c);
    lc = c;
  }
}
