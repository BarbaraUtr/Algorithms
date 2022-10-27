#include <bits/stdc++.h>
#include<queue>

#define LOL 100005
#define XD 1000000009

using namespace std;

int n, f, mi=XD;
int cyf[LOL];

bool tak[LOL];

queue<int> my;
queue<int> my2;
queue<int> notmy;

int main ()
{

	scanf("%d%d", &n, &f);
	for(int i=0; i<n; ++i)
	{
		int d;
		
		scanf("%d", &d);
		cyf[i]=d;
		
		if(d<mi) mi=d;
		
	}
	
	for(int i=0; i<n; ++i)
	{
		if(cyf[i]==mi) tak[i]=1;
		my.push(i);
	}
	
	for(int i= 0; i<n; ++i)
	{
		mi2=XD;
		
		for(int g=0; g<my.size(); ++g)
		{
			int a=my.front();
			
			 	
			
		}
		
	}
	
}
