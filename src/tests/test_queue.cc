#include <gtest/gtest.h>

#include "../s21_container_adaptors/s21_queue.h"

// constructors

TEST(queue_constructor_test, queue_default_constructor) {
  s21::queue<int> *example_queue = nullptr;
  example_queue = new s21::queue<int>;
  EXPECT_NE(example_queue, nullptr);
  delete example_queue;
}

TEST(queue_constructor_test, queue_constructor_with_param) {
  s21::queue<int> example_queue({1, 2});
}

TEST(queue_constructor_test, queue_constructor_copy) {
  s21::queue<int> first_queue({1, 2});
  s21::queue<int> second_queue(first_queue);
  EXPECT_EQ(second_queue.back(), 2);
  EXPECT_TRUE(&first_queue != &second_queue);
}

TEST(queue_constructor_test, queue_constructor_move) {
  s21::queue<int> first_queue({1, 2, 3});
  s21::queue<int> second_queue(std::move(first_queue));
  EXPECT_EQ(second_queue.size(), 3);
  EXPECT_NE(first_queue.size(), 3);
}

// operators

TEST(queue_operator_test, queue_operator_assignment) {
  s21::queue<int> first_queue;
  s21::queue<int> second_queue({4, 5, 6});
  first_queue = second_queue;
  EXPECT_EQ(first_queue.back(), 6);
  EXPECT_EQ(first_queue.size(), 3);
}

TEST(queue_operator_test, queue_operator_comparison) {
  s21::queue<int> first_queue({1, 2, 3});
  s21::queue<int> second_queue(first_queue);
  EXPECT_TRUE(first_queue == second_queue);
}

// metods

TEST(queue_metods_test, queue_front) {
  s21::queue<int> example_queue({-1, -2, -3});
  EXPECT_EQ(example_queue.front(), -1);
}

TEST(queue_metods_test, queue_back) {
  s21::queue<int> example_queue({-1, -2, -3});
  EXPECT_EQ(example_queue.back(), -3);
}

TEST(queue_metods_test, queue_back_reference) {
  s21::queue<int> example_queue({10});
  const int *p_back = &example_queue.back();
  EXPECT_EQ(*p_back, 10);
}

TEST(queue_metods_test, queue_empty) {
  s21::queue<int> empty_queue;
  EXPECT_TRUE(empty_queue.empty());
  s21::queue<int> not_empty_queue({1});
  ASSERT_FALSE(not_empty_queue.empty());
}

TEST(queue_metods_test, queue_size) {
  s21::queue<int> first_queue({1});
  s21::queue<int> second_queue({1, 2});
  s21::queue<int> third_queue({1, 2, 3});
  EXPECT_EQ(first_queue.size(), 1);
  EXPECT_EQ(second_queue.size(), 2);
  EXPECT_EQ(third_queue.size(), 3);
}

TEST(queue_metods_test, queue_push) {
  s21::queue<int> example_queue;
  example_queue.push(123);
  EXPECT_EQ(example_queue.back(), 123);
  example_queue.push(-333);
  EXPECT_EQ(example_queue.back(), -333);
  example_queue.push(0);
  EXPECT_EQ(example_queue.back(), 0);
  EXPECT_EQ(example_queue.size(), 3);
}

TEST(queue_metods_test, queue_pop) {
  s21::queue<double> example_queue({1.1, 2.2, 3.3});
  example_queue.pop();
  EXPECT_EQ(example_queue.size(), 2);
  example_queue.pop();
  example_queue.pop();
  EXPECT_TRUE(example_queue.empty());
}

TEST(queue_metods_test, queue_swap) {
  s21::queue<int> first_queue({1, 2, 3});
  s21::queue<int> second_queue({4});
  first_queue.swap(second_queue);
  EXPECT_EQ(first_queue.size(), 1);
  EXPECT_EQ(second_queue.size(), 3);
}
