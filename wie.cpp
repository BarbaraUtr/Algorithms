#include <cstdio>
#include<math.h>
#include<algorithm>
#include <vector>

#define LOL 1000005

using namespace std;

int sum[LOL];
int licz[LOL];

int main()
{
	int n, k;
	int wyn=0;
	
	scanf("%d%d", &n, &k);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &licz[i]);
	}
	
	sum[1]=licz[0];
	
	for(int i=1; i<=n; i++)
	{
		sum[i]=sum[i-1]+licz[i-1];
		sum[i]%=k;
	}
	
	sort(sum, sum+(n+1));
	
       for(int i = 0; i <= n; ++i) 
	   {
	        int e = sum[i];
	        int ile = 1;
	        
	        while(i+1 <= n && sum[i+1] == e) 
			{
	            ile++;
	            i++;
	    	}
	    	
	        wyn+=ile*(ile-1)/2;
    	}
	
	/*
		for(int i=0; i<n; i++)
	{
		printf("%d ", licz[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		printf("%d ", sum[i]);
	}
	*/
	
	
	/*
	
	

	
	for(int i=0; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{	
			int fu=sum[j]-sum[i];
			
			if(fu%k==0) wyn++;
			
//			printf("%d ", fu);
		}
//		printf("\n");
	}
	*/
	printf("%d", wyn); 
	
//	*/
}
