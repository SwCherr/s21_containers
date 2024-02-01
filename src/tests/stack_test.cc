#include <gtest/gtest.h>

#include "../s21_container_adaptor/s21_stack.h"

// constructors

TEST(stack_constructor_test, stack_default_constructor) {
  s21::stack<int> *example_stack = nullptr;
  example_stack = new s21::stack<int>;
  EXPECT_NE(example_stack, nullptr);
  delete example_stack;
}

TEST(stack_constructor_test, stack_constructor_with_param) {
  s21::stack<int> example_stack({1, 2});
}

TEST(experemental, stack) {
  s21::stack<int, std::vector<int>> stack_vector;
  stack_vector.push(10);
}

TEST(stack_constructor_test, stack_constructor_copy) {
  s21::stack<int> first_stack({1, 2});
  s21::stack<int> second_stack(first_stack);
  EXPECT_EQ(second_stack.top(), 2);
  EXPECT_TRUE(&first_stack != &second_stack);
}

TEST(stack_constructor_test, stack_constructor_move) {
  s21::stack<int> first_stack({1, 2, 3});
  s21::stack<int> second_stack(std::move(first_stack));
  EXPECT_EQ(second_stack.size(), 3);
  EXPECT_NE(first_stack.size(), 3);
}

// operators

TEST(stack_operator_test, stack_operator_assignment) {
  s21::stack<int> first_stack;
  s21::stack<int> second_stack({4, 5, 6});
  first_stack = second_stack;
  EXPECT_EQ(first_stack.top(), 6);
  EXPECT_EQ(first_stack.size(), 3);
}

TEST(stack_operator_test, stack_operator_comparison) {
  s21::stack<int> first_stack({1, 2, 3});
  s21::stack<int> second_stack(first_stack);
  EXPECT_TRUE(first_stack == second_stack);
}

// metods

TEST(stack_metods_test, stack_top) {
  s21::stack<int> example_stack({-1, -2, -3});
  EXPECT_EQ(example_stack.top(), -3);
}

TEST(stack_metods_test, stack_top_reference) {
  s21::stack<int> example_stack({10});
  const int *p_top = &example_stack.top();
  EXPECT_EQ(*p_top, 10);
}

TEST(stack_metods_test, stack_empty) {
  s21::stack<int> empty_stack;
  EXPECT_TRUE(empty_stack.empty());
  s21::stack<int> not_empty_stack({1});
  ASSERT_FALSE(not_empty_stack.empty());
}

TEST(stack_metods_test, stack_size) {
  s21::stack<int> first_stack({1});
  s21::stack<int> second_stack({1, 2});
  s21::stack<int> third_stack({1, 2, 3});
  EXPECT_EQ(first_stack.size(), 1);
  EXPECT_EQ(second_stack.size(), 2);
  EXPECT_EQ(third_stack.size(), 3);
}

TEST(stack_metods_test, stack_push) {
  s21::stack<int> example_stack;
  example_stack.push(123);
  EXPECT_EQ(example_stack.top(), 123);
  example_stack.push(-333);
  EXPECT_EQ(example_stack.top(), -333);
  example_stack.push(0);
  EXPECT_EQ(example_stack.top(), 0);
  EXPECT_EQ(example_stack.size(), 3);
}

TEST(stack_metods_test, stack_pop) {
  s21::stack<double> example_stack({1.1, 2.2, 3.3});
  example_stack.pop();
  EXPECT_EQ(example_stack.size(), 2);
  example_stack.pop();
  example_stack.pop();
  EXPECT_TRUE(example_stack.empty());
}

TEST(stack_metods_test, stack_swap) {
  s21::stack<int> first_stack({1, 2, 3});
  s21::stack<int> second_stack({4});
  first_stack.swap(second_stack);
  EXPECT_EQ(first_stack.size(), 1);
  EXPECT_EQ(second_stack.size(), 3);
}
