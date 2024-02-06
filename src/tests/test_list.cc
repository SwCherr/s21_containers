#include <gtest/gtest.h>

#include <list>

#include "../s21_sequental_containers/s21_list.h"

template <class T>
bool ListEqual(s21::list<T> s21_List, std::list<T> List) {
  bool result = true;
  if (s21_List.size() != List.size()) {
    result = false;
  } else {
    auto iter = List.begin();
    auto s21_iter = s21_List.begin();
    for (; iter != List.end(); ++iter, ++s21_iter) {
      if (*iter != *s21_iter) {
        result = false;
        break;
      }
    }
  }
  return result;
}

TEST(list, default_constructor) {
  s21::list<char> s21_List;
  std::list<char> List;
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, size_n_constructor) {
  s21::list<int> s21_List(22);
  std::list<int> List(22);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, init_list_constructor_0) {
  s21::list<unsigned int> s21_List = {12, 13, 14};
  std::list<unsigned int> List = {12, 13, 14};
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, init_list_constructor_1) {
  s21::list<unsigned int> s21_List = {};
  std::list<unsigned int> List = {};
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, init_list_constructor_2) {
  s21::list<unsigned int> s21_List = {1};
  std::list<unsigned int> List = {1};
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, copy_constructor_0) {
  s21::list<int> s21_List_1 = {4, 5, 6, 9};
  s21::list<int> s21_List_2(s21_List_1);
  std::list<int> List_1 = {4, 5, 6, 9};
  std::list<int> List_2(List_1);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, copy_constructor_1) {
  s21::list<int> s21_List_1;
  s21::list<int> s21_List_2(s21_List_1);
  std::list<int> List_1;
  std::list<int> List_2(List_1);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, copy_constructor_2) {
  s21::list<int> s21_List_1 = {4, 5, 6, 9};
  s21::list<int> s21_List_2(s21_List_1);
  std::list<int> List_1 = {4, 5, 6, 9};
  std::list<int> List_2(List_1);
  s21_List_1.insert(++s21_List_1.begin(), 3);
  List_1.insert(++List_1.begin(), 3);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, move_constructor_1) {
  s21::list<double> s21_List_1 = {1.1, 2.2, 3.3};
  s21::list<double> s21_List_2(std::move(s21_List_1));
  std::list<double> List_1 = {1.1, 2.2, 3.3};
  std::list<double> List_2(std::move(List_1));
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, copy_operator_0) {
  s21::list<unsigned int> s21_List_1 = {1, 2, 3};
  s21::list<unsigned int> s21_List_2 = s21_List_1;
  std::list<unsigned int> List_1 = {1, 2, 3};
  std::list<unsigned int> List_2 = List_1;
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, copy_operator_1) {
  s21::list<unsigned int> s21_List_1 = {};
  s21::list<unsigned int> s21_List_2 = s21_List_1;
  std::list<unsigned int> List_1 = {};
  std::list<unsigned int> List_2 = List_1;
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, move_operator_0) {
  s21::list<unsigned int> s21_List_1 = {1, 2, 3};
  s21::list<unsigned int> s21_List_2 = std::move(s21_List_1);
  std::list<unsigned int> List_1 = {1, 2, 3};
  std::list<unsigned int> List_2 = std::move(List_1);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, move_operator_1) {
  s21::list<unsigned int> s21_List_1 = {};
  s21::list<unsigned int> s21_List_2 = std::move(s21_List_1);
  std::list<unsigned int> List_1 = {};
  std::list<unsigned int> List_2 = std::move(List_1);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, front_back) {
  s21::list<char> s21_List{'s', 'c', 'h', 'o', 'o', 'l'};
  std::list<char> List{'s', 'c', 'h', 'o', 'o', 'l'};
  ASSERT_EQ(s21_List.front(), List.front());
  ASSERT_EQ(s21_List.back(), List.back());
}

TEST(list, empty) {
  s21::list<char> s21_List{'s', 'c', 'h', 'o', 'o', 'l'};
  std::list<char> List{'s', 'c', 'h', 'o', 'o', 'l'};
  ASSERT_EQ(s21_List.empty(), List.empty());
  s21_List.clear();
  List.clear();
  ASSERT_EQ(s21_List.empty(), List.empty());
}

TEST(list, max_size_0) {
  s21::list<int> s21_List{12, 13, 14};
  std::list<int> List{12, 13, 14};
  ASSERT_EQ(s21_List.max_size(), List.max_size());
}

TEST(list, clear_0) {
  s21::list<char> s21_List{'s', 'c', 'h', 'o', 'o', 'l'};
  std::list<char> List{'s', 'c', 'h', 'o', 'o', 'l'};
  s21_List.clear();
  List.clear();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, clear_1) {
  s21::list<char> s21_List;
  std::list<char> List;
  s21_List.clear();
  List.clear();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_back_0) {
  s21::list<char> s21_List;
  std::list<char> List;
  s21_List.push_back('s');
  List.push_back('s');
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_back_1) {
  s21::list<char> s21_List;
  std::list<char> List;
  s21_List.push_back('s');
  s21_List.push_back('c');
  s21_List.push_back('h');
  List.push_back('s');
  List.push_back('c');
  List.push_back('h');
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_back_2) {
  s21::list<char> s21_List{'s', 'c', 'h', 'o', 'o'};
  std::list<char> List{'s', 'c', 'h', 'o', 'o'};
  s21_List.push_back('l');
  List.push_back('l');
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_front_0) {
  s21::list<double> s21_List;
  std::list<double> List;
  s21_List.push_front(12.4);
  List.push_front(12.4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_front_1) {
  s21::list<int> s21_List;
  std::list<int> List;
  s21_List.push_front(12);
  s21_List.push_front(13);
  s21_List.push_front(14);
  List.push_front(12);
  List.push_front(13);
  List.push_front(14);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, push_front_2) {
  s21::list<char> s21_List{'c', 'h', 'o', 'o', 'l'};
  std::list<char> List{'c', 'h', 'o', 'o', 'l'};
  s21_List.push_back('s');
  List.push_back('s');
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, pop_0) {
  s21::list<int> MyList;
  EXPECT_THROW(MyList.pop_back(), std::invalid_argument);
  EXPECT_THROW(MyList.pop_front(), std::invalid_argument);
}

TEST(list, pop_back_1) {
  s21::list<int> s21_List = {65};
  std::list<int> List = {65};
  s21_List.pop_back();
  List.pop_back();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, pop_back_2) {
  s21::list<int> s21_List{12, 13, 14};
  std::list<int> List{12, 13, 14};
  s21_List.pop_back();
  List.pop_back();
  s21_List.pop_back();
  List.pop_back();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, pop_front_0) {
  s21::list<int> s21_List;
  std::list<int> List;
  s21_List.push_back(65);
  s21_List.push_back(66);
  s21_List.pop_front();
  List.push_back(65);
  List.push_back(66);
  List.pop_front();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, pop_front_1) {
  s21::list<int> s21_List;
  std::list<int> List;
  s21_List.push_back(65);
  s21_List.pop_front();
  List.push_back(65);
  List.pop_front();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, iterator_0) {
  s21::list<int> s21_List{56, 120, 4, 8, 34, 6, 8};
  std::list<int> List{56, 120, 4, 8, 34, 6, 8};
  auto s21_iter = s21_List.begin();
  auto iter = List.begin();
  ASSERT_EQ(*iter, *s21_iter);
  ASSERT_EQ(*(++iter), *(++s21_iter));
  ASSERT_EQ(*(--iter), *(--s21_iter));
  ASSERT_EQ(6, *(s21_iter + 5));
  s21_iter = s21_List.end();
  ASSERT_EQ(4, *(s21_iter - 5));
}

TEST(list, iterator_1) {
  s21::list<int> MyList;
  EXPECT_THROW(*MyList.begin(), std::invalid_argument);
  EXPECT_THROW(*MyList.end(), std::invalid_argument);
}

TEST(list, iterator_2) {
  s21::list<int>::iterator iter;
  EXPECT_THROW(*iter, std::invalid_argument);
  EXPECT_THROW(++iter, std::invalid_argument);
  EXPECT_THROW(--iter, std::invalid_argument);
  EXPECT_THROW(iter - 5, std::invalid_argument);
  EXPECT_THROW(iter + 5, std::invalid_argument);
}

TEST(list, iterator_3) {
  s21::list<int> MyList = {56, 120};
  auto iter = MyList.begin();
  ASSERT_EQ(*(++iter), 120);
}

TEST(list, iterator_4) {
  std::list<int> List{56, 120};
  s21::list<int> s21_List{56, 120};
  auto s21_iter = s21_List.end();
  auto iter = List.end();
  ASSERT_EQ(*(--iter), *(--s21_iter));
}

TEST(list, iterator_bool) {
  std::list<int> List{1, 1, 1, 1};
  s21::list<int> s21_List{1, 1, 1, 1};
  auto s21_iter_1 = s21_List.begin();
  auto s21_iter_2 = s21_List.begin();
  auto iter_1 = List.begin();
  auto iter_2 = List.begin();
  EXPECT_TRUE(s21_iter_1 == s21_iter_2);
  EXPECT_TRUE(iter_1 == iter_2);
  EXPECT_TRUE(s21_iter_1 != ++s21_iter_2);
  EXPECT_TRUE(iter_1 != ++iter_2);
}

TEST(list, const_iterator_0) {
  s21::list<int> s21_List{56, 120, 4, 8, 34, 6, 8};
  std::list<int> List{56, 120, 4, 8, 34, 6, 8};
  auto s21_iter = s21_List.cbegin();
  auto iter = List.cbegin();
  ASSERT_EQ(*iter, *s21_iter);
  ASSERT_EQ(*(++iter), *(++s21_iter));
  ASSERT_EQ(*(--iter), *(--s21_iter));
  ASSERT_EQ(6, *(s21_iter + 5));
  s21_iter = s21_List.cend();
  ASSERT_EQ(4, *(s21_iter - 5));
}

TEST(list, const_iterator_1) {
  s21::list<int> MyList;
  auto iter = MyList.cbegin();
  EXPECT_THROW(*iter, std::invalid_argument);
}

TEST(list, const_iterator_2) {
  s21::list<int>::const_iterator iter_2;
  EXPECT_THROW(*iter_2, std::invalid_argument);
  EXPECT_THROW(++iter_2, std::invalid_argument);
  EXPECT_THROW(--iter_2, std::invalid_argument);
}

TEST(list, const_iterator_3) {
  std::list<int> List{56, 120};
  s21::list<int> s21_List{56, 120};
  auto s21_iter = s21_List.cend();
  auto iter = List.cend();
  ASSERT_EQ(*(--iter), *(--s21_iter));
}

TEST(list, const_iterator_bool) {
  std::list<int> List = {1, 1, 1, 1};
  s21::list<int> s21_List = {1, 1, 1, 1};
  auto s21_iter_1 = s21_List.cbegin();
  auto s21_iter_2 = s21_List.cbegin();
  auto iter_1 = List.cbegin();
  auto iter_2 = List.cbegin();
  EXPECT_TRUE(s21_iter_1 == s21_iter_2);
  EXPECT_TRUE(iter_1 == iter_2);
  EXPECT_TRUE(s21_iter_1 != ++s21_iter_2);
  EXPECT_TRUE(iter_1 != ++iter_2);
}

TEST(list, front_back_0) {
  std::list<int> List = {23, 9, 43};
  s21::list<int> MyList{23, 9, 43};
  ASSERT_EQ(List.front(), MyList.front());
  ASSERT_EQ(List.back(), MyList.back());
}

TEST(list, insert_0) {
  std::list<unsigned int> List{6, 5, 4, 2, 1};
  auto iter = List.begin();
  s21::list<unsigned int> s21_List{6, 5, 4, 2, 1};
  auto s21_iter = s21_List.begin();
  for (int i = 0; i < 3; i++, ++iter, ++s21_iter) {
  }
  auto res = List.insert(iter, 3);
  auto s21_res = s21_List.insert(s21_iter, 3);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_1) {
  std::list<unsigned int> List;
  s21::list<unsigned int> s21_List;
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  auto res = List.insert(iter, 42);
  auto s21_res = s21_List.insert(myiter, 42);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_2) {
  std::list<unsigned int> List = {2, 3};
  s21::list<unsigned int> s21_List{2, 3};
  auto iter = List.end();
  auto myiter = s21_List.end();
  auto res = List.insert(iter, 4);
  auto s21_res = s21_List.insert(myiter, 4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_3) {
  std::list<unsigned int> List = {2, 3};
  s21::list<unsigned int> s21_List = {2, 3};
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  auto res = List.insert(iter, 4);
  auto s21_res = s21_List.insert(myiter, 4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_4) {
  std::list<unsigned int> List;
  s21::list<unsigned int> s21_List;
  auto iter = List.end();
  auto myiter = s21_List.end();
  auto res = List.insert(iter, 4);
  auto s21_res = s21_List.insert(myiter, 4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_5) {
  std::list<unsigned int> List = {2, 3};
  s21::list<unsigned int> s21_List = {2, 3};
  auto res = List.insert(--List.begin(), 4);
  auto s21_res = s21_List.insert(--s21_List.begin(), 4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*s21_res, *res);
}

TEST(list, insert_6) {
  s21::list<unsigned int> s21_List = {2, 3};
  s21::list<unsigned int>::iterator myiter;
  EXPECT_THROW(s21_List.insert(myiter, 4), std::invalid_argument);
}

TEST(list, erase_0) {
  std::list<unsigned int> List = {1, 7, 2, 3};
  s21::list<unsigned int> s21_List = {1, 7, 2, 3};
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  List.erase(++iter);
  s21_List.erase(++myiter);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, erase_1) {
  s21::list<unsigned int> MyList;
  auto myiter = MyList.begin();
  EXPECT_ANY_THROW(MyList.erase(myiter));
}

TEST(list, erase_2) {
  std::list<unsigned int> List = {1, 2, 3};
  s21::list<unsigned int> s21_List = {1, 2, 3};
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  List.erase(iter);
  s21_List.erase(myiter);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, erase_3) {
  s21::list<unsigned int> MyList = {1, 2, 3};
  auto myiter = MyList.end();
  EXPECT_ANY_THROW(MyList.erase(myiter));
}

TEST(list, erase_4) {
  std::list<unsigned int> List = {1, 2, 3};
  s21::list<unsigned int> s21_List = {1, 2, 3};
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  ++iter;
  ++myiter;
  List.erase(++iter);
  s21_List.erase(++myiter);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, erase_5) {
  s21::list<unsigned int> s21_List = {1, 7, 2, 3};
  auto myiter = s21_List.begin();
  EXPECT_THROW(s21_List.erase(--myiter), std::invalid_argument);
}

TEST(list, erase_6) {
  std::list<unsigned int> List = {1};
  s21::list<unsigned int> s21_List = {1};
  auto iter = List.begin();
  auto myiter = s21_List.begin();
  List.erase(iter);
  s21_List.erase(myiter);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, swap_0) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2{3, 2, 1};
  List_1.swap(List_2);
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2{3, 2, 1};
  s21_List_1.swap(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, swap_1) {
  std::list<unsigned int> List_1;
  std::list<unsigned int> List_2{3, 2, 1};
  List_1.swap(List_2);
  s21::list<unsigned int> s21_List_1;
  s21::list<unsigned int> s21_List_2{3, 2, 1};
  s21_List_1.swap(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, swap_2) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2;
  List_1.swap(List_2);
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2;
  s21_List_1.swap(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, swap_3) {
  std::list<unsigned int> List_1;
  std::list<unsigned int> List_2;
  List_1.swap(List_2);
  s21::list<unsigned int> s21_List_1;
  s21::list<unsigned int> s21_List_2;
  s21_List_1.swap(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_0) {
  std::list<unsigned int> List_1{0, 3, 4};
  std::list<unsigned int> List_2{1, 2, 5};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{0, 3, 4};
  s21::list<unsigned int> s21_List_2{1, 2, 5};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_1) {
  std::list<unsigned int> List_1{0, 1, 3};
  std::list<unsigned int> List_2{2, 2, 4};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{0, 1, 3};
  s21::list<unsigned int> s21_List_2{2, 2, 4};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_2) {
  std::list<unsigned int> List_1{5, 1, 3, 6, 2};
  std::list<unsigned int> List_2{2, 2, 4};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{5, 1, 3, 6, 2};
  s21::list<unsigned int> s21_List_2{2, 2, 4};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_3) {
  std::list<unsigned int> List_1{5, 1, 3, 6, 2};
  std::list<unsigned int> List_2;
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{5, 1, 3, 6, 2};
  s21::list<unsigned int> s21_List_2;
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_4) {
  std::list<unsigned int> List_1;
  std::list<unsigned int> List_2{2, 2, 4};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1;
  s21::list<unsigned int> s21_List_2{2, 2, 4};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_5) {
  std::list<unsigned int> List_1{5, 1, 3, 6, 2};
  std::list<unsigned int> List_2{8, 2, 4};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{5, 1, 3, 6, 2};
  s21::list<unsigned int> s21_List_2{8, 2, 4};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_6) {
  std::list<unsigned int> List_1{1};
  std::list<unsigned int> List_2{1};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{1};
  s21::list<unsigned int> s21_List_2{1};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, merge_7) {
  std::list<unsigned int> List{1};
  List.merge(List);
  s21::list<unsigned int> s21_List{1};
  s21_List.merge(s21_List);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, merge_8) {
  std::list<unsigned int> List_1{1, 43};
  std::list<unsigned int> List_2{1, 3, 9};
  List_1.merge(List_2);
  s21::list<unsigned int> s21_List_1{1, 43};
  s21::list<unsigned int> s21_List_2{1, 3, 9};
  s21_List_1.merge(s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_0) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2{4, 5, 6};
  auto iter = List_1.cend();
  List_1.splice(iter, List_2);
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2{4, 5, 6};
  auto s21_iter = s21_List_1.cend();
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_1) {
  std::list<unsigned int> List_1;
  std::list<unsigned int> List_2{4, 5, 6};
  auto iter = List_1.cend();
  List_1.splice(iter, List_2);
  s21::list<unsigned int> s21_List_1;
  s21::list<unsigned int> s21_List_2{4, 5, 6};
  auto s21_iter = s21_List_1.cend();
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_2) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2;
  auto iter = List_1.cend();
  List_1.splice(iter, List_2);
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2;
  auto s21_iter = s21_List_1.cend();
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_3) {
  std::list<unsigned int> List_1;
  std::list<unsigned int> List_2;
  auto iter = List_1.cend();
  List_1.splice(iter, List_2);
  s21::list<unsigned int> s21_List_1;
  s21::list<unsigned int> s21_List_2;
  auto s21_iter = s21_List_1.cend();
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_4) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2{4, 5, 6};
  auto iter = List_1.cbegin();
  List_1.splice(iter, List_2);
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2{4, 5, 6};
  auto s21_iter = s21_List_1.cbegin();
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, splice_5) {
  std::list<unsigned int> List_1{1, 2, 3};
  std::list<unsigned int> List_2{4, 5, 6};
  auto iter = List_1.cbegin();
  s21::list<unsigned int> s21_List_1{1, 2, 3};
  s21::list<unsigned int> s21_List_2{4, 5, 6};
  auto s21_iter = s21_List_1.cbegin();
  for (int i = 0; i < 3; i++, ++iter, ++s21_iter) {
  }
  List_1.splice(iter, List_2);
  s21_List_1.splice(s21_iter, s21_List_2);
  ASSERT_EQ(ListEqual(s21_List_1, List_1), true);
  ASSERT_EQ(ListEqual(s21_List_2, List_2), true);
}

TEST(list, reverse_0) {
  s21::list<unsigned int> s21_List = {1, 2, 3, 4, 5};
  std::list<unsigned int> List = {1, 2, 3, 4, 5};
  s21_List.reverse();
  List.reverse();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, reverse_1) {
  s21::list<unsigned int> s21_List = {5};
  std::list<unsigned int> List = {5};
  s21_List.reverse();
  List.reverse();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, reverse_2) {
  s21::list<unsigned int> s21_List = {};
  std::list<unsigned int> List = {};
  s21_List.reverse();
  List.reverse();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, unique_0) {
  s21::list<unsigned int> s21_List = {1, 1, 1, 4, 5};
  std::list<unsigned int> List = {1, 1, 1, 4, 5};
  s21_List.unique();
  List.unique();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, unique_1) {
  s21::list<unsigned int> s21_List = {1};
  std::list<unsigned int> List = {1};
  s21_List.unique();
  List.unique();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, unique_2) {
  s21::list<unsigned int> s21_List = {1, 1, 1, 1, 1};
  std::list<unsigned int> List = {1, 1, 1, 1, 1};
  s21_List.unique();
  List.unique();
  ASSERT_EQ(List.size(), s21_List.size());
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_0) {
  s21::list<int> s21_List = {43, 1};
  std::list<int> List = {43, 1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_1) {
  s21::list<int> s21_List = {6, 5, 4, 3, 2, 1};
  std::list<int> List = {6, 5, 4, 3, 2, 1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_2) {
  s21::list<unsigned int> s21_List = {43, 1, 3, 1};
  std::list<unsigned int> List = {43, 1, 3, 1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_3) {
  s21::list<int> s21_List = {1, 1};
  std::list<int> List = {1, 1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_4) {
  s21::list<int> s21_List{};
  std::list<int> List{};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_5) {
  s21::list<int> s21_List = {1, 4, 6, 7, 2, -7};
  std::list<int> List = {1, 4, 6, 7, 2, -7};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_6) {
  s21::list<int> s21_List = {-1};
  std::list<int> List = {-1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, sort_7) {
  s21::list<int> s21_List = {-1};
  std::list<int> List = {-1};
  s21_List.sort();
  List.sort();
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_0) {
  std::list<int> List = {1, 2, 3, 4, 5, 6};
  s21::list<int> s21_List = {1, 2, 3};
  auto iter = s21_List.cend();
  auto iter_res = s21_List.insert_many(iter, 4, 5, 6);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*iter_res, 4);
}

TEST(list, insert_many_1) {
  std::list<int> List = {1, 2, 3, 4, 5, 6};
  s21::list<int> s21_List = {4, 5, 6};
  auto iter = s21_List.cbegin();
  auto iter_res = s21_List.insert_many(iter, 1, 2, 3);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*iter_res, 1);
}

TEST(list, insert_many_2) {
  std::list<int> List = {1, 2, 3, 4, 5, 6};
  s21::list<int> s21_List = {1, 6};
  auto iter = s21_List.cbegin();
  auto iter_res = s21_List.insert_many(++iter, 2, 3, 4, 5);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*iter_res, 2);
}

TEST(list, insert_many_3) {
  std::list<int> List = {1, 2};
  s21::list<int> s21_List;
  auto iter = s21_List.cbegin();
  auto iter_res = s21_List.insert_many(iter, 1, 2);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*iter_res, 1);
}

TEST(list, insert_many_4) {
  std::list<int> List = {1};
  s21::list<int> s21_List;
  auto iter = s21_List.cbegin();
  auto iter_res = s21_List.insert_many(iter, 1);
  ASSERT_EQ(ListEqual(s21_List, List), true);
  ASSERT_EQ(*iter_res, 1);
}

TEST(list, insert_many_back_0) {
  std::list<int> List = {1, 2, 3, 4, 5, 6};
  s21::list<int> s21_List = {1, 2, 3};
  s21_List.insert_many_back(4, 5, 6);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_back_1) {
  std::list<int> List = {4, 5, 6};
  s21::list<int> s21_List;
  s21_List.insert_many_back(4, 5, 6);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_back_2) {
  std::list<int> List = {4};
  s21::list<int> s21_List;
  s21_List.insert_many_back(4);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_front_0) {
  std::list<int> List = {1, 2, 3, 4, 5, 6};
  s21::list<int> s21_List = {4, 5, 6};
  s21_List.insert_many_front(3, 2, 1);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_front_1) {
  std::list<int> List = {1, 2, 3};
  s21::list<int> s21_List;
  s21_List.insert_many_front(3, 2, 1);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}

TEST(list, insert_many_front_2) {
  std::list<int> List = {3};
  s21::list<int> s21_List;
  s21_List.insert_many_front(3);
  ASSERT_EQ(ListEqual(s21_List, List), true);
}
