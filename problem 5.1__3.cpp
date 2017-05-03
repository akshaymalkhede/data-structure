#include <iostream>
#include<iomanip>
#include <stdlib.h>
using namespace std;
struct node
{int value;
node* left;
node* right;
};
struct node* root;
struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);
void delete_tree(struct node **ptr,int item);
int main()
{
root = NULL;
int n, v;
cout<<"how many data's do you want to insert "<<endl;
cin>>n;
for(int i=0; i<n; i++){
cout<<"Data  "<<i+1;
cin>>v;
root = insert(root, v);
}
cout<<"Inorder Traversal"<<endl;
    inOrder(root);
cout<<endl;
cout<<"Preorder Traversal: "<<endl;
preOrder(root);
cout<<endl;
cout<<"Postorder Traversal "<<endl;
postOrder(root);
cout<<endl;
int k;
cout<<"enter the element which you want to delete"<<endl;;
cin>>k;
delete_tree(&root,k);
cout<<"after deletion"<<endl;
cout<<"Inorder Traversal"<<endl;
    inOrder(root);
cout<<endl;
cout<<"Preorder Traversal: "<<endl;
preOrder(root);
cout<<endl;
cout<<"Postorder Traversal "<<endl;
postOrder(root);
cout<<endl;
return 0;
}

struct node* insert(struct node* r, int data)
{
if(r==NULL)
{
r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}
void delete_tree(struct node **ptr,int item)

{
struct node *move,*back,*temp;
if(*ptr==NULL)
{cout<<"empty tree"<<endl;
return;
}
else
{
move=*ptr;
back=move;
while(move->value!=item)
{back=move;
if(item<move->value)
{
 move=move->left;
}
 else
{move=move->right;
}
}
if(move->left!=NULL&&move->right!=NULL)
{temp=move->right;
while(temp->left!=NULL)
{back=temp;
temp=temp->left;
}
move->value=temp->value;
move=temp;
}
if(move->left==NULL&&move->right==NULL)
{
if(back->right==move)
{back->right=NULL;
}
else
{
back->left=NULL;
}
free(move);
return;
}
if(move->left==NULL&&move->right!=NULL)
{if(back->left==move)
{back->left=move->right;
}
else
{
back->right=move->right;
}
free(move);
return;
}
if(move->left!=NULL&&move->right==NULL)
 {
if(back->left==move)
{
back->left=move->left;
}
else
{
back->right=move->left;
}
free(move);
return;

}
}
}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
		cout<< (r->value);cout<<endl;
		inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
       cout<< r->value;
       cout<<endl;
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
     cout<< r->value;cout<<endl;

    }
}

                            
