#ifndef CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTORS_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTORS_S21_QUEUE_H_

#include <algorithm>
#include <cstddef>
#include <initializer_list>

#include "../s21_sequental_containers/s21_list.h"
#include "s21_container_adaptor.h"

namespace s21 {

template <class T, class C = list<T>>
class queue : public container_adaptor<T, C> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using container_adaptor<T, C>::container_;

  queue() = default;
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &other);
  queue(queue &&other) noexcept;
  ~queue() = default;

  void pop() override;
  void push(const_reference value) override;
  const_reference back();
  const_reference front();

  queue operator=(const queue &other);
  bool operator==(const queue &other) const;
};

template <class T, class C>
queue<T, C>::queue(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); i++) {
    push(*i);
  }
}

template <class T, class C>
queue<T, C>::queue(const queue &other) {
  container_ = other.container_;
}

template <class T, class C>
queue<T, C>::queue(queue &&other) noexcept {
  container_ = std::move(other.container_);
}

template <class T, class C>
void queue<T, C>::pop() {
  container_.pop_front();
}

template <class T, class C>
void queue<T, C>::push(const_reference value) {
  container_.push_back(value);
}

template <class T, class C>
typename queue<T, C>::const_reference queue<T, C>::back() {
  return container_.back();
}

template <class T, class C>
typename queue<T, C>::const_reference queue<T, C>::front() {
  return container_.front();
}

template <class T, class C>
queue<T, C> queue<T, C>::operator=(const queue &other) {
  container_ = other.container_;
  return *this;
}

template <class T, class C>
bool queue<T, C>::operator==(const queue &other) const {
  return container_ == other.container_;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTORS_S21_QUEUE_H_
