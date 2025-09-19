/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#pragma once

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
    void insertAtHead(int val);
    void insertAttail(int val);

    void deleteAtHead();
    void deleteAtTail();
    void traverse();
    ~DLL();


};