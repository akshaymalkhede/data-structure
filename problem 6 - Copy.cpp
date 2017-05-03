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
				cout<<"No memeory space left for the node no 5d"<<node_no+1;
				exit(1);
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
void insert_data_before(list *p,int key,int data){
	if(p==NULL && p->next==NULL)
        cout<<"Linked list is empty";
	list *newnode=getnode();
	newnode->no=data;
	list *ptr=p->next;
	list *pre=p;
		while(ptr->no!=key && ptr->next!=NULL){
			pre=ptr;
			ptr=ptr->next;
		}
	if(ptr->no!=key)
	{
		
		cout<<"Key not found";
		return;
	}	
	
	list *temp=pre->next;
	pre->next=newnode;
	pre->next->next=temp;		
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
insert_data_before(p,key,data)
;print(p);
return 0;
}

