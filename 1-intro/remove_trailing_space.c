#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int line_length_limit);
int trim_line(int line_length, char line[]);
void print_line(int line_length, char line[]);
int reset_line(char line[], int starting_idx, int line_length_limit);

int main() {
  int line_length;
  char line[MAXLINE];

  while ((line_length = get_line(line, MAXLINE)) > 0) {
    if (line_length == 1) continue;  // Ignore entirely blank lines
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

int trim_line(int line_length, char line[]) {
  int space_start_idx = -1;
  int i;

  for (i = 0; i < line_length && line[i] != '\n' && line[i] != '\0'; i++) {
    if (line[i] != ' ' && line[i] != '\t')
      space_start_idx = i;
  }
  line[++space_start_idx] = line[i];
  if (line[i] == '\n')
    line[++space_start_idx] = line[i + 1];
  reset_line(line, space_start_idx + 1, MAXLINE);

  return space_start_idx;
}

void print_line(int line_length, char line[]) {
  if (line_length < 1) return;

  printf("\nLine length: %d chars\n", line_length);
  printf("%s\n", line);
}

int reset_line(char line[], int starting_idx, int line_length_limit) {
  for (int i = starting_idx; i < line_length_limit; i++)
    line[i] = 0;

  return 0;
}
