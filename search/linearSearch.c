#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[10],i,key,flag=0;
	printf("Enter the elements in the array a[10].\n");
	for (i=0;i<10;i++)
	{
		scanf(" %d",&a[i]);
	}

	printf("Enter the key to be searched: ");
	scanf(" %d",&key);

	for (i=0;i<10;i++)
	{
		if(a[i]==key)
		{
			printf("The key was found at %d index.\n",i);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{	
		printf("The key wasn't found.\n");
	}
	return 0;
}