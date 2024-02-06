#ifndef CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_
#define CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_

#include <limits>
#include <memory>
#include <stdexcept>

#include "s21_vector_allocator.h"

namespace s21 {

template <class T, class A = s21::allocator<T>>
class vector {
 public:
  class VectorIterator;
  class VectorConstIterator;
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = VectorIterator;
  using const_iterator = VectorConstIterator;
  using allocator = A;

  // Vector Constructors
  vector();
  vector(std::initializer_list<value_type> const &items);
  vector(size_type n, const_reference value = value_type());
  vector(pointer first, pointer last);  // добавил еще не тестил
  vector(const vector &other);
  vector(vector &&other);
  ~vector();

  // Vector Operators
  vector &operator=(const vector &other) noexcept;
  vector &operator=(vector &&other) noexcept;
  reference operator[](size_type index);
  const_reference operator[](size_type index) const;

  // Vector Element Access
  reference at(size_type index);
  const_reference at(size_type index) const;
  const_reference front() const;
  const_reference back() const;
  pointer data() noexcept { return data_; }

  // Vector Capacity
  bool empty() const { return size_ ? false : true; }
  size_type size() const { return size_; }
  size_type capacity() const { return capacity_; };
  void reserve(size_type size);
  void shrink_to_fit();  // TODO make it
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
  }

  // Vector Modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back() noexcept;
  void swap(vector &other);
  template <class... Args>  // TODO make it
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>  // TODO make it
  void insert_many_back(Args &&...args);

  // Vector Iterators
  iterator begin() const { return iterator(data_); }
  iterator end() const { return iterator(data_ + size_); }
  const_iterator cbegin() const { return const_iterator(data_); }
  const_iterator cend() const { return const_iterator(data_ + size_); }

 private:
  size_type size_;
  size_type capacity_;
  allocator alloc_;
  pointer data_;
};

// --------------------------------------------------
// Class VectorIterator
// --------------------------------------------------

template <class T, class A>
class vector<T, A>::VectorIterator {
 public:
  VectorIterator() : ptr_(nullptr){};
  VectorIterator(pointer ptr) : ptr_(ptr){};

  reference operator*() {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    return *ptr_;
  }

  pointer operator->() { return ptr_; }

  iterator operator++() {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    ptr_++;
    return *this;
  }

  iterator operator++(int) {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    iterator tmp(this->ptr_++);
    return tmp;
  }

  iterator operator--() {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    ptr_--;
    return *this;
  }

  iterator operator--(int) {
    if (!ptr_) {
      throw std::invalid_argument("Iterator is nullptr");
    }
    iterator tmp(this->ptr_--);
    return tmp;
  }

  bool operator==(const iterator &other) const { return ptr_ == other.ptr_; };
  bool operator!=(const iterator &other) const { return ptr_ != other.ptr_; };

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

  ptrdiff_t operator-(const iterator &other) const {
    return ptr_ - other.ptr_;
  };

 private:
  pointer ptr_;

};  // class VectorIterator

// --------------------------------------------------
// Class VectorConstIterator
// --------------------------------------------------

template <class T, class A>
class vector<T, A>::VectorConstIterator : public VectorIterator {
 public:
  VectorConstIterator() : ptr_(nullptr){};
  VectorConstIterator(const_pointer ptr) : ptr_(ptr){};

  const_reference operator*() const {
    if (!ptr_) {
      throw std::invalid_argument("ConstIterator is nullptr");
    }
    return *ptr_;
  }

  const_iterator &operator++() {
    if (!ptr_) {
      throw std::invalid_argument("ConstIterator is nullptr");
    }
    ptr_++;
    return *this;
  }

  const_iterator &operator++(int) {
    if (!ptr_) {
      throw std::invalid_argument("ConstIterator is nullptr");
    }
    const_iterator tmp(this->ptr_++);
    return tmp;
  }

  const_iterator operator--() {
    if (!ptr_) {
      throw std::invalid_argument("ConstIterator is nullptr");
    }
    ptr_--;
    return *this;
  }

  const_iterator &operator--(int) {
    if (!ptr_) {
      throw std::invalid_argument("ConstIterator is nullptr");
    }
    const_iterator tmp(this->ptr_--);
    return tmp;
  }

  bool operator==(const const_iterator &other) const {
    return ptr_ == other.ptr_;
  };

  bool operator!=(const const_iterator &other) const {
    return ptr_ != other.ptr_;
  };

  const_iterator operator-(size_type n) const {
    const_iterator iter(*this);
    for (size_type i = 0; i < n; i++) {
      --iter;
    }
    return iter;
  };

  const_iterator operator+(size_type n) const {
    const_iterator iter(*this);
    for (size_type i = 0; i < n; i++) {
      ++iter;
    }
    return iter;
  };

  ptrdiff_t operator-(const const_iterator &other) const {
    return ptr_ - other.ptr_;
  };

 private:
  const_pointer ptr_;

};  // class VectorIterator

// --------------------------------------------------
// Vector Constructors
// --------------------------------------------------

// default constructor
template <class T, class A>
vector<T, A>::vector() : size_(0), capacity_(0), data_(nullptr) {}

// constructor with params
template <class T, class A>
vector<T, A>::vector(size_type n, const_reference value)
    : size_(n), capacity_(n), data_(alloc_.allocate(capacity_)) {
  std::fill_n(data_, n, value);  // списал. надо разобраться
}

// constuctor with list_params
template <class T, class A>
vector<T, A>::vector(std::initializer_list<T> const &items)
    : size_(items.size()),
      capacity_(items.size()),
      data_(alloc_.allocate(items.size())) {
  std::copy(items.begin(), items.end(), data_);
}

// constructor with iterators
template <class T, class A>
vector<T, A>::vector(pointer first, pointer last) {
  size_ = last - first;
  capacity_ = size_;
  data_ = alloc_.allocate(capacity_);
  std::copy(first, last, data_);
}

// constructor copy
template <class T, class A>
vector<T, A>::vector(const vector &other)
    : size_(other.size_),
      capacity_(other.capacity_),
      data_(alloc_.allocate(capacity_)) {
  std::copy(other.data_, other.data_ + size_, data_);
  // std::copy(other.begin(), other.end(), data_);
}

// constructor_move
template <class T, class A>
vector<T, A>::vector(vector &&other)
    : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
  std::move(other.data_, other.data_ + size_, data_);
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

// destructor
template <class T, class A>
vector<T, A>::~vector() {
  alloc_.deallocate(data_, capacity());
  size_ = 0;
  capacity_ = 0;
}

// --------------------------------------------------
// Vector Operators
// --------------------------------------------------

template <class T, class A>
vector<T, A> &vector<T, A>::operator=(const vector &other) noexcept {
  if (this != &other) {
    swap(other);
  }
  return *this;
}

template <class T, class A>
vector<T, A> &vector<T, A>::operator=(vector &&other) noexcept {
  if (this != &other) {
    vector tmp = std::move(other);
    swap(tmp);
  }
  return *this;
}

template <class T, class A>
typename vector<T, A>::reference vector<T, A>::operator[](size_type index) {
  return *(data_ + index);
}

template <class T, class A>
typename vector<T, A>::const_reference vector<T, A>::operator[](
    size_type index) const {
  return *(data_ + index);
}

// --------------------------------------------------
// Vector Element Access
// --------------------------------------------------

template <class T, class A>
typename vector<T, A>::reference vector<T, A>::at(size_type index) {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[index];
}

template <class T, class A>
typename vector<T, A>::const_reference vector<T, A>::at(size_type index) const {
  if (index >= size_ || index < 0) {
    throw std::out_of_range("Index out of range");
  }
  return data_[index];
}

template <class T, class A>
typename vector<T, A>::const_reference vector<T, A>::front() const {
  if (empty()) {
    throw std::out_of_range("Front error: vector is empty");
  }
  return *data_;
};

template <class T, class A>
typename vector<T, A>::const_reference vector<T, A>::back() const {
  if (empty()) {
    throw std::out_of_range("Back error: vector is empty");
  }
  return *(data_ + size_ - 1);
};

// --------------------------------------------------
// Vector Capacity
// --------------------------------------------------

template <class T, class A>
void vector<T, A>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }
  // TODO сделать exception safety
  pointer new_arr = alloc_.allocate(new_capacity);
  size_type i = 0;

  for (; i < size_; ++i) {
    alloc_.construct(&new_arr[i], std::move(data_[i]));
    alloc_.destroy(&data_[i]);
  }
  alloc_.deallocate(data_, capacity());

  data_ = new_arr;
  capacity_ = new_capacity;
}

template <class T, class A>
void vector<T, A>::shrink_to_fit() {
  if (size_ < capacity_) {
    pointer new_data = alloc_.allocate(size_);
    size_type i = 0;

    for (; i < size_; ++i) {
      alloc_.construct(&new_data[i], std::move(data_[i]));
      alloc_.destroy(&data_[i]);
    }
    alloc_.deallocate(data_, capacity());
    data_ = new_data;
    capacity_ = size_;
  }
}

// --------------------------------------------------
// Vector Modifiers
// --------------------------------------------------

template <class T, class A>
void vector<T, A>::clear() noexcept {
  for (size_type i = 0; i < size_; ++i) {
    alloc_.destroy(data_ + i);
  }
  size_ = 0;
}

template <class T, class A>
typename vector<T, A>::iterator vector<T, A>::insert(iterator pos,
                                                     const_reference value) {
  size_type index = pos - begin();
  if (index > size()) {
    throw std::out_of_range("Insert error: iterator out of range");
  }
  if (capacity_ == size_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  for (size_type i = size(); i > index; i--) {
    std::swap(data_[i], data_[i - 1]);
  }
  alloc_.construct(data_ + index, value);
  size_++;
  return pos = begin() + index;
}

template <class T, class A>
void vector<T, A>::erase(iterator pos) {
  size_type index = pos - begin();
  if (index >= size()) {
    throw std::out_of_range("Erase error: iterator out of range");
  }
  for (size_type i = index; i < size() - 1; ++i) {
    std::swap(data_[i], data_[i + 1]);
  }
  --size_;
  alloc_.destroy(data_ + size_);
}

template <class T, class A>
void vector<T, A>::push_back(const_reference value) {
  if (size_ == capacity_) {
    capacity_ ? reserve(capacity_ * 2) : reserve(1);
  }
  alloc_.construct(data_ + size_, value);
  ++size_;
}

template <class T, class A>
void vector<T, A>::pop_back() noexcept {
  --size_;
  alloc_.destroy(data_ + size_);
}

template <class T, class A>
void vector<T, A>::swap(vector &other) {
  if (this != &other) {
    std::swap(data_, other.data_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
  }
}

template <class T, class A>
template <typename... Args>
typename vector<T, A>::iterator vector<T, A>::insert_many(const_iterator pos,
                                                          Args &&...args) {
  size_type index = pos - cbegin();
  iterator cur_pos = begin() + index;
  for (auto &arg : {args...}) {
    cur_pos = insert(cur_pos, arg);
    ++cur_pos;
  }
  return begin() + index;
}

template <class T, class A>
template <typename... Args>
void vector<T, A>::insert_many_back(Args &&...args) {
  for (auto &arg : {args...}) {
    push_back(arg);
  }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_
