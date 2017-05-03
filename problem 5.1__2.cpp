#include<iostream>
#include<stdlib.h>
#include<iomanip>
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
   
  inOrder(node->left);cout<<endl;
  cout<< node->data;
 inOrder(node->right);
} 
int maxDepth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
 int getLeafCount(struct node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);      
}
void siblings(struct node *root)
{
    
    if (root == NULL)
      return;
 
    
    if (root->left != NULL && root->right != NULL)
    { cout<<root->left->data<<"  "<<root->right->data<<"   are siblings "<<endl;
        siblings(root->left);
        siblings(root->right);
    }
 
    
    else if (root->right != NULL)
    {
    
        siblings(root->right);
    }
 
    
    else if (root->left != NULL)
    {
    
        siblings(root->left);
        
    }
}void father(struct node *root)
{if(root==NULL)
return;
if(root->left!=NULL||root->right!=NULL)
{
cout<<root->data<<"  is a father of"<<root->left->data<<"  "<<root->right->data<<endl;
father(root->left);
father(root->right);}
else
{cout<<root->data<<"  is not a father of any child"<<endl;
father(root->left);
father(root->right);
}
}
  
int main()
{struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   cout<<" Inorder traversal of the constructed tree is "<<endl;
  inOrder(root);
  cout<<endl;
cout<<"height="<<maxDepth(root)<<endl;
cout<<"no of leaf="<< getLeafCount(root)<<endl;
siblings(root);
father(root);
 return 0; }

