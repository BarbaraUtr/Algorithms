#include<bits/stdc++.h>

#define LOL 100005

using namespace std;

long int ta[LOL];

int main ()
{
	int n, li=0, op;
	long long int wyn=0;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; ++i)
	{
		scanf("%ld", &ta[i]);
	}
	
	sort(ta, ta+n);
	
	for(int i=0; i<n; ++i)
	{
		printf("%d: %ld  ", i, ta[i]);
	}
	
	wyn+=ta[n-1];
	
	for(int i=(n-2); i>=0; --i)
	{
		li=0;
		while(ta[i]==ta[i+1])
		{	
			li++;
			wyn+=ta[i];
			i--;
		}
		
		i-=li;
		
		if(i<=0) break;
		
		i--;
		wyn+=ta[i];
	}
	
	printf("%lld", wyn);
} 
