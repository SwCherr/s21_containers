#include <gtest/gtest.h>

#include "../s21_stack.h"

TEST(stack_constructor_test, stack_default_constructor) {
  s21::stack<int> *example = new s21::stack<int>;
  ASSERT_NE(example, nullptr);
}
