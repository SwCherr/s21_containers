#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

// #include "binary_tree.h"

namespace s21 {
// class SetContainer {}; // общий класс для множеств
// class Multiset: public SetContainer {}; // допка - заглушка

template<typename Key>
class set {
  public:
  // внутриклассовые переопределения типов
  using key_type = Key;                              // первый параметр шаблона
  using value_type = Key;                            // Тип значения ключа (само значение является ключом)
  using reference = value_type &;                    // тип ссылки на элемент
  using const_reference = const value_type &;        // тип ссылки на константу
  // using iterator = BinaryTree::iterator;             // тип для итерации по контейнеру
  // using const_iterator = BinaryTree::const_iterator; // тип константы для итерации по контейнеру
  // using size_type = size_t;                           // определяет тип размера контейнера (стандартный тип - size_t);
  
  // основные публичные методы для взаимодействия с классом
  // 5 конструкторов и 1 деструктор
  // set();
  // set(std::initializer_list<value_type> const &items);
  // set(const set &s);                                    // copy constructor
  // set(set &&s);                                         // move constructor
  // ~set();                                               // destructor
  // operator=(set &&s);                                   // assignment operator overload for moving object


  // публичные методы для итерирования по элементам класса
  // публичные методы для доступа к информации о наполнении контейнера
  // публичные методы для изменения контейнера
  // публичные методы для просмотра контейнера

  void DataTypeSize();

  private:
  Key value;
};
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
