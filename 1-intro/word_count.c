#include <stdio.h>

#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */

int main() {
  int c, nc, nw, nl, state;

  nc = nw = nl = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n')
      ++nl;

    if (c == '\t' || c == ' ' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      ++nw;
      state = IN;
    }
  }

  printf("\nNumber of characters: %d\n", nc);
  printf("Number of words: %d\n", nw);
  printf("Number of newlines: %d\n", nl);
}
