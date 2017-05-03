#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std ;
struct node
{int num;
    struct node *next;
};
 
void create(struct node **);
void display(struct node *);
int survivor(struct node **, int);
 
int main()
{
    struct node *head = NULL;
    int survive, skip;
 
    create(&head);
    cout<<"The persons in circular list are"<<endl;
    display(head);
    cout<<"Enter the number of persons to be skipped "<<endl;
    cin>>skip;
   survive = survivor(&head, skip);
    cout<<"The person to survive is"<< survive;
    return 0;
}
 
int survivor(struct node **head, int skip)
{struct node *p, *q;
int i;
 q = p = *head;
while (p->next != p)
 {for (i = 0; i < skip - 1;i++)
        {q = p;
        p = p->next;
        }
        q->next = p->next;
      cout<<" has been killed"<<p->num<<endl;
        p = q->next;
    }
    *head = p;
 
    return (p->num);
}
 
void create (struct node **head)
{struct node *temp, *rear;
    int a, ch;
do
{cout<<"Enter a number "<<endl;
cin>>a;
temp = (struct node *)malloc(sizeof(struct node));
temp->num = a;
  temp->next = NULL;
  if (*head == NULL)
        {
        *head = temp;
        }
        else
        {
        rear->next = temp;
        }
        rear = temp;
 cout<<"Do you want to add a number [1/0]";
   cin>> ch;
    } while (ch != 0);
    rear->next = *head;
}
 
void display(struct node *head)
{
    struct node *temp;
 temp = head;
    cout<<setw(3)<<temp->num;
    temp = temp->next;
    while (head != temp)
    {
   cout<<setw(3)<<temp->num;
        temp = temp->next;
    }
    cout<<endl;
}


