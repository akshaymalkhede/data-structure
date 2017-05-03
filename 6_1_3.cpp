#include<iostream>
#include<iomanip>
using namespace std;

void bubble_sort(int a[],int n)
{
int temp;
{
for(int i=0;i<n;i++)
{for(int j=0;j<n-i-1;j++)

{if(a[j]>a[j+1])
{temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
cout<<"bubble sort"<<endl;
for(int i=0;i<n;i++)
{ cout<<setw(3)<<a[i];
}
}
int main()
{
int n;
cout<<"enter the no of element"<<endl;
cin>>n;
int a[n]; int temp;
cout<<"enter the element"<<endl;
for(int i=0;i<n;i++){
cout<<"data "<<i+1<<"  ";
cin>>a[i];
}
bubble_sort(a,n);
}

