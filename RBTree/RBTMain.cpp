#include "RBT.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
int choice, key;
RBT* tree = new RBT();
Node* found = nullptr;
const string separator = "(note -99999 means value not found)-------------------------------------\n";

do {
cout << separator;
cout << "Tree Inorder ";
tree->inorder();

cout << separator;
cout << "1. insert key" << endl;
cout << "2. delete key" << endl;
cout << "3. search for key" << endl;
cout << "4. Find minimum" << endl;
cout << "5. Find maximum" << endl;
cout << "6. Find inorder successor" << endl;
cout << "7. Find inorder predecessor" << endl;
cout << "8. display preorder traversal" << endl;
cout << "9. Display postorder Traversal" << endl;
cout << "10. exit" << endl;
cout << "Enter choice ";
cin >> choice;
cout << separator;

switch (choice) {
case 1:
cout << "Enter new key  ";
cin >> key;
tree->insert(key);
break;


case 2:
cout << "enter key to be deleted : ";
cin >> key;
tree->deleteKey(key);
break;


case 3:
cout << "Enter key to find: ";
cin >> key;
found = tree->search(key);
if (found != nullptr) {
cout << "key " << key << " was found" << endl;
}
else {
cout << "key " << key  << " couldnt be found" << endl;
}
break;


case 4:
cout << "minimum : " << tree->minimum() << endl;
break;


case 5:
cout << "maximum : " << tree->maximum() << endl;
break;


case 6:
cout << "Enter key to find its successor: ";
cin >> key;
cout << "successor of " << key << " == " << tree->successor(key) << endl;
break;


case 7:
cout << "Enter key to find its predecessor: ";
cin >> key;
cout << "predecessor of  " << key << " == " << tree->predecessor(key) << endl;
break;


case 8:
cout << "preorder Traversal ";
tree->preorder();
break;


case 9:
cout << "Postorder; ";
tree->postorder();
break;


case 10:
cout << "Exicting " << endl;
break;


default:
cout << "invalid choice" << endl;
break;
}

} while (choice != 10);

delete tree;
return 0;
}