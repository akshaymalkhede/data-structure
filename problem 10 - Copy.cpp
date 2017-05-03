#include<conio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
struct dnode
{
  int data;
  struct dnode *p,*n;
};
  typedef struct dnode dnode;
  dnode *start,*last;
  
  dnode *createNode(int ele)
  {
   dnode *nnode;
   nnode=(dnode*)malloc(sizeof(dnode));
   nnode->n=NULL;
   nnode->data=ele;
   return nnode;
  }
   dnode *insertBegining(int ele)
   {
    dnode *nnode,*curr,*prev;
    nnode=createNode(ele);
    if(start==NULL)
    {
     start=nnode;
     nnode->p=NULL;
     return start;
    }
    curr=start;
    start=nnode;
    nnode->p=NULL;
    nnode->n=curr;
    curr->p=nnode;
    return start;
   }
  dnode *insertLast(int ele)
  {
   dnode *nnode,*curr,*prev;
   nnode=createNode(ele);
   if(start==NULL)
   {
    start=nnode;
    nnode->p=NULL;
    return start;
   }
  curr=start;
  while(curr!=NULL)
  {
   prev=curr;
   curr=curr->n;
  }
 prev->n=nnode;
 nnode->p=prev;
 return start;
}
void display()
{
 dnode *curr;
 curr=start;
 while(curr!=NULL)
 {
  cout<<"--->"<<curr->data;
  curr=curr->n;
 }
}
 int main()
 {
  int ch,ele;
  
  do
  {
   cout<<"Enter choice"<<endl;
   cout<<"1-insert beginning"<<endl;
   cout<<"2-insert last"<<endl;
 cout<<"3-display"<<endl;
   cout<<"4-Exit"<<endl;
   cin>>ch;
   switch(ch)
   {
    case 1:
    cout<<"Enter Number";
    cin>>ele;
    insertBegining(ele);
    break;
    case 2:
    cout<<"enter number";
    cin>>ele;
    insertLast(ele);
    break;
    case 3:
    display();
    break;
   }
  }
  while(ch!=4);
  getch();
  }
