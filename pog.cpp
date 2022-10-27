#include<bits/stdc++.h>

#define AA 100005
#define LOL 131072
#define BB 17

using namespace std;

int main()
{
	int n, m, a=1, b=1, k;
	
	scanf("%d", &n);
	
	while(a<n)
	{
		a*=2;
	}
	
	if(a!=n)
	{
		a/=2;
	}
	
	m=n-a;
	
	while(b<m)
	{
		b*=2;
	}
	
	if(m!=b)
	{
		b/=2;
	}
	printf("a:%d n:%d b:%d m:%d", a, n, b, m);
//	/*
	if(n==(a*2-1))
	{
		k=a;
		
		printf("%d\n", k);
		
		for(int i=1; i<a; ++i)
		{
			printf("%d ", i);
		}
		printf("%d\n", n);
		
		for(int i=a; i<n; ++i)
		{
			printf("%d\n", i);
		}
	}

	if(a/2==b&&n!=(a*2-1))
	{
		k=n-a+2;
		
		printf("%d\n", k);
		
		for(int i=1; i<a/2; ++i)
		{
			printf("%d ", i);
		}
		printf("%d\n", a-1);
		
		for(int i=a/2; i<a-1; i++)
		{
			printf("%d ", i);
		}
		printf("%d\n", n);
		
		for(int i=a; i<n; ++i)
		{
			printf("%d\n", i);
		}
	}
	else
	{
		k=n-a+1+a/2;
		
		printf("%d\n", k);
		
		for(int i=1; i<a/2; ++i)
		{
			printf("%d ", i);
		}
		printf("%d\n", a-1);
		
		for(int i=a/2; i<a-1; i++)
		{
			printf("%d\n", i);
		}
		
		for(int i=a; i<=n; ++i)
		{
			printf("%d\n", i);
		}
	}
//	*/
}
