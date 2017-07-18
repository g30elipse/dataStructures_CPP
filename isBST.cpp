/** Check if the given tree is a BST
*/

#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};


Node* createLeaf(int d)
{
    Node *tmp = new Node;
    tmp->left = tmp->right = NULL;
    tmp->data = d;
    return tmp;
}


Node* init()
{
    Node *root;
    root = createLeaf(4);
    root->right = createLeaf(6);
    root->left = createLeaf(3);
    root->right->right = createLeaf(10);
    root->right->left = createLeaf(5);
    root->left->left = createLeaf(2);
    root->right->right->left = createLeaf(7);
    return root;
}


int minval(Node *root)
{
	if(!root->left)
		return root->data;
	else
		return minval(root->left);
}

int maxval(Node *root)
{
	if(!root->right)
		return root->data;
	else
		return maxval(root->right);
}


bool isBST(Node* root)
{
    if(!root)
        return true;
    else
    {
        int rmin = INT_MAX;
        int lmax = INT_MIN;
        if(root->right)
            rmin = minval(root->right);
        if(root->left)
            lmax = maxval(root->left);
        bool flag = (root->data > lmax) & (root->data < rmin);
        return (isBST(root->left) & isBST(root->right) & flag);
    }
}

int main()
{
    Node *root = init();
    if(isBST(root))
        cout<<"The tree is a BST"<<endl;
    else
        cout<<"The tree is not a BST"<<endl;

    return 0;
}
