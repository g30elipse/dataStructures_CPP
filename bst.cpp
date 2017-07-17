/** Binary Search Tree
  * insert():           inserts an element in bst
  * inOrder():          in-order traversal
  * preOrder():         pre-order traversal
  * postOrder():        post-order traversal
  * search():           search for an element in bst
  * deleteNode():           delete a node with element 'd'
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


Node *searchElement(Node *root, int d)
{
    if(root == NULL || root->data == d)
        return root;
    else if(d < root->data)
        return searchElement(root->left, d);
    else
        return searchElement(root->right, d);
}


int findMin(Node *root)
{
    if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}


Node *deleteNode(Node *root, int d)
{
    if(d == root->data)
    {
        // If the node has no leaf nodes
        if(root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        // If the node has only one leaf node
        else if(root->left == NULL)
        {
            root->data = root->right->data;
            root->right = deleteNode(root->right, root->data);
        }
        else if(root->right == NULL)
        {
            root->data = root->left->data;
            root->left = deleteNode(root->left, root->data);
        }
        // If the node has both child nodes
        else
        {
            int x = findMin(root->right);
            root->data = x;
            root->right = deleteNode(root->right, x);
        }
    }
    else if(d < root->data)
        root->left = deleteNode(root->left, d);
    else
        root->right = deleteNode(root->right, d);

    return root;
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
    cin>>d;
    root = deleteNode(root, d);
    inOrder(root);
    return 0;
}



