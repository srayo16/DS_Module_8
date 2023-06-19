#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }

    void show()
    {
        cout << val << " " << prev << " " << next << endl;
    }
};

void printing(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void tailPrint(Node *tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
}

void insertAtAny(Node *head, int pos, int val)
{

    Node *temp = head;
    Node *newNode = new Node(val);
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;

    // newNode->next = temp->next;
    // temp->next = newNode;
    // newNode->next->prev = newNode;
    // newNode->prev = temp;
}

void insertHead(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printingAll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int size(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;

    if (pos < 1 || pos > size(head))
    {
        cout << "Invalid" << endl;
        return;
    }

    if (pos == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
    }
    else if (pos == size(head))
    {
        Node *tmp = tail;
        tail = tmp->prev;
        tmp->prev->next = NULL;
        delete tmp;
    }
    else
    {

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        cout << temp->val << endl;

        Node *forDelete = temp->next;

        temp->next = temp->next->next;
        temp->next->prev = temp;

        delete forDelete;
    }
}

int main()
{
    // Node *head = NULL;
    // Node *tail = NULL;
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    int pos, val;
    cin >> pos;
    // insertAtTail(head, tail, val);
    deleteNode(head, tail, pos);
    // if (pos == 0)
    // {
    //     insertHead(head, tail, val);
    // }
    // else if (pos == size(head))
    // {
    //     insertAtTail(head, tail, val);
    // }
    // else if (pos >= size(head))
    // {
    //     cout << "Invalid index!" << endl;
    // }
    // else
    // {
    //     insertAtAny(head, pos, val);
    // }

    // printingAll(head);
    // cout << size(head) << endl;
    printing(head);
    cout << endl;
    tailPrint(tail);
    return 0;
}