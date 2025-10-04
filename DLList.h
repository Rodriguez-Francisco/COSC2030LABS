/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#ifndef __DLLLIST_H__
#define __DLLLIST_H__

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value);
    
};

class DLL{
    private:
    Node* head;
    Node* tail;

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