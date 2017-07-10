/** Linked List
  * insertHead: 		inserts an element 'd' in the beginning of the list
  * insertTail: 		inserts an element 'd' in the end of the list
  * display:    		displays the list in order
  * deleteNode:			delete an element 'x' from the list
  * deleteNodePos:		delete a node at position 'x'
  * listLength:			returns the length of the list
***/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};



void insertHead(node **head, int d)
{
    node *tmp = new node;
    tmp->data = d;
    tmp->next = *head;
    *head = tmp;
}

void insertTail(node **head, int d)
{
    node *tmp = new node;
    tmp->data = d;
    tmp->next = NULL;
    if(!(*head))
        *head = tmp;
    else
    {
        node *cur = *head;
        while(cur->next)
            cur = cur->next;
        cur->next = tmp;
    }
}


void deleteNode(node **head, int x)
{
    if((*head)->data == x)
        *head = (*head)->next;
    else
    {
        node *cur, *prev;
        prev = *head;
        cur = (*head)->next;
        while(cur->data != x)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
    }
}


void deleteNodePos(node **head, int x)
{
    if(x==1)
        *head = (*head)->next;
    else
    {
        node *cur = *head;
        node *prev;
        while(--x)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete(cur);
    }
}


int listLength(node *head)
{
    int l=0;
    while(head)
    {
		l++;
		head = head->next;
	}
    return l;
}


void display(struct node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
	cout<<endl;
}

int main()
{
    struct node *head=NULL;
    int n, d;
    cin>>n;
    while(n--)
    {
        cin>>d;
        insertTail(&head, d);
    }
    display(head);
    cout<<"Length of the list: "<<listLength(head)<<endl;
    return 0;
}
