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
void insertdata(list *p)
	{int key,data;
	cout<<"enter key"<<endl;
	cin>>key;
	cout<<"enter data"<<endl;
	cin>>data;
list *pp=NULL;
	list *q=new list;
	q->no=data;
	while(p!=NULL)
	{if(p->no==key)
	{cout<<"key present"<<endl;
	cout<<"pre pointer"<<pp<<endl;
	cout<<"key pointer "<<p<<endl;
	list* temp= pp->next;
	pp->next= q;
	pp->next->next= temp;
	}
	pp=p;
	p=p->next;
	}
	cout<<"key absent"<<endl;
	}
int main()
{
list *p=new list;
create(p);
print(p);
insertdata(p)
;print(p);
return 0;
}

