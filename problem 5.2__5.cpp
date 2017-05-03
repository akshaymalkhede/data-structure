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
 
void mirror(struct node* node) 
{
  if (node==NULL) 
    return;  
  else
  {
    struct node* temp;
    mirror(node->left);
    mirror(node->right);
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
} 
 
void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  cout<<endl;
cout<< node->data;
 
  inOrder(node->right);
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
  mirror(root); cout<<endl;
  cout<<" Inorder traversal of the mirror tree is "<<endl;  
  inOrder(root);
  return 0; }

