#include<iostream>
using namespace std;

#define SIZE  10

template <class X>
class queue{
    private:
    X*arr;
    int top;
    int capactity;
    public:
    queue(int size=SIZE);
    int size();
    void Enqueue (X);
    X Dequeue();
    bool isEmpty();
    bool isFull();
};
template<class X>
queue<X>::queue(int size){
    arr=new X [size];
    capactity=size;
    top=-1;
}
template<class X>
int queue<X>::size(){
    return top+1;
}
template<class X>
void queue<X>::Enqueue(X x){
    if(isFull()){
        cout<<"overflow\n";
        exit(EXIT_FAILURE);
    }
    else {
        cout<<"enqueue "<<x<<endl;
        arr[++top]=x;
    }
}
template<class X>
X queue<X>::Dequeue(){
    if(isEmpty()){
        cout<<"underflow\n";
        exit(EXIT_FAILURE);
    }
    else {
       X x= arr[0];
       for(int i=0;i<top;i++){
           arr[i]=arr[i+1];
       }
       top--;
       cout<<"dequeue "<<x<<endl;
       return x;
    }
}

template<class X>
bool queue<X>::isFull (){
   return top==capactity-1;
}

template<class X>
bool queue<X>::isEmpty (){
   return top==-1;
}

int main(){
 queue<string> s;
 s.Enqueue("A");
  s.Enqueue("B");
    s.Enqueue("C");
      s.Enqueue("D");
 s.Dequeue();
 s.Dequeue();
 s.Dequeue();
  s.Dequeue();
   s.Dequeue();
    return 0;
}