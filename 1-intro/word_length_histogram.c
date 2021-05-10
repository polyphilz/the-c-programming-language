#include <stdio.h>

#define MAX_WORD_LENGTH 20  /* max length of word recorded in histogram */
#define IN  1               /* inside a word */
#define OUT 0               /* outside a word */

int main() {
  int num_words_of_length[MAX_WORD_LENGTH + 1];  // [0] is largely ignored
  int c, cwl, state;  // cwl is current word length

  for (int i = 0; i < MAX_WORD_LENGTH + 1; i++)
    num_words_of_length[i] = 0;
  cwl = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      // if cwl is > MAX_WORD_LENGTH, we just ignore it
      if (state == IN && cwl <= MAX_WORD_LENGTH) {
        ++num_words_of_length[cwl];
        cwl = 0;
      }
      state = OUT;
    } else {
      ++cwl;
      state = IN;
    }
  }

  // prints a horizontal histogram
  for (int i = 1; i < MAX_WORD_LENGTH + 1; i++) {
    printf("%2d: ", i);
    for (int j = 0; j < num_words_of_length[i]; j++)
      printf("x");
    printf("\n");
  }
}
