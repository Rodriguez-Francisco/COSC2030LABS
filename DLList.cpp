/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#include "DLList.h"
#include <iostream>
using namespace std;


Node::Node(int value){
    data = value ;
    next = nullptr;
    prev= nullptr ;

}

DLL::DLL(){
    head =nullptr;
    tail = nullptr;
}

void DLL::insertAtHead(Node * x){
   

    if(head == nullptr){
        head = x;
        tail= x;
    }
    else{
        x->next=head;
        head->prev=x;
        head = x;
    }
}

void DLL::insertAtTail(Node * x ) {
   
    if (tail == nullptr) {
        head = x;
        tail = x ;
    } 
    else {
        tail->next = x;
        x->prev = tail;
        tail =  x;
    }
}

void DLL::deleteAtHead(){
    if(head == nullptr) return; 

    
    if (head==tail){
        delete head;
        head = nullptr;
        tail=nullptr ;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->prev=nullptr;
        delete temp;
    }

}

void DLL::deleteAtTail(){
    if(head == nullptr) return; 

    
    if (head==tail){
        delete tail;
        head = nullptr;
        tail=nullptr ;
    }
    else{
        Node* temp = tail;
        tail = tail->prev;
        tail->next=nullptr;
        delete temp;
    }
    
}
void DLL::traverse(){
    Node* curr = head;

    if( curr == nullptr){
        cout<<"Empty list\n\n";
        return;
    }
    while (curr != nullptr){
        cout<<"["<<curr->data<<"]";
        curr = curr->next;
    }
}
DLL::~DLL() {
    while (head != nullptr) {
        deleteAtHead();
    }
}



