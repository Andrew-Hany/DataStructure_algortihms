#include<iostream>
using namespace std;

template<class X>
class Node{
    private:
    X data;
    Node *left;
    Node*right;
    public:
    Node<X>(X d){ data=d; left=NULL;right=NULL ;}
    X getdata(){return data;}
    Node<X>*getleft(){return left;}
    Node<X>*getright(){return right;}
    void setLeft( Node<X>*temp){left=temp;}
    void setRight( Node<X>*temp){right=temp;}
};
template<class X>
class BST{
    private:
    Node<X> *root;
    public:
     Node<X>*getroot(){return root;}
    BST();
   Node<X>* insert(Node<X>*root, X data);
   void inorder (Node<X>*root);
   void posorder (Node<X>*root);
      void preorder (Node<X>*root);
    };

template<class X>
BST<X>::BST(){
    root=NULL;
}
////////////////----------------insert ------------------------//////////////
template<class X>
Node<X>* BST<X>::insert(Node<X>*root, X data){
Node<X>*node=new Node<X>(data);
if(root==NULL){
root=node;
return root;
}
else if(data <=root->getdata()){
  
    root->setLeft(insert(root->getleft(),data));
}
else {
    root->setRight(insert(root->getright(),data));
    
}
return root;
}
////////////////----------------inorder ------------------------//////////////
template<class X>
void BST<X>::inorder(Node<X>*root){ // left root right

    if(root!=NULL){
      
        inorder(root->getleft());
        cout<<root->getdata()<<" ";
        inorder(root->getright());
         
       
        }else return;
  
}

template<class X>
void BST<X>::posorder(Node<X>*root){ // left right root
    if(root!=NULL){
      
        posorder(root->getleft());
        posorder(root->getright());
         cout<<root->getdata()<<" ";
       
        }else return;
  
}
template<class X>
void BST<X>::preorder(Node<X>*root){ // root left right 
    if(root!=NULL){
        cout<<root->getdata()<<" ";
        preorder(root->getleft());
        preorder(root->getright());
       
       
        }else return;
}
int main(){
    BST<int>*bst=new BST<int>();
    Node<int>*cur=bst->getroot();
    //creating the nodes of the tree the tree
   cur= bst->insert(cur, 10);
   cur= bst->insert(cur, 5);
     cur= bst->insert(cur, 14);
      cur= bst->insert(cur, 1);
 cur= bst->insert(cur, 7);
 cur= bst->insert(cur, 12);
      cur= bst->insert(cur, 16);
      //printing the inorder
  cout<<"inorder: ";
  bst->inorder(cur);
  cout<<endl;
    cout<<"postorder: ";
   bst->posorder(cur);
   cout<<endl;
    return 0;
}
