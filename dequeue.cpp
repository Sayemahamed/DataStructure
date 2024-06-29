#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>*next,*prev;
    Node(){
        this->next = NULL;
        this->prev = NULL;
    }
    Node(T data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
template<typename T>
class DQ{
    long long siz=0;
    Node<T>* head=new Node<T>(),* tail=new Node<T>();
    void headTraverse(){
        Node<T>* tmp = head->next;
        while(tmp!=tail){
            cout<<tmp->data<<endl;
            tmp=tmp->next;
        }
    }
    void tailTraversal(){
        Node<T>* tmp = tail->prev;
        while(tmp!=head){
            cout<<tmp->data<<endl;
            tmp=tmp->prev;
        }
    }
    public:
    DQ(){
        head->next = tail;
        tail->prev = head;
    }
    void pushBack(T data){
        Node<T>* tmp =new Node<T>(data);
        if(tmp==NULL){
            cout<<"Overflow"<<endl;
            return;
        }
        tmp->prev=tail->prev;
        tail->prev->next = tmp;
        tail->prev=tmp;
        tmp->next = tail;
        siz++;
    }
    void pushFront(T data){
        Node<T>* tmp=new Node<T>(data);
        if(tmp==NULL){
            cout<<"Overflow"<<endl;
            return;
        }
        tmp->next=head->next;
        head->next->prev=tmp;
        head->next=tmp;
        tmp->prev=head;
        siz++;
    }
    void popBack(){
        Node<T>*tmp=tail->prev;
        if(tail->prev==head){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            tail->prev->prev->next=tail;
            tail->prev->next=NULL;
            tail->prev=tail->prev->prev;
            delete tmp;
        }
        siz--;
    }
    void popFront(){
        Node<T>*tmp=head->next;
        if(head->next==tail){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            head->next->next->prev=head;
            head->next->prev=NULL;
            head->next=head->next->next;
            delete tmp;
        }
        siz--;
    }
    long long size(){return siz;}
    T front(){return siz?head->next->data:NULL;}
    T back(){return siz?tail->prev->data:NULL;}
};
int main(){
    DQ<long long> dq;
    dq.pushFront(40);
    dq.pushFront(30);
    dq.pushBack(1);
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(10);
    // dq.headTraverse();
    // cout<<endl<<endl;
    // dq.tailTraversal();
    cout<<dq.size()<<endl;
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl<<endl;
    // dq.headTraverse();
    // cout<<endl;
    // dq.tailTraversal();
    // cout<<endl<<endl;
    dq.popFront();
    cout<<dq.front()<<endl;
    dq.popBack();
    cout<<dq.back()<<endl<<endl;
    cout<<dq.size()<<endl;
    // dq.headTraverse();
    // cout<<endl;
    // dq.tailTraversal();
    // cout<<endl<<endl; 
}