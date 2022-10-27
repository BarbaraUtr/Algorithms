#include<cstdio>

#define LOL 2002

long long x[LOL],y[LOL];
int t[LOL];

int n, x0, y0;

bool cmp(int i1,int i2)
{
	return (x[i1]-x0)(y[i2]-y0)-(x[i2]-y0)*(y[i1]-y0)<0;
	
}

int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		t[i]=i;
	}
	
	sort(t,t+n,cmp);
	
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			if(y[k]<y[i]) 
		}
	}
}
