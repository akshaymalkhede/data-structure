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
list* sorting(list *p)
{
int n =count(p);
	list* head = p;
	for(int i = 0;i<n-1;i++)
	{
		list* pp = NULL;
		p =head;
		for(int j=0;j<n-1;j++)
		{
			if(p->no > p->next->no)
			{ if(pp==NULL)
				{
					  head = p->next;
					  p->next = head->next;
					  head->next =p;
					  pp = head;
				}
			  else
			    {
			    	pp->next = pp->next->next;
			    	p->next = pp->next->next;
			    	pp->next->next = p;
			    	pp = pp->next;
			    }
			}
			else {pp=p;
				p = p->next;
            }
}
}}
void sortedInsert(list *p)
{list *q=sorting(p);
list* current;list *head=p;list* newnode=getnode();int n;
cin>>n;
newnode->no=n;
if (head == NULL || head->no > newnode->no)
    {newnode->next = head;
        head = newnode;
    }
    else
    {current = head;
        while (current->next!=NULL &&
               current->next->no < newnode->no)
        {current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}



int main()
{
list *p=new list;
create(p);
print(p);sorting(p);print(p);
sortedInsert(p);
print(p);
return 0;
}

