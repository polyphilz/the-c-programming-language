#include <stdio.h>

int main() {
  int ndigits[10];
  int c, nspaces, nother;

  for (int i = 0; i < 10; i++)
    ndigits[i] = 0;
  nspaces = nother = 0;
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigits[c - '0'];
    else if (c == ' ' || c == '\t' || c == '\n')
      ++nspaces;
    else
      ++nother;
  }
  printf("\nNumber of spaces: %d\n", nspaces);
  printf("Number of non-numeric characters: %d\n", nother);
  for (int i = 0; i < 10; i++)
    printf("Number of digit %d: %d\n", i, ndigits[i]);
}
