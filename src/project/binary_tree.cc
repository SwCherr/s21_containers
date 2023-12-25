#include "binary_tree.h"

using namespace s21;

TNode::TNode(int key) : Key(key), Left(nullptr), Right(nullptr) {};

void TNode::PrintTNode() {
  std::cout << Key << std::endl;
}

// ******************************
// --------- CLASS TREE ---------
// ******************************

TTree::TTree(): Root(nullptr) {} // constructor

TTree::~TTree() {          // destructor
  DestroyNode(Root);
}

void TTree::DestroyNode(TNode* node) {
  if (node) {
    DestroyNode(node->Left);
    DestroyNode(node->Right);
    delete node;
  } 
}



// void push(Node_t **head, T value) {
//   Node_t *tmp = malloc(sizeof(Node_t));
//   tmp->next = *head;
//   tmp->value = value;
//   *head = tmp;

  // TNode* tmp = new TNode(x);
  // tmp->Left = *cur;
  // *cur = tmp;
// }

void TTree::Insert(int x) {
  bool flag_identic_key = false;
  TNode** cur = &Root;                // храним адрес УКАЗАТЕЛЯ на узел
  while (*cur && !flag_identic_key) { // пока корень не пустой
    TNode& node = **cur;              // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
    if (x < node.Key) {
      cur = &node.Left;               // берем адрес УКАЗАТЕЛЯ на левый узел
    } else if (x > node.Key) {
      cur = &node.Right;              // берем адрес УКАЗАТЕЛЯ на правый узел
    } else {
      flag_identic_key = true;
    }
  }
  if (!flag_identic_key) *cur = new TNode(x); // меняем указатель на новую ноду
}

// Идея удаления элемента делится на несколько случаев:
// + у узла нет дочерних узлов;
// - у узла есть левый дочерних узлов;
// - у узла есть правый дочерних узлов;
// - у узла есть оба ребёнка.

void TTree::DeleteElement(int x) {
  bool flag_identic_key = false;
  TNode** cur = &Root;                // храним адрес УКАЗАТЕЛЯ на узел
  TNode** prev = nullptr;
  while (*cur && !flag_identic_key) { // пока корень не пустой
    TNode& node = **cur;              // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
    if (x < node.Key) {
      prev = &node.Left;
      cur = &node.Left;               // берем адрес УКАЗАТЕЛЯ на левый узел
    } else if (x > node.Key) {
      prev = &node.Right;
      cur = &node.Right;              // берем адрес УКАЗАТЕЛЯ на правый узел
    } else {
      flag_identic_key = true;
    }
  
    // std::cout << "*prev   ";
    // (**prev).PrintTNode();
    // std::cout << "*cur    ";
    // node.PrintTNode();
  }

  // std::cout << "*prev - ";
  // prevnode.PrintTNode();
  // std::cout << "*cur  - ";
  // curnode.PrintTNode();
  // std::cout << "*cur Left  - ";
  // node.Left->PrintTNode();
  // std::cout << "*prev Left - ";
  // prevnode.Left->PrintTNode();


  // (*prev)->PrintTNode();

  if (flag_identic_key) {
    TNode& curnode = **cur;
    // TNode& prevnode = **prev;

    if (curnode.Left) {
      *prev = curnode.Left;
    } 

    if (curnode.Right) {
      *prev = curnode.Right;
    } 

    // if (curnode.Right) {
    //   // prev->PrintTNode();
    //   prev = &curnode.Right;
    // } 
    
    // if (curnode.Left && curnode.Right) {

    // } else {
    //   *cur = nullptr;     // адрес на узел
    // }




  // std::cout << "*prev Left - ";
  // prevnode.Left->PrintTNode();
  }


  // добавить удаление самой ноды и освобождение памяти
  // пока буду просто ввырезать элементы из структуры

  // DestroyNode(*cur);
  // delete *cur;
  
}


void TTree::TreePrint() {
  TreePrintPrivate(Root);
  std::cout << std::endl;
}

// ******************************
// ----------- PRIVATE ----------
// ******************************

// пока что такая костылявая реализация с инкапсуляцией
void TTree::TreePrintPrivate(TNode* node) {
  if (node!=NULL) {                      //Пока не встретится пустой узел
    TreePrintPrivate(node->Left);        //Рекурсивная функция для левого поддерева
    std::cout << node->Key << " ";       //Отображаем корень дерева
    TreePrintPrivate(node->Right);       //Рекурсивная функция для правого поддерева
  }
}