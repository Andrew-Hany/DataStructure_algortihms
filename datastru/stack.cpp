#include<iostream>
using namespace std;

#define SIZE  10

template <class X>
class stack{
    private:
    X*arr;
    int top;
    int capactity;
    public:
    stack(int size=SIZE);
    int size();
    void push (X);
    X pop();
    X peek();
    bool isEmpty();
    bool isFull();
};
template<class X>
stack<X>::stack(int size){
    arr=new X [size];
    capactity=size;
    top=-1;
}
template<class X>
void stack<X>::push(X x){
    if(isFull()){
        cout<<"overflow"<<endl;
        exit(EXIT_FAILURE );
    }
    else {
        cout<<"inserting "<<x<<endl;
        arr[++top]=x;
    }

}

template<class X>
X stack<X>::pop (){
    if(isEmpty()){
        cout<<"underflow"<<endl;
        exit(EXIT_FAILURE );
    }
    else {
        int x =arr[top];
        top--;
        return x;

    }

}
template<class X>
X stack<X>::peek (){
    if(isEmpty()){
        cout<<"underflow"<<endl;
        exit(EXIT_FAILURE );
    }
    else {
        int x =arr[top];
        return x;

    }

}

template<class X>
bool stack<X>::isFull (){
   return top==capactity-1;
}

template<class X>
bool stack<X>::isEmpty (){
   return top==-1;
}
int main(){
    stack<int>s;
    s.push (1);
     s.push (2);
      s.push (3);
       s.push (4);
        s.push (5);
        cout<<s.pop()<<" poped from the stack"<<endl;
     cout<<s.pop()<<" poped from the stack"<<endl;
      cout<<s.pop()<<" poped from the stack"<<endl;
      cout<<s.peek()<<" peeked from the stack not poped"<<endl;
      cout<<s.pop()<<" poped from the stack"<<endl;
      cout<<s.pop()<<" poped from the stack"<<endl;
      cout<<s.pop()<<" poped from the stack"<<endl;
    return 0;
}