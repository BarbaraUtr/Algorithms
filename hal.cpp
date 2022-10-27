#include <cstdio>

#define LOL 100005

using namespace std;

int dom[LOL];
int sum[LOL];

int main ()
{
	int t, n;
	
	scanf("%d%d", &t, &n);
	
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &dom[i]);
	}
	
	sum[1]=dom[1];
	
	for(int i=2; i<=n; i++)
	{
		sum[i]=sum[i-1]+dom[i];
	}
	
	for(int i=0; i<t; i++)
	{
		int x, y;
		
		scanf("%d%d", &x, &y);
		
		int a=sum[y]-sum[x-1];
		
		printf("%d\n", a);
	}
}
