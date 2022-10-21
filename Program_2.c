#include<stdio.h>
#include<stdlib.h>
int isFull(int *a, int *pn) 
{
	return ((*pn) == 100);
}

int isEmpty(int *a, int *pn) 
{
	return ((*pn) == 0);
}

void add_value(int value, int *a,int *pn)
{
	a[*pn]= value;
	(*pn) ++;
}

int search_value(int value, int *a,int*pn)
{
	int num=0;
	for(int i=0;i<(*pn);i++)
	{
		if (a[i]==value) num++;
	}
	return num;
}

void print_array(int *a,int *pn)
{
	for(int i=0;i<(*pn);i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}

void print_array_range(int *a, int *pn)
{
	int minVal, maxVal, i;
	printf("minVal = ");
	scanf("%d", &minVal);
	printf("maxVal = ");
	scanf("%d", &maxVal);
	for (i = 0; i < (*pn); i++)
		if (a[i] >= minVal && a[i] <= maxVal) printf("%3d",a[i]);
	printf("\n");
}

void print_ascending(int *clone, int *n)
{
	int i,j,c;
	for (i = 0 ; i < (*n) - 1 ; i++)
		{
			c = i;
			for (j = i + 1 ; j < (*n); j++)
				if (clone[c] > clone[j])  c = j;
			if ( c > i)
			{
				j = clone[c];
				clone[c] = clone[i];
				clone[i] = j;
			}
		}
	printf("\n");
}
int getUserChoice()
{
	int choice;
		printf("=====Array=====\n");
		printf("1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Print out the array\n");
		printf("4- Print out value in a range\n");
		printf("5- Print out the array in ascending order\n");
		printf("Others- Quit\n");
		printf("Select: \n");
		fflush(stdin);
		scanf("%d",&choice);
	return choice;
}

int main()
{
	int choice;
	int n = 0, value;
	int *a, *clone;
	a = calloc ( n+1 ,sizeof(int) );
	do 
	{
		a = (int*)realloc(a,n+1);
		choice = getUserChoice();
		switch (choice)
		{
		case 1: 
			if (isFull(a, &n)) printf("Array is full\n\n");
				else 
					{	
						printf("Input an added value: ");
						scanf("%d", &value);
						add_value(value, a, &n);
						printf("Added\n");
					}
			break;
		case 2:
			if (isEmpty(a, &n)) printf("Array is empty\n\n");
				else
					{
						printf("Input the searched value : ");
						scanf("%*c%d", &value);
						printf("There are %d number!\n",search_value(value,a,&n));
					}
			break;
		case 3:
			if (isEmpty(a, &n)) printf("Array is empty\n\n");
			else print_array(a,&n);
			break;
		case 4:
			if (isEmpty(a, &n)) printf("Array is empty\n\n");
			else print_array_range(a,&n);
			break;
		case 5:
			if (isEmpty(a, &n)) printf("Array is empty\n\n");
			else 
			{				
			clone = calloc ( n+1 ,sizeof(int) );
			for(int i=0;i<n;i++) clone[i] = a[i];
			print_ascending(clone,&n);
			for(int i=0;i<n;i++) printf("%3d",clone[i]);
			}
			printf("\n");
			break;
		default:
			free(a);free(clone);
			printf("You choose quit, good bye");
		} 
	}while(choice>0&&choice<6);
	return 0;
}