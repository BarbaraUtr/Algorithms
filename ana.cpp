#include <bits\stdc++.h>

#define LOL 100005

using namespace std;

int zbr [LOL];


int main ()
{
	int t, a;
	
	scanf("%d", &t);
	
	for(int i=0; i<LOL; i++)
	{
		zbr[i]=1;
	}
	
	for (int i=0; i<t; i++)
	{
		int a;
		scanf("%d", &a);
		
		if(a)
		{
			int e, f;
			scanf("%d%d", &e, &f);
			if(zbr[e]>zbr[f])
			{
				zbr[e]+=zbr[f];
				zbr[f]=zbr[e];
			}
			else
			{
				zbr[f]+=zbr[e];
				zbr[e]=zbr[f];
			}
			
		}
		else
		{
			int k, wyn;
			scanf("%d", &k);
			
			for(int i=0; i<t; i++)
			{
				if(zbr[1]==k)
				{
					wyn++;
				}
			}
			
			wyn/=k;
			
			printf("%d", wyn);
		}
	}
}
