#include<stdio.h>
#include<stdlib.h>
int main()
{
int d[100],kin[20],pin[20],temp,k,i,j=0,n,n1=0,start,end;

printf("Enter the number of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&d[i]);
printf("Enter the number to be searched:");
scanf("%d",&k);
for(i=0;i<n;i+=3)
{
kin[n1]=d[i];
pin[n1]=i;
n1++;
}
if(k < kin[0])
{
printf("element not found");
exit(0);
}
else
{
for(i=1;i<=n1;i++)
if(k < kin[i] )
{
start=pin[i-1];
end=pin[i];
break;
}
}
for(i=start;i<=end;i++)
{
if(k==d[i])
{
j=1;
break;
}
}
if(j==1)
printf("element found at position %d",i);
else
printf("element not found");
}

 
