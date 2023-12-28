#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <stack>

#include "../s21_stack.h"

TEST(stack_constructor_test, stack_default_constructor) {
  s21::stack<int> *example_stack = nullptr;
  example_stack = new s21::stack<int>;
  ASSERT_NE(example_stack, nullptr);
}

TEST(stack_constructor_test, stack_constructor_with_param) {
  s21::stack<int> example_stack = {1, 2};
}

/* TEST(stack_constructor_test, stack_constructor_copy) {
  s21::stack<int> first_stack;
  first_stack.push(1);
  first_stack.push(2);
  s21::stack<int> second_stack(first_stack);
  // s21::stack<int> second_stack = first_stack;
  EXPECT_EQ(second_stack.top(), 2);
} */
