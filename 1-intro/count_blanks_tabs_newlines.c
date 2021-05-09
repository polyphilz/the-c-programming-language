#include <stdio.h>

int main() {
  int c;
  long nc = 0;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') ++nc;
  printf("%ld blanks, tabs and newlines entered.\n", nc);
}
