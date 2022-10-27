#include <bits\stdc++.h>

#define LOL 10000000000

using namespace std;

int fib[LOL];

int main()
{
	long long int d, li;
	int k;
	
	scanf("%lld%d", &d, &k);
	
	li=k-1;
	
	int naj=0, suma=0;
	
	for(int i=0; i<k-1; i++)
	{
		fib[i]=1;
		suma+=fib[i];
	}
	
	while(naj<=d)
	{
		fib[li]=suma;
		
		suma+=fib[li];
		suma-=fib[li-k+1];
		
		naj=fib[li];
		
		li++;
	}
	int wyn=li-1;
	printf("%d", wyn);
}
