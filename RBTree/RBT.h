#ifndef __RBT_H__
#define __RBT_H__

enum Color{RED,BLACK};
class Node {
public:
int key;
Color color;
Node* parent;
Node* left;
Node* right;

Node(int value);

};

class RBT {

private:

void rotateL(Node* x);
void rotateR(Node* y);
void rotateFix(Node* node);

Node* root;


public:

RBT();
~RBT();
void insert(int key);
void inorder();
int maximum();
void preorder();
void postorder();
int minimum();
int successor(int key);
int predecessor(int key);
void deleteKey(int key);
Node* search(int key);

};

#endif 