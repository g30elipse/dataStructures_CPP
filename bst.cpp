/** Binary Search Tree
  * insert():           inserts an element in bst
  * inOrder():          in-order traversal
  * preOrder():         pre-order traversal
  * postOrder():        post-order traversal
***/


#include <iostream>
using namespace std;


struct Node
{
    struct Node *left, *right;
    int data;
};


// Create a leaf node with data 'd'
Node *createLeaf(int d)
{
    Node *ptr = new Node;
    ptr->data = d;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}


Node *insert(Node *root, int d)
{
    if(!root)
        return createLeaf(d);
    if(d < root->data)
        root->left = insert(root->left, d);
    else
        root->right = insert(root->right, d);
    return root;
}

void preOrder(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void inOrder(Node *root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}



int main()
{
    int n, d;
    Node *root = NULL;
    cin>>n;
    while(n--)
    {
        cin>>d;
        root = insert(root, d);
    }
    inOrder(root);
    return 0;
}



