#include <stdio.h>

#define LINE_LENGTH_CUTOFF 80
#define MAXLINE 1000

int get_line(char line[], int line_length_limit);
void print_line(int line_length, char line[]);
int reset_line(char line[], int line_length_limit);

int main() {
  int line_length;
  char line[MAXLINE];

  while ((line_length = get_line(line, MAXLINE)) > 0) {
    if (line_length >= LINE_LENGTH_CUTOFF) print_line(line_length, line);
    line_length = reset_line(line, MAXLINE);
  }

  return 0;
}

int get_line(char line[], int line_length_limit) {
  int i, c;

  for (i = 0; i < line_length_limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

void print_line(int line_length, char line[]) {
  printf("\nLine length: %d chars\n", line_length);
  printf("%s\n", line);
}

int reset_line(char line[], int line_length_limit) {
  for (int i = 0; i < line_length_limit; i++)
    line[i] = 0;

  return 0;
}
