#include "binary_tree.h"

using namespace s21;


// ******************************
// ----------- DELETE -----------
// ******************************

// Идея удаления элемента делится на несколько случаев:
// + у узла нет дочерних узлов;
// - у узла есть левый дочерних узлов;
// - у узла есть правый дочерних узлов;
// - у узла есть оба ребёнка.

// void BinaryTree::DeleteElement(int x) {
//   bool flag_identic_key = false;
//   Node** cur = &Root;                // храним адрес УКАЗАТЕЛЯ на узел
//   while (*cur && !flag_identic_key) { // пока корень не пустой
//     Node& node = **cur;              // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
//     if (x < node.Key) {
//       cur = &node.Left;               // берем адрес УКАЗАТЕЛЯ на левый узел
//     } else if (x > node.Key) {
//       cur = &node.Right;              // берем адрес УКАЗАТЕЛЯ на правый узел
//     } else {
//       flag_identic_key = true;
//     }
//   }

//   (*cur)->PrintNode();
  
//   if (flag_identic_key) {
//     Node& curnode = **cur;
//     if (curnode.Left && curnode.Right) {
//       // // из левой ветви удаляемого узла находим наибольший узел
//       // Node** parent = MaxNode(cur); // parent max node
//       // Node** tmp = (*parent)->Right;

//       Node* tmp = MaxNode(cur); // max node
//       tmp->PrintNode();
//       tmp->Left = curnode.Left;
//       tmp->Right = curnode.Right;
//       *cur = tmp;

//     } else if (curnode.Left) {
//       *cur = curnode.Left;
//     } else if (curnode.Right) {
//       *cur = curnode.Right;
//     } else {
//       *cur = nullptr;     // адрес на узел
//     }
//   }

//   // добавить удаление самой ноды и освобождение памяти
//   // пока буду просто ввырезать элементы из структуры
//   // DestroyTree(*cur);
//   // delete *cur;  
// }


// // написать перемещение узла с зачисткой хвостов
// Node* BinaryTree:: MaxNode(Node** node) {
//   Node** prev = node;
//   Node* cur = (*node)->Left;
//   if (cur->Right) {
//     while(cur->Right) {
//       prev = &cur;
//       cur = cur->Right;
//     }
//     (*prev)->Right = nullptr;
//   } else {
//     (*prev)->Left = nullptr;
//   }
//   return cur;


//   // Node* cur = node;
//   // Node* prev = cur;
//   // while(cur->Right) {
//   //   // prev = cur;
//   //   cur = cur->Right;
//   // }
//   // prev->Right = nullptr;
//   // return cur;
//   // // return prev;

//   // Node* cur = node;
//   // if (cur->Right != nullptr)
//   //   cur = MaxNode(node->Right);
//   // return cur;
// }
