#include <stdio.h>
#include <stdlib.h>

#define PASS "✅"
#define FAILURE "❌"

typedef struct test
{
  char *name;
  int failed;
  void (*int_eq)(struct test *t, int actual, int expected);
  char *err;
} Tester;

typedef struct
{
  int Total;
  int Failed;
  int Passed;
} Report;

typedef void (*Function)(Tester *r);

Report runTest(Function tests[], int count);

void assert_int_eq(Tester *t, int a, int b);