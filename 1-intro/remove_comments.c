#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int line_length_limit);

int main() {
  int line_length;
  char line[MAXLINE];

  while ((line_length = get_line(line, MAXLINE)) > 0) {
    line_length = trim_line(line_length, line);
    print_line(line_length, line);
    line_length = reset_line(line, 0, MAXLINE);
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
