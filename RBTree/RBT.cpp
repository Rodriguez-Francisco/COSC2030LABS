#include "RBT.h"
#include <iostream>

using namespace std;

Node::Node(int value) {
    key = value;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color=RED;
}

RBT::RBT() {
    root = nullptr;
}

RBT::~RBT() {
    while (root != nullptr) {
        deleteKey(root->key);
    }


}

void RBT::insert(int key) {


    Node* newNode = new Node(key);
    if (root == nullptr) {
        root = newNode;
        rotateFix(newNode);
        return;
    }
Node* parentNode = nullptr;


    Node* current = root;
    while (current != nullptr) {
        parentNode = current;
       
        if (key  < current->key) {
            current = current->left;
        } 
        else {
            current  = current->right;
        }
    }
    newNode->parent = parentNode;
    if  (key  < parentNode->key) {
        parentNode->left = newNode;
    } 
    else {
        parentNode->right =  newNode;}
    rotateFix(newNode);
}


void RBT::inorder() {
    if (!root) return ;
    
    Node* current = root;
    
    while (current->left) {
        current = current->left;
    }
    
    while (current) {
        cout <<  current->key << " " ;
        if (current->right) {
            current = current->right;
            while (current->left) {
                current =  current->left;}
    } 
        
        else {
            Node* p = current->parent;
            while (p && current == p->right) {
                current = p;
                p = p->parent;
            }
            current = p;
    }
    }
    
}

void RBT::preorder() {
    if (!root) return ;
    
    Node* current = root;
    
    while (current != nullptr) {
        cout << current->key <<" " ;
       
        if (current->left) {
            current = current->left;
        } 
        else if (current->right) 
        {
            current = current->right;
        } 
        else {
            while (current->parent != nullptr && (current->parent->right == nullptr || current->parent->right == current) )  {
                current = current->parent;
            }
            if (current->parent != nullptr) {
                current = current->parent->right;
        } 
            else {
                current = nullptr;}
        }
}
    
}

void RBT::postorder() {
    if (!root) return ;
   
    Node* lastVisited = nullptr;
    Node* current = root;

    while (current) {
        if (current->left && lastVisited != current->left  && lastVisited !=  current->right) {
            current = current->left;

        }
        else if (current->right && lastVisited != current->right) {
            current  = current->right; }
        else {
            cout << current->key<< " ";
            lastVisited  = current;
            current = current->parent;
        }}
 
}
Node* RBT::search(int key) {
    Node* current = root;
   
    while (current != nullptr  && current->key !=  key) 
    {
        if (key < current->key) {
            current = current->left;
        }
         else {
            current =  current->right;}
    }
   
    return current;
}

int RBT::minimum() {
    if (!root) return -9999 ;
    
    Node* current = root;
    while (current->left != nullptr) {
        current  = current->left;}
    
    return current->key;
}

int RBT::maximum() {
    if (!root) return -99999 ;
    
    
    Node* current  = root;
    while (current->right != nullptr) {
        current =  current->right;
    }
    return  current->key;
}

int RBT::successor(int key) {
    Node* node = search(key);
    if (!node) return -99999 ;
    
    if (node->right) {
        Node* current  = node->right;
        
    while (current->left) {
        current = current->left;}
        return current->key;
    }
    Node* p = node->parent;
    
    while (p && node == p->right) {
        node = p;
        p = p->parent;}
    return p ? p->key : -1;
}

int RBT::predecessor(int key) {
    Node* node = search(key);
    if (!node) return -99999 ;
    
    
    if (node->left) {
        Node* current = node->left;
        while (current->right) {
            current = current->right;}
        
return current->key;
    }
    Node* p = node->parent;
    while (p && node == p->left) {
        node = p;
        p =  p->parent;
}
    return p ? p->key : -9999;
}

void RBT::deleteKey(int key) {
    Node* nodeToDelete = search(key);
    
    if (!nodeToDelete) return;
    
   
    if (nodeToDelete->left &&  nodeToDelete->right)  {
        Node* successor = nodeToDelete->right;
        
        while (successor->left != nullptr) {
            successor = successor->left;}
        
        nodeToDelete->key = successor->key;
        nodeToDelete = successor; 
    
    }
    

    Node* child = nodeToDelete->left ?  nodeToDelete->left : nodeToDelete->right;
    
    
    if (child) {
        child->parent = nodeToDelete->parent;
    
    }
    
   
    if (!nodeToDelete->parent) {
        root =  child;
    } 
    else if (nodeToDelete == nodeToDelete->parent->left) {
        nodeToDelete->parent->left = child;
    } 
    else {
        nodeToDelete->parent->right = child;}
    
    delete  nodeToDelete;
}



void RBT::rotateL(Node*x) {
    Node * Rchild = x->right;

    x->right=Rchild->left;
    if (Rchild->left){
        Rchild->left->parent = x;
    }
    Node* parent=x->parent;
    Rchild->parent= parent;
    if(!parent){
        root =Rchild;
    }
    else if (x==parent->left){
        parent->left=Rchild;
    }
    else{
        parent->right=Rchild;
    }
    Rchild-> left=x;
    x->parent =Rchild;

}
void RBT::rotateR(Node*y){
    Node* leftChild = y->left;

    y->left = leftChild->right;
    if (leftChild->right){
        leftChild->right->parent = y;}

    Node* parent = y->parent;
    leftChild->parent = parent;

    if (!parent){
        root = leftChild;}
    else if (y == parent->left){
        parent->left = leftChild;}
    else{
        parent->right = leftChild;}

    leftChild->right = y;

    y->parent = leftChild;
}

void RBT::rotateFix(Node*node){
    while((node->parent)&&(node->parent->color == RED)){
        Node* parent=node->parent;
        Node*grand=parent->parent;
        Node*uncle=nullptr;
        
        if(parent == grand->left){
            uncle = grand->right;
        }
        else{
            uncle=grand->left;
        }

        
        if(uncle && (uncle->color==RED)){
            parent->color=BLACK;
            uncle->color=BLACK;
            grand->color=RED;
            node=grand;
        }
        else{

            if((parent== grand->left)&&(node==parent->right)){
                node=parent;
                rotateL(node);
                parent=node->parent;
                grand=parent->parent;
            }
            else if ((parent==grand->right)&&(node==parent->left)){
                node=parent;
                rotateR(node);
                parent=node->parent;
                grand=parent->parent;
            }
            
            grand->color=RED;
            parent->color= BLACK;
            
            
            if(parent== grand->left){
                rotateR(grand);
            }else{
                rotateL(grand);
            
            }
            break;
        }
    }
root->color=BLACK;
    
}