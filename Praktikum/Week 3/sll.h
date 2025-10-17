#ifndef SLL_H
#define SLL_H

struct Node {
    int data;
    Node* next;
};

struct SLL {
    Node* head;
};

void CreateList(SLL &L);

bool IsEmpty(SLL L);

void InsertFirst(SLL &L, int x);
void InsertLast(SLL &L, int x);
void InsertAfter(Node* prevNode, int x);

void DeleteFirst(SLL &L);
void DeleteLast(SLL &L);
void DeleteAfter(Node* prevNode);

void ViewList(SLL L);

#endif
