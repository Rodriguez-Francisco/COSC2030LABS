/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#ifndef TDLLIST_H
#define TDLLIST_H

#include <iostream>
#include<string>
using namespace std;

template <typename TTT >
class Node{

    public:
        TTT data;
        Node<TTT>* next;
        Node<TTT>* prev;

        Node(TTT value){
            data = value;
            next = nullptr;
            prev = nullptr;

        }
};

template <typename TTT>
class TDLList{
private:
    Node<TTT>* head; 
    Node<TTT>* tail;
public:

    TDLList(){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(Node<TTT>*x){
        if(head==nullptr){
            head = x;
            tail = x ;
        
        }
        else{
            x->next = head;
            head->prev =x;
            head=x;
        }
    }

void insertAtTail(Node<TTT>*x){
    if(tail==nullptr){
        head=x;
        tail=x;
    }
    else{
        tail->next=x;
        x->prev=tail;
        tail=x;
    }

}
void deleteAtHead(){
    if(head==nullptr)return;

    if(head==tail){
        delete head;
        head = nullptr;
        tail= nullptr;

    }
    else{
        Node<TTT>* temp=head;
        head= head->next;
        head->prev=nullptr;
        delete temp;
    }
}
    void deleteAtTail(){
        if(tail==nullptr)return;

        if(head==tail)
        {
            delete tail;
            head = nullptr;
            tail=nullptr;
        }
        else{
            Node<TTT>* temp = tail;
            tail= tail->prev;
            tail->next=nullptr;
            delete temp;
        }
    }

    void traverse(){
        Node<TTT>* curr=head;

        if(curr==nullptr){
            cout<<"List empty\n\n";
            return;
        }
        while(curr != nullptr){
            cout<<"["<<curr->data<<"]";
            curr= curr->next;
        }

    }

    ~TDLList(){
        while(head !=nullptr){
            deleteAtHead();
        }
    }










};
#endif