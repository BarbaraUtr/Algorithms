#include<bits/stdc++.h>

#define LOL 102
#define XD 17

using namespace std;

int ka[LOL][XD];
int il[XD];

int main()
{
	int n, m, k, ma=0, a;
	
	scanf("%d%d", &n, &m);
	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			scanf("%d", &ka[i][j]);
			
			if(j==0) 
			{
				il[i]++;
				printf("%d: %d\n", i, j);
			}
		}
	}
	
	for(int i=0; i<m; ++i)
	{
		if(ma<il[i])
		{
			ma=il[i];
			a=i+1;
		}
		
	}
	
	printf("%d", a);
}
