// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
    typedef struct node {
    T value;
    struct node* next;
  } Node;
  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head != nullptr)
      pop();
  }
  void push(const T& value) {
    Node* newNode, *currentNode, *pre = nullptr;
    newNode = new Node;
    newNode->value = value;
    if (head == nullptr || value.prior > head->value.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      currentNode = head;
      while (currentNode && value.prior <= currentNode->value.prior) {
        pre = currentNode;
        currentNode = currentNode->next;
      }
      newNode->next = pre->next;
      pre->next = newNode;
    }
  }
  T pop() {
    if (head == nullptr) {
      throw std::string("Empty");
    } else {
      Node* newNode;
      newNode = head;
      T value = newNode->value;
      head = newNode->next;
      delete newNode;
      return value;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
