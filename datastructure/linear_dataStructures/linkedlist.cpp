#include<iostream>
using namespace std; 
#define SIZE 10
template <class X>
class Node{
    X data;
    Node<X>*next;
    public:
    Node(X data);
    X getdata();
    Node<X>* getnext(){return next;};
    void append(Node<X>*node);
    void setnext(Node <X>*temp);
};
template <class X>
Node<X>::Node(X d){
    data=d;
    next=NULL;
}
template <class X>
X Node<X> ::getdata(){
    return data;
}
template <class X>
void Node<X>::append(Node<X>*node){
    node->next=next;
    next=node;
    }
template <class X>
void Node<X>::setnext(Node<X>*temp){
    next=temp;
}
//start the calss nodelist 
template <class X>
class Nodelist{
 Node<X>*head;
 Node<X>*tail;
 public:
Nodelist(){head=NULL;tail=NULL;} //done here
Node<X>*gethead(){return head;}  //done here
Node<X>*gettail(){return tail;} //done here
void sethead(Node<X>*temp){head=temp;}
void display(Node<X>*cur);                         
void append(Node<X>*node); //add to the end                 
void Delete(X data,Node<X>*&cur); //delete specific data (user choose what he wants to delete)
void insert(int pos,X data,Node<X>*&cur ); //position indicates the place the user wants to enter the node ,
                                            // data is the data of the inserted node
                                            //cur indicates to the head
};
//display
template <class X>
void Nodelist<X>::display(Node<X>*cur ){
    while(cur!=NULL){
        cout<<cur->getdata()<<"  ";
        cur=cur->getnext();
    }
}
//append
template <class X>
void Nodelist<X>::append(Node<X>*node ){
    
    if(head==NULL&tail==NULL){
        head=tail=node;
    }else {
        tail->append(node);
        tail=node;
    }
}
//insert function
template <class X>
void Nodelist<X>::insert(int pos, X data, Node<X> *&cur ){
   Node<X>*node= new Node<X>(data);
//    the node will be the head 
   if(pos==1){  
node->setnext(cur); //make the node points to the cur 
cur=node;
   }else {
       for( int i=1;i<pos-1;i++){
           cur=cur->getnext();
       }
      node->setnext(cur->getnext());
      cur->setnext(node);
   }
  
}
template <class X>
void Nodelist<X>::Delete(X data,Node<X>*&cur){
 Node<X>*temp=cur;
 Node<X>*temp1=cur->getnext();
  Node<X>*temp2=temp1->getnext();
  if (temp->getdata()==data){
cur=cur->getnext();
sethead(cur);
  }else {
while(temp1->getdata()!=data){
    temp=temp->getnext();
      temp1=temp1->getnext();
        temp2=temp2->getnext();
}
temp->setnext(temp2);
  }
}

////////////------------main------------/////////
int main(){
    Nodelist<int>*nodelist=new Nodelist<int>();

    //filling the linkedlist 
for(int i=0;i<SIZE;i++){
   
nodelist->append(new Node<int>(i+1));
}
//head
Node<int>*cur=nodelist->gethead();
//display 
cout<<"------------------before any modifications -----------"<<endl;
nodelist->display(cur);
cout<<endl;
//insert
cout<<"------------------inserting a node -----------"<<endl;
nodelist->insert(11,90,cur );
cur=nodelist->gethead();
nodelist->display(cur);
cout<<endl;
//deleting the first node 
cout<<"--------------Deleting the first node------------ "<<endl;
cur=nodelist->gethead();
nodelist->Delete(1,cur);

nodelist->display(cur);
cout<<endl;
//deleting middle node
cout<<"-------------Deleting the middle node-------------- "<<endl;
cur=nodelist->gethead();
nodelist->Delete(5,cur);

nodelist->display(cur);
cout<<endl;
//deleting last node
cout<<"---------------Deleting the last node-----------------"<<endl;
cur=nodelist->gethead();
nodelist->Delete(90,cur);

nodelist->display(cur);
cout<<endl;
    return 0;
}
