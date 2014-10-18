#include<stdio.h>
void merge(int [],int ,int ,int );
void partition(int [],int ,int );

int main()
{
	int a[5];
	int i,size;
	printf("Enter elements in a[5]:\n");
	for(i=0; i<5; i++)
    {
        scanf("%d",&a[i]);
 	}
	partition(a,0,5);
 	printf("The sorted array a[5] is: ");
 	for(i=0; i<5; i++)
	{ 
		printf("%d ",a[i]);
	} 
	return 0;
}


void partition(int a[],int min,int max)
{
	int mid;
	if(min<max)
	{
    	mid=(min+max)/2;
    	partition(a,min,mid);
    	partition(a,mid+1,max);
    	merge(a,min,mid,max);
    }
}   


void merge(int a[],int min,int mid,int max)
{
	int temp[5];
  	int i,j,k,m; 
  	j=min;
  	m=mid+1;
  	i=min;
  	while(j<=mid && m<=max)
  	{
    	if(a[j]<=a[m])
     	{
	 		temp[i]=a[j];
	 		j++;
     	}
     	else
     	{
	 		temp[i]=a[m];
	 		m++;
     	}
     	i++;
  	}
  	if(j>mid)
  	{
   		for(k=m; k<=max; k++)
   	    {
	 		temp[i]=a[k];
	 		i++;
    	}
  	}
  	else
  	{
    	for(k=j; k<=mid; k++)
     	{
			temp[i]=a[k];
			i++;
     	}
  	}
  	for(k=min; k<=max; k++)
	{
    	a[k]=temp[k];
	}
}
