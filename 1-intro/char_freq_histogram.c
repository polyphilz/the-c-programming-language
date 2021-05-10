#include <stdio.h>

#define NUM_CHARACTERS_IN_ALPHABET 26  /* number of characters in English 
                                          alphabet */

int main() {
  int nchars[NUM_CHARACTERS_IN_ALPHABET];
  int c;

  for (int i = 0; i < NUM_CHARACTERS_IN_ALPHABET; i++)
    nchars[i] = 0;
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z')
      ++nchars[c - 'a'];
  }

  // prints a horizontal histogram
  for (int i = 0; i < NUM_CHARACTERS_IN_ALPHABET; i++) {
    printf("%c: ", 'a' + i);
    for (int j = 0; j < nchars[i]; j++)
      printf("x");
    printf("\n");
  }
}
