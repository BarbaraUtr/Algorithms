#include<bits/stdc++.h>

#define LOL 1003
#define XD 102

bool jakie[LOL][LOL];

pair<int, int> prze[LOL];

int pocz[LOL], kon[LOL];

int zero=0;

int main ()
{
	int n;
	
	for(int i=1; i<=n; ++i)
	{
		int a,b;
		
		scanf("%d%d", &a, &b);
		
		pocz[i]=b-a;
		kon[i]=b+a;
	}
	
	for(int i=1; i<=n; ++i)
	{
		prze[i].second=i;
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int k=i; k<=n; ++i)
		{
			if(pocz[i]<pocz[k]&&kon[i]<kon[k])
			{
				prze[i].first++;
				jakie[i][k]=true;
				jakie[k][k]=true;
			}
		}
	}
	
	sort(prze, prze+n);
	
	
}
