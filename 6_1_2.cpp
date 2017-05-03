#include<iostream>
#include<iomanip>
using namespace std;
void selection(int a[],int n)
{
for(int i=0;i<n;i++)
{
int pos=i;
for(int j=i;j<n;j++)
{
if(a[j]<a[pos])
pos=j;
}
int temp=a[pos];
a[pos]=a[i];
a[i]=temp;
	}

}

int main()
{
int n;
cout<<"enter the no of element"<<endl;
cin>>n;
int a[n]; 
cout<<"enter the element"<<endl;
for(int i=0;i<n;i++)
{
cout<<"data "<<i+1<<"  ";
cin>>a[i];}
selection(a,n);
cout<<"selection sort"<<endl;
for(int i=0;i<n;i++)
{cout<<setw(3)<<a[i];
}}








