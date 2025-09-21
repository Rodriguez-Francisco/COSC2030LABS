/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/

#include "DLList.h"

DLL::DLL(){
    head= nullptr;
    tail=nullptr;
}


void DLL:insertAtHead(node* x){
x->prev=nullptr;
x->next= head;
if (head == nullptr!){
    head-> prev =x;

}else{
    tail =x;
}
head = x;
}

void DLL::insertAttail(node*x){
x->next=nullptr;
x->prev= tail;
if (tail == nullptr!){
    head-> next =x;

}else{
    tail =x;
}
tail = x; 
}

void DLL::deleteAtHead(){
    if(head==nullptr){
        cout<<"Error list is empty\n\n"
        return;
    }
    node* temp =head;
    head =head->next;
   
    if (head== nullptr!){
        head->prev =nullptr;

    }
    else{
        tail=nullptr;
    }
    delete temp;

    
}

void DLL::deleteAtHead(){
    if(tail==nullptr){
        cout<<"Error list is empty\n\n"
        return;
    }
    node* temp =tail;
    head =tail->prev;
   
    if (head== nullptr!){
        tail->next =nullptr;
    }
    else{
        head=nullptr;
    }
    delete temp;
void DLL::traverse(){
    if (head== nullptr){
        cout<<"Couldnt traverse list empty\n"
        return;
    }
    node*curr=head;
    while(curr=nullptr!){
        cout<<"{"<<curr->data<<"}";
        curr = curr->
    }
    cout<<"\n\n";
}
DLL::~DLL(){
    node* curr=head;
    while(curr==nullptr!){
        node* temp=curr;
        curr= curr->nextl
        delete temp;
    }
}

    
}