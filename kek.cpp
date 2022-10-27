#include <cstdio>
#include <algorithm>
#define LOL 1005

using namespace std;

int t[LOL][LOL];

int main() 
{
	int n;
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
	{
		for(int k=1; k<=n;k++)
		{
			int a;
			
			scanf("%d",&a);
			
			t[i][k]=a;
		}
	}
	
	for(int i=(n-1); i>0; i--)
	{
			t[n][i]+=t[n][i+1];
			t[i][n]+=t[i+1][n];
	}
	
	for(int i=(n-1); i>0; i--)
	{
		for(int k=(n-1); k>0; k--)
		{
			if ((i+k)%2==0) t[i][k]+=max(t[i+1][k], t[i][k+1]);
			
			else t[i][k]+=min(t[i+1][k], t[i][k+1]);
		}
	}
	 /*
	for(int i=1; i<=n; ++i)
	{
		for(int k=1; k<=n; ++k)
		{
			printf("%d ", t[i][k]);
		}
		 printf("\n");
	}
	*/
	int wyn = t[1][1];
	
	printf("%d", wyn);
}

