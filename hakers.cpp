#include<bits/stdc++.h>

#define LOL 1000006

using namespace std;

typedef pair<int,int> pii;

int n, mak, poz, f, sum;
int kom[LOL], tab1[LOL];

deque <pii> kol;

void add (int a, int b)
{
//	cerr << "add():"<< a << " " << b << endl;
	
	while( !kol.empty()&&kol.back().first<a)
	{
		kol.pop_back();
	}
	
	kol.push_back(make_pair(a,b));
}

void rem ( int c)
{
	if(kol.front().second==c) kol.pop_front();
}

int main()
{
	scanf("%d", &n);
	f=n/2+n%2;
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &kom[i]);
		
		sum+=kom[i];
	}
	
	
	
	for(int i=0; i<n/2; ++i)
	{
		tab1[0]+=kom[i];
	}
	
	for(int i=1; i<n; ++i)
	{
		int a=i+n/2-1;
		if(a>=n) a=a%n;
		
		tab1[i]=tab1[i-1]-kom[i-1]+kom[a];
	}
	
	
		for(int i=0; i<(n/2+n%2); ++i)
	{
		add(tab1[i], i); 
		
	}
	
	mak=kol.front().first;
	poz=0;
	
	for(int i=1; i<n; ++i)
	{
		int a=i+f-1;
		if(a>=n) a=a%n;
		
		add(tab1[a], a);
		
		rem(i-1);
		
//		cerr << "i:" << i << " " << "mak:" << mak << "p:" << kol.front().first << "k:" << kol.back().first << endl;
		
		if(mak>kol.front().first)
		{
			mak=kol.front().first;
			poz=i;
		}
	}
	
	int wyn=0;
	
	
	
	if(poz==0) wyn=n-1;
	else wyn=poz-1;
	
	printf("%d", sum-mak);
	
}
