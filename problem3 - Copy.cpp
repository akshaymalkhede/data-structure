#include<iostream>
#include<iomanip>

using namespace std;
struct list
{int no;
list *next;
};
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
void search(list* p)
{list* head=p;int key;
cout<<"enter key";
cin>>key;
{
    while (head != NULL)
    {
        if (head->no == key)
        {
        cout<<"key present";
        cout<<head;
            return;
        }
        head = head->next;
    }
   cout<<"key absent";
}}

int main()
{
list *p=new list;
create(p);
print(p);
search(p);
return 0;
}

