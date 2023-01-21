#include <bits/stdc++.h>
using namespace std;
// Start Generic Node Class
template <typename T>
class Node
{
public:
    T data;
    Node *point;
    Node();
    Node(T data)
    {
        this->data = data;
        this->point = NULL;
    }
};
// End of Generic Node Class

// Start of Generic LinkList Implementation
template <typename T>
class ChainNode
{
public:
    Node<T> *start = NULL;
    long long siz = 0;
    void add(T data)
    {
        if (start == NULL)
            start = new Node<T>(data);
        else
        {
            Node<T> *temp = start;
            while (temp->point != NULL)
                temp = temp->point;
            temp->point = new Node<T>(data);
        }
        siz++;
    }
    void traverse()
    {
        Node<T> *temp = start;
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->point;
        }
    }
    void removeElement(T dat)
    {
        if (start->data == dat)
        {
            start = start->point;
            siz--;
            return;
        }
        Node<T> *temp = start;
        Node<T> *nextPoint = start->point;
        Node<T> *previousPoint;
        while (temp != NULL and temp->data != dat)
        {
            previousPoint = temp;
            temp = temp->point;
            if (temp == NULL)
            {
                cout << "The Element does not exist" << endl;
                return;
            }
            nextPoint = nextPoint->point;
        }
        previousPoint->point = nextPoint;
        siz--;
    }
    void InsertElementAT(T data, T theElementAfter)
    {
        Node<T> *temp = start;
        Node<T> *New = new Node<T>(data);
        while (temp != NULL and temp->data != theElementAfter)
        {
            temp = temp->point;
            if (temp == NULL)
            {
                cout << "The Element you want to insert after does not exist , So inserted at last" << endl;
            }
        }
        New->point = temp->point;
        temp->point = New;
        siz++;
    }
    long long size() { return siz; }
};
// End of Generic LinkList implementation

int main()
{
    ChainNode<long long> chain;
    chain.add(10);
    // cout << chain.start->data << endl;
    chain.add(20);
    chain.add(20);
    // cout << chain.start->data << endl;
    chain.add(30);
    // cout << chain.start->data << endl;
    chain.traverse();
    cout << endl;
    chain.InsertElementAT(50, 20);
    chain.traverse();
    cout << endl;
    chain.removeElement(20);
    chain.traverse();
    cout << endl;
    chain.removeElement(40);
}