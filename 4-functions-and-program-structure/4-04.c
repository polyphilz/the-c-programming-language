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
double top(void);
void dup_top(void);
void swap_two_tops(void);
void clear_stack(void);

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
int stack_populated = 0;
double val[MAXVAL];

void push_f(double f)
{
  printf("Attempting to push %g...\n", f);

  double s_top = top();
  if (stack_populated == 1) {
    printf("(Pre-push) current top of stack: %g\n", s_top);
  }

  if (sp < MAXVAL) {
    val[sp++] = f;
    printf("Pushed %g successfully\n", f);
    printf("(Post-push) new top of stack: %g\n\n", top());
  } else {
    printf("Error: stack full\n");
    return;
  }
}

double pop(void)
{
  printf("Attempting to pop...\n");

  double s_top = top();
  if (stack_populated == 1) {
    printf("(Pre-pop) current top of stack: %g\n", s_top);
  }

  if (sp > 0) {
    --sp;
    printf("Popped %g successfully\n", s_top);

    s_top = top();
    if (stack_populated == 1) {
      printf("(Post-pop) new top of stack: %g\n\n", s_top);
    } else {
      printf("(Post-pop) stack now empty\n\n");
    }

    return val[sp];
  } else {
    printf("Error: stack empty\n");
    return 0.0;
  }
}

double top(void)
{
  if (sp > 0) {
    stack_populated = 1;
    return val[sp - 1];
  } else {
    stack_populated = 0;
    return 0.0;
  }
}

/* Duplicates top of stack (untested) */
void dup_top(void) {
  double s_top = top();
  if (sp < MAXVAL && stack_populated == 1) {
    val[sp++] = s_top;
  }
}

/* Swaps top two elements on stack (untested) */
void swap_two_tops(void) {
  if (sp > 1) {
    double s_top = pop();
    double s_top2 = pop();
    push_f(s_top);
    push_f(s_top2);
  } else {
    printf("Error: stack has less than 2 elements\n");
  }
}

/* Clears stack (untested) */
void clear_stack(void) {
  sp = 0;
  stack_populated = 0;
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