#include <bits/stdc++.h>
using namespace std;
// Start Generic Node Class
template <typename T>
class Node
{
public:
    T data;
    Node<T> *BiggerNodePoint, *SmallerNodePoint;
    Node(){};
    Node(T data)
    {
        this->data = data;
        this->BiggerNodePoint = NULL;
        this->SmallerNodePoint = NULL;
    }
};
// End of Generic Node Class

// Start of Generic Binary Search Tree Class Implementation
template <typename T>
class GenericBinarySearchTree
{
private:
    Node<T> *Root = NULL;
    long long rightWeight = 0, leftWeight = 0, Size = 0;
    void depthFirstSearch(Node<T> *node)
    {
        if (node == NULL)
            return;
        depthFirstSearch(node->SmallerNodePoint);
        cout << node->data << ' ';
        depthFirstSearch(node->BiggerNodePoint);
    }
    void depthFirstSearchForOverLapping(Node<T> *firstNode, Node<T> *secondNode)
    {
        if (secondNode == NULL or firstNode==NULL)return;
        if(firstNode->data==secondNode->data){
            if(firstNode->SmallerNodePoint == NULL and secondNode->SmallerNodePoint!=NULL)
            firstNode->SmallerNodePoint=secondNode->SmallerNodePoint;
            if(firstNode->BiggerNodePoint == NULL and secondNode->BiggerNodePoint!=NULL)
            secondNode->BiggerNodePoint=secondNode->SmallerNodePoint;
        }
        depthFirstSearchForOverLapping(firstNode->SmallerNodePoint, secondNode->SmallerNodePoint);
        firstNode->data += secondNode->data;
        depthFirstSearchForOverLapping(firstNode->BiggerNodePoint, secondNode->BiggerNodePoint);
    }

public:
    void add(T data)
    {
        if (Root == NULL)
        {
            Root = new Node<T>(data);
        }
        else
        {
            bool bigNode = false, smallNode = false;
            Node<T> *temp = Root;
            Node<T> *New = new Node<T>(data);
            if (temp->data < data)
            {
                bigNode = true;
                smallNode = false;
            }
            else
            {
                smallNode = true;
                bigNode = false;
            }
            while (true)
            {
                if (temp->BiggerNodePoint == NULL and bigNode)
                    break;
                if (temp->SmallerNodePoint == NULL and smallNode)
                    break;
                if (temp->data < data)
                {
                    temp = temp->BiggerNodePoint;
                }
                else
                {
                    temp = temp->SmallerNodePoint;
                }
                if (temp->data < data)
                {
                    bigNode = true;
                    smallNode = false;
                }
                else
                {
                    smallNode = true;
                    bigNode = false;
                }
            }
            if (bigNode)
            {
                rightWeight++;
                temp->BiggerNodePoint = New;
            }
            else
            {
                leftWeight++;
                temp->SmallerNodePoint = New;
            }
        }
    }
    void traverse()
    {
        depthFirstSearch(Root);
        cout << endl;
    }
    void overLapping(GenericBinarySearchTree<T> &second)
    {
        depthFirstSearchForOverLapping(Root, second.Root);
    }
};
// End of Generic Binary Search Tree Class Implementation
int main()
{
    GenericBinarySearchTree<long long> aDamnedTree, first, second;
    aDamnedTree.add(10);
    aDamnedTree.add(5);
    aDamnedTree.add(4);
    aDamnedTree.add(6);
    aDamnedTree.add(15);
    aDamnedTree.add(13);
    aDamnedTree.add(16);
    aDamnedTree.add(1);
    aDamnedTree.traverse();
    cout << endl;
    first.add(10);
    first.add(5);
    first.add(6);
    first.add(4);
    first.add(1);
    first.traverse();
    cout << endl;
    second.add(10);
    second.add(15);
    second.add(16);
    second.add(13);
    second.traverse();
    cout << endl;
    first.overLapping(second);
    first.traverse();
}