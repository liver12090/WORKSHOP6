#include<stdio.h>
int valid_ISBN(long long int n)
{
	int T=0;
	int C[10];
	for(int i=9; i>=0;i--)
	{
		C[i]=n%10;
		n=n/10;
	}
	for(int i=9;i>=0;i--)
	{
		C[i]=C[i]*(10-i);
		T+=C[i];
	}
	return (T%11==0);	
}
 int main()
 {
 	long long int n;
 	printf("======ISBN Validator=====\n");
 	do
 	{
 		printf("ISBN (0 to quit): \n");
 		scanf("%lld",&n);
 		if(n==0)	{printf("Have a nice day!");break;}
 		else if(n<1000000000||n>9999999999)continue;
 		if(valid_ISBN(n))	printf("This is a valid ISBN\n");
 		else printf("This is not valid ISBN\n");
 		
	}while (1);
	return 0;
 }