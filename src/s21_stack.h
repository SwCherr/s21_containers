#ifndef S21_CONTAINERS_1_SRC_S21_STACK_H_
#define S21_CONTAINERS_1_SRC_S21_STACK_H_

#include <deque>

namespace s21 {

template <class T, class C = std::deque<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  stack();
  stack(std::initializer_list<value_type> const &items);
  // stack(const stack &s);
  // stack(stack &&s);
  ~stack();
  // operator=(stack &&s);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  // void pop();
  // void swap(stack &other);

 private:
  C container_;
};

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_STACK_H_
