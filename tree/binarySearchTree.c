#include <stdio.h>
#include <stdlib.h>

struct binarySearchTree
{
	int data;
	struct binarySearchTree *left;
	struct binarySearchTree *right;
}*root;

struct binarySearchTree * insert(struct binarySearchTree *,int);int search(struct binarySearchTree *,int);struct binarySearchTree * createNode(int);

int main(void)
{
	int choice,menu,subMenu,dataIn,key,result=0;
	root=NULL;
	do
	{
		printf("\tMENU - Press:\n1 to insert an element\n2 to search an element\n3 to find Min/Max element in the tree\n");  //To add delete and transversal codes.
		scanf(" %d",&menu);
		switch(menu)
		{
			case 1:
				printf("Enter the data to be inserted: ");
				scanf(" %d",&dataIn);
				root=insert(root,dataIn);
			break;
			case 2:
				printf("Enter the data to be searched: ");
				scanf(" %d",&key);
				result=search(root,key);
				if(result==1)
				{
					printf("The data was found in the tree.\n");
				}
				else
				{
					printf("The data wasn't found.\n");
				}
			break;
			case 3:
				printf("Press 1 for Min,2 for Max element: ");
				scanf(" %d",&subMenu);
				if(subMenu==1)
				{
					struct binarySearchTree *temp = root;
					while(temp->left!=NULL)
					{
						temp=temp->left;
					}
					printf("The Min element is: %d\n",temp->data);
				}
				else if(subMenu==2)
				{
					struct binarySearchTree *temp = root;
					while(temp->right!=NULL)
					{
						temp=temp->right;
					}
					printf("The Max element is: %d\n",temp->data);
				}
				else
				{
					printf("Bad option provided.\n");
				}
			break;
			default:
				printf("Bad option provided.\n");
		}
		printf("Enter 1 to continue,0 to exit: ");
		scanf(" %d",&choice);
	}while(choice!=0);


	return 0;
}

struct binarySearchTree * createNode(int dataIn)
{
	struct binarySearchTree *newNode;
	newNode=(struct binarySearchTree*)malloc(sizeof(struct binarySearchTree));
	newNode->data=dataIn;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct binarySearchTree * insert(struct binarySearchTree *root,int dataIn)
{
	if(root==NULL)
	{
		root=createNode(dataIn);
	}
	else if(dataIn<=root->data)
	{
		root->left=insert(root->left,dataIn);
	}
	else if(dataIn>root->data)
	{
		root->right=insert(root->right,dataIn);
	}

	return root;
}

int search(struct binarySearchTree *root,int key)
{
	
	if(root==NULL)
	{
		return 0;
	}
	if(root->data==key)
	{
		return 1;
	}
	else if(key<root->data)
	{
		return search(root->left,key);
	}
	else if(key>root->data)
	{
		return search(root->right,key);
	}
}