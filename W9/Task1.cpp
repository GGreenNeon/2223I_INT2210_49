#include <iostream>
using namespace std;
#define COUNT 10

class BST {
    public:
        int data;
        //vector<Node> child; //non_binary case
        BST* left;
        BST* right;

    BST (int Data) {
        this->data = Data;
        left = NULL;
        right = NULL;
    }
};

void Free (BST* root) {
    if (root == NULL)
        return;
 
    Free (root->left);
    Free (root->right);
    free (root);
}

int LeftOf (const int value, const BST* root) {

    return value < root->data; // No duplicate
    //return value <= root->data; // Allow duplicate
}
 
int RightOf (const int value, const BST* root) {

    return value > root->data; // No duplicate
    //return value >= root->data; // Allow duplicate

}

BST* Insert (BST* root, const int value) {

    //Create new Node if that Node is NULL
    if (root == NULL) {
        BST* node = new BST (value);
        return node;
    }

    //
    if (LeftOf (value, root)) {
        root->left = Insert (root->left, value);
    }
    else if (RightOf (value, root)) {
        root->right = Insert (root->right, value);
    }
    return root;
}

int LeftMostValue (const BST* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

BST* Delete (BST* root, int value) {
    if (root == NULL)
        return root;

    if (LeftOf (value, root)) {
        root->left = Delete (root->left, value);
    }
    else if (RightOf (value, root)) {
        root->right = Delete (root->right, value);
    }
    else {
        // root->data == value, delete this node
        if (root->left == NULL) {
            BST* newRoot = root->right;
            free (root);
            return newRoot;
        }
        if (root->right == NULL) {
            BST* newRoot = root->left;
            free (root);
            return newRoot;
        }
        root->data = LeftMostValue (root->right);
        root->right = Delete (root->right, root->data);
    }
    return root;
}

//Inorder: L, Root, R
void printInorder (BST* root) {
    if (root == NULL)
        return;

    //first recur on left child 
    printInorder (root->left);
 
    //then print the data of root 
    cout << root->data << " ";
 
    //now recur on right child 
    printInorder (root->right);
}

//Postorder: L, R, Root
void printPostorder (struct BST* root)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    printPostorder (root->left);
 
    // then recur on right subtree
    printPostorder (root->right);
 
    // now deal with the root
    cout << root->data << " ";
}

//Preorder: Root, L, R
void printPreorder (struct BST* root) {
    if (root == NULL)
        return;
 
    //first print data of root
    cout << root->data << " ";
 
    //then recur on left subtree
    printPreorder (root->left);
 
    //now recur on right subtree
    printPreorder (root->right);
}

int main () {
    BST* root = NULL;
    root = Insert (root, 2);
    Insert (root, 1);
    Insert (root, 10);
    Insert (root, 6);
    Insert (root, 3);
    Insert (root, 8);
    Insert (root, 7);
    Insert (root, 13);
    Insert (root, 20);

    cout << "Binary Search Tree at the beginning: ";
    printPreorder (root);
    cout << endl;

    Insert (root, 14);
    Insert (root, 0);
    Insert (root, 35);
    cout << "Binary Search Tree after insert 14, 0 and 35: ";
    printPreorder (root);
    cout << endl;
    
    Delete (root, 6);
    Delete (root, 13);
    Delete (root, 35);
    cout << "Binary Search Tree after delete 6, 13 and 35: ";
    printPreorder (root);
    cout << endl;
}