#include<iostream>
#include<stack>
using namespace std;

class Node {
    public:
        int data;
        //vector<Node> child; //non_binary case
        Node* left;
        Node* right;

    Node (int Data) {
        this->data = Data;
        left = NULL;
        right = NULL;
    }
};

int MaxDepth (Node* node) {
    if (node == NULL)
        return 0;
    else
    {
        //depth cal
        int lDepth = MaxDepth(node->left);
        int rDepth = MaxDepth(node->right);

        // use larger depth
        if (lDepth > rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
    }
}

//Inorder: L, Root, R
void printInorder (Node* node) {
    if (node == NULL)
        return;

    //first recur on left child 
    printInorder (node->left);
 
    //then print the data of node 
    cout << node->data << " ";
 
    //now recur on right child 
    printInorder (node->right);
}

//Preorder: Root, L, R
void printPreorder (struct Node* node) {
    if (node == NULL)
        return;
 
    //first print data of node
    cout << node->data << " ";
 
    //then recur on left subtree
    printPreorder (node->left);
 
    //now recur on right subtree
    printPreorder (node->right);
}

//Postorder: L, R, Root
void printPostorder (struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder (node->left);
 
    // then recur on right subtree
    printPostorder (node->right);
 
    // now deal with the node
    cout << node->data << " ";
}

int isBST (struct Node* node) {
	if (node == NULL)
		return 1;

	//false if left is > than node
	if (node->left != NULL && node->left->data > node->data)
		return 0;

	//false if right is < than node
	if (node->right != NULL && node->right->data < node->data)
		return 0;

	//false if, recursively, the left or right is not a BST
	if (!isBST(node->left) || !isBST(node->right))
		return 0;

	/* passing all that, it's a BST */
	return 1;
}

// This code is contributed by shubhamsingh10



int main() {
    Node* root = new Node (1);
    root->left = new Node (2);
    root->right = new Node (3);
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    cout << MaxDepth (root) - 1 <<endl;
    printPreorder (root);
    cout << endl;
    printPostorder (root);
    cout << endl;
    if (isBST) printInorder (root);
}