/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#pragma once
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class DLL{
    private:
    Node* head;
    Node*tail;

public:
    DLL();
    void insertAtHead(node*);
    void insertAttail(node*);

    void deleteAtHead();
    void deleteAtTail();
    void traverse();
    ~DLL();


};