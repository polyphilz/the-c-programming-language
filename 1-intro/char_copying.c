#include <stdio.h>

int main() {
  int c;

  /* EXERCISE 1.6 */
  // The precedence of `!=` is higher than `=`; therefore this produces
  // undesirable consequences. Specifically, this expression assigns the value
  // of 0 or 1 to `c`.
  /*while (c = getchar() != EOF) {*/
    /*printf("%d", c);*/
  /*}*/

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
