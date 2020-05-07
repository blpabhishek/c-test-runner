#include "test.h"

int add(int a, int b){
  return a + b;
};

void test_should_add_two_numbers(Tester *t){
  t->name = "test_should_add_two_numbers";
  t->int_eq(t, 5, add(2, 3));
}

void test_should_check_equality(Tester *t){
  t->name = "test_should_check_equality";
  t->int_eq(t, 2, 2);
  t->int_eq(t, 2, 3);
}

int main()
{
  Function tests[] = {
      test_should_add_two_numbers,
      test_should_check_equality};
  Report report = runTest(tests, 2);
  printf("Total %d Failed %d \n", report.Total, report.Failed);
  return 0;
}