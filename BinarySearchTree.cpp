#include<bits/stdc++.h>
using namespace std;
// Start Generic Node Class
template <typename T>
class Node
{
public:
    T data;
    Node *BiggerNodePoint,*SmallerNodePoint;
    Node(){};
    Node(T data)
    {
        this->data = data;
        this->BiggerNodePoint = NULL;
        this->SmallerNodePoint = NULL;
    }
};
// End of Generic Node Class
int main()
{

}