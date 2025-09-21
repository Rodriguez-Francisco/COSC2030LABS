/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#ifndef __DLLLIST_H__
#define __DLLLIST_H__
#include <iostream>
using namespace std;
#ifndef TTT
#define TTT
#endif

class Node{
public:
    TTT data;
    Node* next;
    Node* prev;
};

class DLL{
    private:
    Node* head;
    Node*tail;

public:
    DLL();
    void insertAtHead(Node*);
    void insertAtTail(Node*);

    void deleteAtHead();
    void deleteAtTail();
    void traverse();
    ~DLL();


};
#endif