#include <stdio.h>

int main(void)
{
	int i,j,key,a[10];
	
	printf("Enter the elements in a[10]:\n");	
	for(i=0;i<10;i++)
	{
		scanf(" %d",&a[i]);
	}
	
	for(i=1;i<10;i++)                                        
	{
		key=a[i];
		for(j=i-1;j>=0 && key<=a[j];j--)
		{
		a[j+1]=a[j];
		}
		a[j+1]=key;
	}

	printf("\n\nThe sorted array a[10]:\n");	
	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
