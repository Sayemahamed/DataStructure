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

// Start of Generic Stack Implementation
template <typename T>
class couldNotFindFancyWordAsStack
{
public:
    Node<T> *top = NULL;
    long long siz = 0;
    void add(T data)
    {
        Node<T> *temp = new Node<T>(data);
        temp->point = top;
        top = temp;
        siz++;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Underflow ERROR: Stack is empty." << endl;
            return;
        }
        top = top->point;
        siz--;
    }
    T show()
    {
        if (top == NULL)
            cout << "Underflow ERROR: Stack is empty." << endl;
        return top->data;
    }
    long long size() { return siz; }
    void traverse()
    {
        while (top != NULL)
        {
            cout << top->data << ' ';
            couldNotFindFancyWordAsStack::pop();
        }
    }
};
// End of Generic Stack Implementation

int main()
{
    couldNotFindFancyWordAsStack<string> aStack;
    cout << aStack.size() << endl;
    aStack.add("10");
    cout << aStack.show() << endl;
    aStack.add("20");
    aStack.add("20");
    cout << aStack.size() << endl;
    cout << aStack.show() << endl;
    // aStack.pop();
    cout << aStack.show() << endl;
    cout << aStack.size() << endl;
    aStack.traverse();
    cout << endl;
    cout << aStack.size() << endl;
}