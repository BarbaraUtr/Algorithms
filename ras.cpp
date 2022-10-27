#include<bits/stdc++.h>

#define LOL 1003

using namespace std;

int la[LOL];

int main ()
{
	int n, m, k, t, wyn=0;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &la[i]);
		
		if(i==0)
		{
			if((la[i]-k)>1)
			{
				wyn++;
				wyn+=(la[i]-k-1)/(2*k+1);
				
//				printf("a\n");
			}
			
		}
		
		else
		{
			if((la[i-1]+k+1)<(la[i]-k))
			{
				wyn++;
				wyn+=((la[i]-k)-(la[i-1]+k))/(2*k+1);
				
//				printf("b\n");
			}
			
		}
	}
	
	if(la[m-1]+k<n)
	{
		wyn++;
		wyn+=(n-(la[m-1]+k))/(2*k+1);
		
//		printf("c\n");
	}
	
	printf("%d", wyn);
}
