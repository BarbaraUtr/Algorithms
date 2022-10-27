#include<bits/stdc++.h>

#define LOL 1000006

using namespace std;

int n, m;
int wk[LOL];

int main()
{
	scanf("%d%d", n, m);
	
	int c;
	
	for(int i=0; i<n; ++i)
	{
		int a, v;
		scanf("%d%d", v, a);
		
		if(a>v) wk[i]=0;
		else 
		{
			c=v%a;
			if(a*c==v) wk[i]=c-1;
			else wk[i]=c;
		}
	}
	
	
}
