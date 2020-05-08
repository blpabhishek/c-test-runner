#include <stdio.h>
#include "test.h"

void assert_int_eq(Tester *t, int actual, int expected)
{
  if (t->failed)
    return;
  int result = !(actual == expected);
  if (result){
    t->failed = result;
    sprintf(t->err, "Expected:%d Actual:%d", expected, actual);
  }
};

Tester *createTest()
{
  Tester *test = malloc(sizeof(Tester));
  test->failed = 0;
  test->err = malloc(sizeof(50));
  test->int_eq = assert_int_eq;
  // can add more assert functions here
  return test;
}

void printResult(Tester *test){
  printf("%s) %s \n", test->failed ? FAILURE : PASS, test->name);
  if (test->failed)
  {
    printf("\t-------------------\n");
    printf("\t%s\n", test->err);
    printf("\t-------------------\n");
  }
  free(test->err);
  free(test);
}

Report runTest(Function tests[], int count)
{
  Report report;
  for (int i = 0; i < count; i++)
  {
    Tester *test = createTest();
    tests[i](test);
    report.Failed += test->failed;
    report.Total++;
    printResult(test);
  }
  report.Passed = report.Total - report.Failed;
  return report;
}