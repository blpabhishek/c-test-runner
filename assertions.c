#include "test.h"

void assert_int_eq(Tester *t, int a, int b)
{
  if (t->failed)
    return;
  t->failed = !(a == b);
};

Tester *createTest(){
  Tester *test = malloc(sizeof(Tester));
  test->int_eq = assert_int_eq;
  // can add more assert functions here 
  return test;
}

Report runTest(Function tests[], int count)
{
  Report report;
  for (int i = 0; i < count; i++)
  {
    Tester *test = createTest();
    tests[i](test);
    printf("%s) %s \n", test->failed ? FAILURE : PASS, test->name);
    report.Failed += test->failed;
    report.Total++;
    free(test);
  }
  report.Passed = report.Total - report.Failed;
  return report;
}