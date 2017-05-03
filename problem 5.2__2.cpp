#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  {
  inOrder(node->left);cout<<endl;
  cout<< node->data;
 inOrder(node->right);}
 
 
}  
node* search(struct node *node, int key)
{
    struct node* found = NULL;

    if(node == NULL)
        return NULL;

cout<< node->data<<"  "<<  key<<endl;

    if(node->data== key)
        return node;
    
    
	found = search(node->left, key);
    if (found)
        return found;
        
		

    found = search(node->right, key);
    if (found)
       return found;

    return NULL;
}
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   cout<<" Inorder traversal of the constructed tree is "<<endl;
  inOrder(root);
  int key;cout<<endl;
  cout<<"enter key"<<endl;
  cin>>key;
  struct node *tmp = search(root, key);
    if (tmp)
    {
        cout<<"key found"<<endl;
    }
    else
    {
      cout<<"key Not found in tree"<<endl;
    }
return 0; }

