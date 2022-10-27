#include <cstdio>
#include <algorithm>
//#include <bits\stdc++.h>

#define KEK 100000
#define LOL 262144

using namespace std;

int drzewo[LOL];

int maksy (int x, int y) //maks na przedziale
{
	int wyn=0;
		
	int first=x-1, last=y+1; // zanczniki
	
	while(last-first!=1) 
	{
		if(first%2==0) 
		{
			if(wyn < drzewo[first+1]) wyn=drzewo[first+1];
		}
		
		if(last%2==1)
		{
			if(wyn < drzewo[last-1]) wyn=drzewo[last-1];
		}
		first/=2;
		last/=2;
	}
	
	return wyn;
}

int main () 
{
	int n, k;
	int dwa=1;
	
	scanf("%d", &n);
	scanf("%d", &k);
		
	while(dwa<=n)
	{
		dwa*=2;
	}
	
	dwa*=2;
		
	for(int i=0; i<n; i++)
	{
		scanf("%d", &drzewo[i+dwa/2]);
	}
	
	
	for(int i=dwa/2-1; i>0; i--)
	{
		drzewo[i]=max(drzewo[2*i], drzewo[2*i+1]);
	}
	/*
	for(int i=1; i<dwa; i++)
	{
		printf("%d ", drzewo[i]);
	}
	*/
//	int p=maksy(9, 11);
//	printf("%d", dwa);
	 
	int m = maksy((1+dwa/2),(k+dwa/2));
//	int m=maksy(18,21);
	
	printf("%d ", m);
//	/*
	for(int i=1; i<n; i++)
	{	
		int po=dwa/2+1+i, ko=dwa/2+k+i;
		
		if(ko>=(dwa/2+n)) ko=dwa/2+n;
		
		if(drzewo[po-1]==m) m=maksy(po, ko);
		if(drzewo[ko]>m) m=maksy(po, ko);
		
		if(i==n-1) printf("0");
		else printf("%d ", m);
	}
	
//	*/
}

