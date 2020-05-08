#include "test.h"

int add(int a, int b){
  return a + b;
};

void add_two_numbers(Tester *t){
  t->name = "should_add_two_numbers";
  t->int_eq(t, 5, add(2, 3));
}

void check_equality(Tester *t){
  t->name = "should_check_equality";
  t->int_eq(t, 2, 2);
  t->int_eq(t, 2, 3);
}

void add_two_negative_numbers(Tester *t){
  t->name = "should_add_two_negative_numbers";
  t->int_eq(t, add(-3, -7) ,- 10);
}

int main()
{
  Function tests[] = {
      add_two_numbers,
      check_equality, 
      add_two_negative_numbers};
  Report report = runTest(tests, 3);
  printf("========================\n");
  printf("| Total: %d Failed: %d |\n", report.Total, report.Failed);
  return 0;
}