
#include<iostream>
#include<conio.h>
using namespace std;
int part(int low,int high,int *a)
{
     int i,h=high,l=low,p,t;  
     p=a[low];
     while(low<high)
     {
                    while(a[l]<p)
                    {
                                   l++;
                    }
                    while(a[h]>p)
                    {
                                   h--;
                    }
                    if(l<h)
                    {
                                t=a[l];
                                a[l]=a[h];
                                a[h]=t;
                    }
                    else
                    {
                        t=p;
                        p=a[l];
                        a[l]=t;
                        break;
                    }
     }
     return h;    
}

void quicksort(int l,int h,int *a)
{
  int index,i;
  if(l<h)
  {
          index=part(l,h,a);
          quicksort(l,index-1,a);
          quicksort(index+1,h,a);
  }
}

int main()
{
      int a[100],n,l,h,i;
      cout<<"Enter number of elements:";
      cin>>n;
      cout<<"Enter the elements ";
      for(i=0;i<n;i++)
      cin>>a[i];
      cout<<" Initial Array ";
      for(i=0;i<n;i++)
      {
                      cout<<a[i]<<" ";
      }   
      h=n-1;
      l=0;
      quicksort(l,h,a);
      cout<<endl;
      cout<<" After Sorting ";
      for(i=0;i<n;i++)
      {
                cout<<a[i]<<"  ";
      }
      
      return 0;
}

