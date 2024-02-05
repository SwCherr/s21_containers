#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_LIST_H
#define CPP2_S21_CONTAINERS_1_SRC_S21_LIST_H

#include <initializer_list>
#include <limits>
#include <memory>

namespace s21 {

template <class T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  // List Constructors
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &other);
  list(list &&other) noexcept;
  ~list();

  // List Operators
  list &operator=(const list &other);
  list &operator=(list &&other) noexcept;

  // List Element access
  const_reference front() const noexcept;
  const_reference back() const noexcept;

  // List Capacity
  bool empty() const;
  size_type size() const noexcept;
  size_type max_size() const;

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other) noexcept;
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();
  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);
  template <class... Args>
  void insert_many_front(Args &&...args);

  // List Iterators
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

 private:
  class Node;
  size_type size_;
  Node *head_;
  Node *end_;
  void mergeSort();
  void quickMerge(list &other);
};  // class list

// --------------------------------------------------
// Class Node
// --------------------------------------------------

template <class value_type>
class list<value_type>::Node {
 public:
  Node(value_type data = value_type())
      : data_(data), ptrNext_(nullptr), ptrPrevious_(nullptr) {}

  value_type data_;
  Node *ptrNext_;
  Node *ptrPrevious_;
};  // class Node

// --------------------------------------------------
// Class ListIterator
// --------------------------------------------------

template <class value_type>
class list<value_type>::ListIterator {
 public:
  ListIterator() : ptr_(nullptr){};
  ListIterator(Node *ptr) : ptr_(ptr){};

  reference operator*() const {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    return ptr_->data_;
  };

  iterator operator++() {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    if (ptr_->ptrNext_) {
      ptr_ = ptr_->ptrNext_;
    }
    return *this;
  };

  iterator operator--() {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    if (ptr_->ptrPrevious_) {
      ptr_ = ptr_->ptrPrevious_;
    }
    return *this;
  };

  bool operator==(const iterator &other) const noexcept {
    return ptr_ == other.ptr_;
  };

  bool operator!=(const iterator &other) const noexcept {
    return ptr_ != other.ptr_;
  };

  iterator operator-(size_type n) const {
    iterator iter(*this);
    for (size_type i = 0; i < n; i++) {
      --iter;
    }
    return iter;
  };

  iterator operator+(size_type n) const {
    iterator iter(*this);
    for (size_type i = 0; i < n; i++) {
      ++iter;
    }
    return iter;
  };

  Node *getPtr() const noexcept { return ptr_; };

 private:
  Node *ptr_;
};  // class ListIterator

// --------------------------------------------------
// Class ListConstIterator
// --------------------------------------------------

template <class value_type>
class list<value_type>::ListConstIterator : public ListIterator {
 public:
  ListConstIterator() : ptr_(nullptr){};
  ListConstIterator(ListIterator other) : ListIterator(other){};

  const_reference operator*() { return ListIterator::operator*(); };

 private:
  Node *ptr_;
};  // class ListConstIterator

// --------------------------------------------------
// List Constructors
// --------------------------------------------------

template <class value_type>
list<value_type>::list() : size_(0), head_(nullptr), end_(nullptr){};

template <class value_type>
list<value_type>::list(size_type n) : list() {
  for (; n > 0; n--) {
    push_back(value_type{});
  }
}

template <class value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (auto &i : items) {
    push_back(i);
  }
}

template <class value_type>
list<value_type>::list(const list &other) : list() {
  for (const_iterator it = other.cbegin(); it != other.cend(); ++it) {
    push_back(*it);
  };
}

template <class value_type>
list<value_type>::list(list &&other) noexcept : list() {
  swap(other);
}

template <class value_type>
list<value_type>::~list() {
  clear();
}

// --------------------------------------------------
// List Operators
// --------------------------------------------------

template <class value_type>
list<value_type> &list<value_type>::operator=(const list &other) {
  if (this != &other) {
    new (this) list(other);
  }
  return *this;
}

template <class value_type>
list<value_type> &list<value_type>::operator=(list &&other) noexcept {
  if (this != &other) {
    new (this) list(std::move(other));
  }
  return *this;
}

// --------------------------------------------------
// List Element access
// --------------------------------------------------

template <class value_type>
typename list<value_type>::const_reference list<value_type>::front()
    const noexcept {
  static const_reference default_value{};
  return empty() ? default_value : *cbegin();
};

template <class value_type>
typename list<value_type>::const_reference list<value_type>::back()
    const noexcept {
  static const_reference default_value{};
  return empty() ? default_value : *(--cend());
};

// --------------------------------------------------
// List Iterators
// --------------------------------------------------

template <class value_type>
typename list<value_type>::iterator list<value_type>::begin() noexcept {
  return iterator(head_);
};

template <class value_type>
typename list<value_type>::iterator list<value_type>::end() noexcept {
  return iterator(end_);
};

template <class value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin()
    const noexcept {
  return const_iterator(head_);
};

template <class value_type>
typename list<value_type>::const_iterator list<value_type>::cend()
    const noexcept {
  return const_iterator(end_);
};

// --------------------------------------------------
// List Capacity
// --------------------------------------------------

template <class value_type>
bool list<value_type>::empty() const {
  return head_ ? false : true;
};

template <class value_type>
typename list<value_type>::size_type list<value_type>::size() const noexcept {
  return size_;
};

template <class value_type>
typename list<value_type>::size_type list<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
};

// --------------------------------------------------
// List Modifiers
// --------------------------------------------------

template <class value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_front();
  }
  delete end_;
  end_ = nullptr;
  head_ = nullptr;
}

template <class value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node *current = pos.getPtr();
  if (empty()) {
    head_ = new Node(value);
    end_ = new Node(const_reference{});
    end_->ptrPrevious_ = end_->ptrNext_ = head_;
    head_->ptrNext_ = head_->ptrPrevious_ = end_;
    pos = iterator(head_);
  } else if (!current) {
    throw std::invalid_argument("Iterator is nullptr");
  } else {
    Node *insert = new Node(value);
    if (current == head_) {
      head_ = insert;
    }
    insert->ptrNext_ = current;
    insert->ptrPrevious_ = current->ptrPrevious_;
    current->ptrPrevious_->ptrNext_ = insert;
    current->ptrPrevious_ = insert;
    pos = iterator(insert);
  }
  size_++;
  return pos;
}

template <class value_type>
void list<value_type>::erase(iterator pos) {
  Node *remove = pos.getPtr();
  if (empty()) {
    throw std::invalid_argument("List is empty");
  }
  if (!remove || remove == end_) {
    throw std::invalid_argument("Pointer is nullptr");
  }
  if (size() == 1.0) {
    delete head_;
    delete end_;
    head_ = nullptr;
    end_ = nullptr;
    size_ = 0;
  } else {
    if (remove == head_) {
      head_ = head_->ptrNext_;
    }
    Node *prev = remove->ptrPrevious_;
    Node *next = remove->ptrNext_;
    prev->ptrNext_ = next;
    next->ptrPrevious_ = prev;
    delete remove;
    size_--;
  }
}

template <class value_type>
void list<value_type>::push_back(const_reference value) {
  insert(end(), value);
}

template <class value_type>
void list<value_type>::pop_back() {
  erase(--end());
}

template <class value_type>
void list<value_type>::push_front(const_reference value) {
  insert(begin(), value);
}

template <class value_type>
void list<value_type>::pop_front() {
  erase(begin());
}

template <class value_type>
void list<value_type>::swap(list &other) noexcept {
  if (this != &other) {
    std::swap(head_, other.head_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }
}

template <class value_type>
void list<value_type>::merge(list &other) {
  if (this != &other) {
    if (empty()) {
      swap(other);
    } else {
      quickMerge(other);
    }
  }
}

template <class value_type>
void list<value_type>::quickMerge(list &other) {
  iterator iter_left = begin();
  iterator iter_right = other.begin();
  while (iter_left != end() && iter_right != other.end()) {
    if (*iter_right < *iter_left) {
      insert(iter_left, *iter_right);
      other.pop_front();
    } else if (iter_left + 1 == end()) {
      splice(end(), other);
    } else {
      ++iter_left;
    }
    iter_right = other.begin();
  }
}

template <class value_type>
void list<value_type>::splice(const_iterator pos, list &other) {
  if (!other.empty()) {
    iterator iter = other.begin();
    if (empty()) {
      push_back(*iter);
      pos = end();
      ++iter;
    }
    for (; iter != other.end(); ++iter) {
      insert(pos, *iter);
    }
    other.clear();
  }
}

template <class value_type>
void list<value_type>::reverse() {
  if (!empty()) {
    iterator iter_left = begin();
    iterator iter_right = --end();
    for (size_type i = 0; i < size() / 2; i++, ++iter_left, --iter_right) {
      std::swap(*iter_left, *iter_right);
    }
  }
}

template <class value_type>
void list<value_type>::unique() {
  if (size() > 1.0) {
    for (auto iter = ++begin(); iter != ++end(); ++iter) {
      if (*iter == *(iter - 1)) {
        erase(iter - 1);
      }
    }
  }
}

template <class value_type>
void list<value_type>::sort() {
  if (!empty() && size() > 1.0) {
    mergeSort();
  }
}

template <class value_type>
void list<value_type>::mergeSort() {
  if (size() <= 1.0) {
    return;
  }
  list<value_type> left{}, right{};
  iterator iter = begin();
  size_type middle = size() / 2.0;
  for (size_type i = 0; iter != end(); i++) {
    if (i >= middle) {
      right.push_back(*iter);
    } else {
      left.push_back(*iter);
    }
    ++iter;
  }
  left.mergeSort();
  right.mergeSort();
  left.merge(right);
  swap(left);
}

// --------------------------------------------------
// "Insert many" methods
// --------------------------------------------------

template <class value_type>
template <class... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  const_iterator res;
  list tmp{args...};
  int i = 0;
  iterator iter = tmp.begin();
  if (empty()) {
    push_back(*iter);
    res = begin();
    pos = end();
    ++iter;
    ++i;
  }
  for (; iter != tmp.end(); ++iter) {
    if (!(i++)) {
      res = insert(pos, *iter);
    } else {
      insert(pos, *iter);
    }
  }
  return res;
}

template <class value_type>
template <class... Args>
void list<value_type>::insert_many_back(Args &&...args) {
  for (auto &arg : {args...}) {
    push_back(arg);
  }
}

template <class value_type>
template <class... Args>
void list<value_type>::insert_many_front(Args &&...args) {
  for (auto &arg : {args...}) {
    push_front(arg);
  }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_LIST_H