/*Franisco Rodriguez
UWYO COSC2030
Graded lab 2
*/
#include "TDLList.h"

int main(){
    int choice;
    TTT item;
    DLL* L =new DLL();
    Node*x;
    const string space ="--------------------------_-\n";
    
    do{
        cout<<space;
        L->traverse();
        cout<<space;
        cout << "1 - Insert at Head " << endl;
        cout << "2 - Insert at Tail" << endl;
        cout << "3 - Delete at Head" << endl;
        cout << "4 - Delete at Tail"  << endl;
        cout << "5 -  Traverse" << endl;
        cout << "6 - Exit" <<  endl;
        cout<<"Enter Choice-";
        cin>>choice;
        cout<<space;

        
        switch (choice) {
        case 1:
            cout << "Enter the data item to  insert at head: ";
            cin >> item;
            x = new Node;
            
            x->data = item;
            x->prev = nullptr;
            x->next = nullptr;
            L->insertAtHead(x);
                break;

        case 2:
            cout << "Enter the data item  to inserted at tail: ";
            cin >> item;
            x = new Node;
           
            x->data = item;
            x->prev = nullptr;
            x->next = nullptr;
            L->insertAtTail(x);
                break;

        case 3:
            L->deleteAtHead();
                break;
        case 4:
            L->deleteAtTail();
            break;

        case 5:
            L->traverse();
            break;

        case 6:
            break;

        default:
            cout << "Enter a valid choice\n\n";
             break;
        }
    } 
    while (choice != 6);
    

    delete L;
    return 0;


    }
