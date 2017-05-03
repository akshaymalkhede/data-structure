#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
struct list
{int no;
list *next;
};
list* getnode(){
		static int node_no=1;
		list* new_node;
		new_node=(list*)malloc(sizeof(list));
			if(new_node==NULL){
				cout<<" No memeory space for the node no 5d"<<node_no+1;
		
			}
			else{
				node_no+=1;
				return(new_node);
			}
			return(0);}
void create(list* p)
{
cout<<"enter the (-99) at end";
cin>>p->no;
if(p->no==-99)
{p->next=NULL;
}
else
{p->next=new list;
create(p->next);
}
}void print(list* p)
{cout<<"linked list";
while(p->next!=NULL){

cout<<setw(3)<<p->no;
p=p->next;
}}int count(list* p)
{int l = 0;
while(p->next!=NULL)
{l++;
p=p->next;
}
cout<<"no of node"<<l;
return(l);
}
void insertdata(list *p,int key,int data){
	if(p==NULL && p->next==NULL)
        cout<<"empty list";
	list *newnode=getnode();
	newnode->no=data;
	list *ptr=p->next;
	while(ptr->no!=key && ptr->next!=NULL){
			ptr=ptr->next;
		}
	
	if(ptr->no!=key)
	{
		
		cout<<"key absent";
		return;
	}	
	if(ptr->next!=NULL)
	{
	list *temp=ptr->next;
	ptr->next=newnode;
	ptr->next->next=temp;		
	}
	else
	{
		ptr->next=newnode;
		ptr->next->next=NULL;
	}
			
}


int main()
{
list *p=new list;
create(p);
print(p);int key,data;
cout<<"key"<<endl;
cin>>key;
cout<<"data"<<endl;
cin>>data;
insertdata(p,key,data)
;print(p);
return 0;
}

