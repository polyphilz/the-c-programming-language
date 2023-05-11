#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char []);
void push_f(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push_f(atof(s));
        break;
      case '+':
        push_f(pop() + pop());
        break;
      case '*':
        push_f(pop() * pop());
        break;
      case '-':
        push_f((pop() - pop()) * -1);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push_f(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push_f(fmod(pop(), op2));
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push_f(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full\n");
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-') {
    return c;
  }
  i = 0;
  if (c == '-') {
    while (isdigit(s[++i] = c = getch()))
      ;
    if (c != EOF)
      ungetch(c);
    if (i == 1) {
      // '-' is operator, not sign for negative number
      s[i] = '\0';
      return '-';
    }
  }
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}