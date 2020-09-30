#include<iostream>
using namespace std;

template<class X>
class Node{
    private:
    X data;
    Node *left;
    Node*right;
     int height; //height of the tree (each node)
    public:
    Node<X>(X d){ data=d; left=NULL;right=NULL;height=1;}
    X getdata(){return data;}
    int getheight(){ if (this == NULL)  return 0;  return height;}
    Node<X>*getleft(){return left;}
    Node<X>*getright(){return right;}
     void setheight(int h){height=h;}
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
      Node<X>* RotateLeft(Node<X>*a);
        Node<X>* RotateRight(Node<X>*a);
   void inorder (Node<X>*root);
   void posorder (Node<X>*root);
      void preorder (Node<X>*root);
        int getBalanceFactor(Node<X>*N){ return N->getleft()->getheight() - N->getright()->getheight();}
        int max(int a, int b)  {  return (a > b)? a : b; }
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
else if(data >root->getdata()){
    root->setRight(insert(root->getright(),data));
    
}

//update the height 

  root->setheight( max(root->getleft()->getheight(), 
                    root->getright()->getheight()) + 1);    
  
 int balance=getBalanceFactor(root);

//  if the BST is not balanced
//  there are 4 cases 

// 1)Left left case
  if (balance > 1 && data < root->getleft()->getdata())  
        return RotateRight(root); 
        //2) Right Right Case  
    if (balance < -1 && data < root->getright()->getdata())  
        return RotateLeft(root);  
  
    // //3) Left Right Case  
    if (balance > 1 &&data > root->getleft()->getdata())  
    {  
        root->setLeft( RotateLeft(root->getleft()));  
        return RotateRight(root);  
    }  
  
    // // 4)Right Left Case  
    if (balance < -1 && data < root->getright()->getdata())  
    {  
        root->setRight (RotateRight(root->getright()));  
        return RotateLeft(root);  
    }  
  
return root;
}
////////////////----------------RotateRight------------/////////////
template<class X>
Node<X>* BST<X>:: RotateRight(Node<X>*a){
Node<X>*b=a->getleft();
Node<X>*c=b->getright();

// rotation 
b->setRight(a);
a->setLeft(c);
//update height 
                
 a->setheight( max(a->getleft()->getheight(), 
                    a->getright()->getheight()) + 1);  
    b->setheight( max(b->getleft()->getheight(), 
                    b->getright()->getheight()) + 1);

return b;
}
////////////////----------------RotateLeft------------/////////////
template<class X>
Node<X>* BST<X>:: RotateLeft(Node<X>*a){
Node<X>*b=a->getright();
Node<X>*c=b->getleft();

// rotation 
b->setLeft(a);
a->setRight(c);
//update height 
 a->setheight( max(a->getleft()->getheight(), 
                    a->getright()->getheight()) + 1);  
    b->setheight( max(b->getleft()->getheight(), 
                    b->getright()->getheight()) + 1);
return b;
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
   cur= bst->insert(cur, 20);
     cur= bst->insert(cur, 30);
      cur= bst->insert(cur, 40);
 cur= bst->insert(cur, 50);
 cur= bst->insert(cur, 25);
      //printing the inorder
  cout<<"inorder: ";
  bst->inorder(cur);
  cout<<endl;
    cout<<"postorder: ";
   bst->posorder(cur);
   cout<<endl;
    return 0;
}
