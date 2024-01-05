#ifndef S21_CONTAINERS_1_SRC_S21_QUEUE_H_
#define S21_CONTAINERS_1_SRC_S21_QUEUE_H_

#include <deque>

#include "s21_container_adaptor.h"

namespace s21 {
template <class T, class C = std::deque<T>>
class queue : public container_adaptor<T, C> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  queue() = default;
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &other);
  queue(queue &&other) noexcept;
  ~queue() = default;
};
}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_QUEUE_H_
