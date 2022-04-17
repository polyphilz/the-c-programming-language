#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int line_length_limit);
void reverse(int line_length, char line[]);
void print_line(int line_length, char line[]);
int reset_line(char line[], int line_length_limit);

int main() {
  int line_length;
  char line[MAXLINE];

  while ((line_length = get_line(line, MAXLINE)) > 0) {
    reverse(line_length, line);
    print_line(line_length, line);
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

void reverse(int line_length, char line[]) {
  int start = 0;
  int end = line_length - 1;
  if (line[end] == '\n')
    end--;

  while (start < end) {
    int tmp = line[start];
    line[start++] = line[end];
    line[end--] = tmp;
  }
}

void print_line(int line_length, char line[]) {
  if (line_length < 1) return;

  printf("\nLine length: %d chars\n", line_length);
  printf("%s\n", line);
}

int reset_line(char line[], int line_length_limit) {
  for (int i = 0; i < line_length_limit; i++)
    line[i] = 0;

  return 0;
}
