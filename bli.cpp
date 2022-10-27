#include <cstdio>
#include<math.h>
#include<algorithm>
#include <vector>

#define LOL 1000005
#define WTF 1003

using namespace std;

bool pri[LOL];

void sito (int n)
{
	for(int i=2; i<n; ++i)
	{
		pri[i]=true;
	}
//	/*
	for(int i=2; i<n; ++i)
	{
		if(pri[i]==false) continue;
		
		int x=pow(i,2);
		
		while(x<n)
		{
			pri[x]=false;
			x+=i;
		}
	}
//	*/
}

int main ()
{
	int n;
	
	scanf("%d", &n);
	
	sito(WTF);
	/*
	for(int i=0; i<WTF; ++i)
	{
		printf("%d\n", pri[i]);
	}
	*/
//	/*
	for(int i=0; i<n; ++i)
	{
		int p, d;
		
		scanf("%d%d", &p, &d);
		if(d>p) swap(p,d);
		
		if(p-d!=2) printf("NIE\n");
		else
		{
			int f=sqrt(p);
			for(int k=2; k<f+1; ++k)
			{
				if(pri[k])
				{
					if(p%k==0) 
					{
						printf("NIE\n");
						
						break;
					}
					
					if(d%k==0)
					{
						printf("NIE\n");
						
						break;
					}
				}
				if(k==f) printf("TAK\n");
			}
		}
	}
//	*/
}
