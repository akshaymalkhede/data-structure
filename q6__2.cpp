#include<iostream>
using namespace std;
void sequential_search(int array[], int size, int n)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == n)
        {
            cout<<n<<" found at location "<< i+1 <<endl ;
            break;
        }
    }
    if (i == size)
      cout<<" not present in the list" <<n<<endl;
}

void binary_search(int array[], int size, int n)
{
    int i, first, last, middle;
    first = 0;
    last = size - 1;
    middle = (first+last) / 2;
 
    while (first <= last) {
        if (array[middle] < n)
            first = middle + 1;
        else if (array[middle] == n) {
          cout<<n<<" found at location "<<"  "<< middle+1<<endl;
           break;
        }
        else
            last = middle - 1;
 
        middle = (first + last) / 2;
    }
    if ( first > last )
 cout<<n<<" is not present in the list  "<<endl;
}
void indexed_sequential_search(int array[],int size,int n)
{
	int kin[20],pin[20],temp,i,j=0,n1=0,start,end;
for(i=0;i<size;i+=3)
{
kin[n1]=array[i];
pin[n1]=i;
n1++;
}
if(n < kin[0])
{
cout<<n<<" not found"<<endl;
exit(0);
}
else
{
for(i=1;i<=n1;i++)
if(n < kin[i] )
{
start=pin[i-1];
end=pin[i];
break;
}
}
for(i=start;i<=end;i++)
{
if(n==array[i])
{
j=1;
break;
}
}
if(j==1)
cout<<n<<" found at position "<<i+1<<" ";
else
cout<<n<<"  not found"<<endl;
}

 

int main()
{
    int a[200], i, j, n, size;
    cout<<"Enter the size of the list:"<<endl;
    cin>>size;
    cout<<"Enter "<<size<<" Integers in ascending order";
    for (i = 0; i < size; i++)
        cin>> a[i];
  cout<<"Enter value to find"<<endl;
   cin>>n;
   cout<<"Sequential search"<<endl;
    sequential_search(a, size, n);
cout<<"Binary search"<<endl;
    binary_search(a, size, n);
    cout<<"indexed sequential search"<<endl;
    indexed_sequential_search(a,size,n);
    
    return 0;
}


