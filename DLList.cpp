/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/

#include "DLList.h"

DLL::DLL(){
    head= nullptr;
    tail=nullptr;
}


void DLL::insertAtHead(Node* x){
x->prev=nullptr;
x->next= head;
if (head != nullptr){
    head-> prev =x;

}else{
    tail =x;
}
head = x;
}

void DLL::insertAtTail(Node* x){
x->next=nullptr;
x->prev= tail;
if (tail != nullptr){
    head-> next =x;

}else{
    tail =x;
}
tail = x; 
}

void DLL::deleteAtHead(){
    if(head==nullptr){
        cout<<"Error list is empty\n\n";
        return;
    }
    Node* temp =head;
    head =head->next;
   
    if (head != nullptr){
        head->prev =nullptr;

    }
    else{
        tail=nullptr;
    }
    delete temp;

    
}

void DLL::deleteAtTail(){
    if(tail==nullptr){
        cout<<"Error list is empty\n\n";
        return;
    }
    Node* temp =tail;
    tail =tail->prev;
   
    if (head != nullptr){
        tail->next =nullptr;
    }
    else{
        head=nullptr;
    }
    delete temp;}
void DLL::traverse(){
    if (head== nullptr){
        cout<<"Couldnt traverse list empty\n";
        return;
    }
    Node*curr=head;
    while(curr !=nullptr){
        cout<<"{"<<curr->data<<"}";
        curr = curr->next;
    }
    cout<<"\n\n";
}
DLL::~DLL() {
    Node* curr=head;
    while(curr !=nullptr){
        Node* temp=curr;
        curr= curr->next;
        delete temp;
    }
}

    
