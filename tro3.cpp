#include<cstdio>
#include<algorithm>
#include<cmath>

#define LOL 550000000

using namespace std;

int main()
{
	
	int n, wyn=0, naj=0;
	
	scanf("%d", &n);
	
	int tym=0;
	
	double k;
	
	for(int i=0; i<n; ++i)
	{
		int a, b, c, d;
		
		scanf("%d%d%d", &a, &b, &c);
		
		if(b>a&&b>c) 
		{
			k=sqrt(c*c+a*a);
			
			if(k==b)
			{
				printf("%d %d %d\n", a, b ,c);
			}	
		}
		if(c>a&&c>b)
		{
			k=sqrt(a*a+b*b);
			
			if(k==c)
			{
				printf("%d %d %d\n", a, b ,c);
			}
		}
		else
		{
			k=sqrt(c*c+b*b);
			
			if(k==a)
			{
				printf("%d %d %d\n", a, b ,c);
			}
		}
	}
}
