#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_custom(char line[], int max);
int strindex(char source[], char search_for[]);
int strrindex(char source[], char search_for[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINE];

  while((getline_custom(line, MAXLINE)) > 0) {
    if (strrindex(line, pattern) >= 0) {
      printf("%s", line);
    }
  }
}

int getline_custom(char line[], int max_chars)
{
  int i = 0;
  int c = getchar();
  while (c != EOF && c != '\n' && i < max_chars) {
    line[i++] = c;
    c = getchar();
  }
  if (c == '\n') {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}

// Returns the position of the leftmost occurence of search_for in source
int strindex(char source[], char search_for[])
{
  int source_len = strlen(source);
  int search_for_len = strlen(search_for);

  for (int i = 0; i <= source_len - search_for_len; i++) {
    int k = 0;
    for (int j = i; j < i + search_for_len; j++) {
      if (source[j] != search_for[k]) {
        break;
      }
      k++;
    }
    if (k == search_for_len) {
      return i;
    }
  }
  return -1;
}

// Returns the position of the rightmost occurence of search_for in source
int strrindex(char source[], char search_for[])
{
  int source_len = strlen(source);
  int search_for_len = strlen(search_for);

  for (int i = source_len - 2; i >= search_for_len - 1; i--) {
    int k = search_for_len - 1;
    for (int j = i; j > i - search_for_len; j--) {
      if (source[j] != search_for[k]) {
        break;
      }
      k--;
    }
    if (k == -1) {
      return i - search_for_len + 1;
    }
  }
  return -1;
}