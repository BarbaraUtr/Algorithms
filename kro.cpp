#include <bits/stdc++.h>

#define LOL 1000006

using namespace std;

int n, m, wol, out, ma=-1;
int a[LOL], v[LOL], wk[LOL], wki[LOL];

int krow ()
{
	int p=0, odp=0;
	
	for(int k=0; k<ma+2; ++k)
	{	
		if(p>(wki[k]-1)&&wki[k]>0)
		{
			p-=(wki[k]-1);
			odp+=wki[k];
			wki[k]=0;
			
//			printf("%d: %d p:%d\n", k, odp, p);
			continue;
		}
		if(p<=(wki[k]-1)&&wki[k]>0)
		{
			odp+=p+1;
			wki[k]-=(p+1);
			p=0;
//			printf("%d: %d p:%d\n", k, odp, p);
			continue;
		}
		if(wki[k]==0)
		{
			p++;
//			printf("%d: %d p:%d\n", k, odp, p);
			continue;
		}
	}
	return odp;
}

int main ()
{
	scanf("%d%d", &n,&m);
	for(int i=0; i<n; ++i)
	{
		int a, v, c;
		scanf("%d%d", &v, &a);
		if(a>v) wki[0]++;
		else
		{
			
			c=v/a;
//			printf("c:%d\n", c);

			if(c>n) c=n;
			if(c*a==v) 
			{
				wki[c-1]++;
				if(ma<c) ma=c;
			}
			else 
			{
				wki[c]++;
				if(ma<c-1) ma=c-1;
			}
		}
//		printf("%d\n", c);
	}
	/*
		for(int i=0; i<15; ++i)
	{
		printf("%d:%d\n", i, wki[i]);
	}
//	*/
//	printf("ma:%d\n", ma);
		
//	/*

	int kr=0;
	for(int i = 0; i<m; ++i)
	{
//		printf("i:%d\n", i);
		int loll=krow();
//		printf("lol:%d\n", loll);
		kr+=loll;
		printf("%d\n", kr);
	}
//	*/
}
