#include <cstdio>
#include <algorithm>
#include <iostream>
#define For(i,s,a) for(int i=s;i<a;++i)
#define LOL 1000000

using namespace std;

pair <int, int> dzie[LOL];
pair <int, int> zap[LOL];

int t[LOL];

int main() 
{
	int n, m;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &dzie[i+1].second);
		
		dzie[i+1].first=i+1;
	}
	
	scanf("%d", &m);
	
	for(int i=0; i<m; i++)
	{
		scanf("%d%d", &zap[i].first, &zap[i].second);
	}
	
	int f=-69, l=0, x;
	//For(i,0,n)cout<<dzie[i].first<<" xd "<<dzie[i].second<<endl;
	
	for(int i=1; i<=n; i++)
	{
		++l;
		//getchar();
		
		if(t[i]!=0)
		continue;
				
		else 
		{	//x=i;
		
			t[i]=l;
			f=dzie[i].second;
			while(f!=i)
			{
	//			getchar();
				t[f]=l;
				
//				printf("%d %d\n", f,dzie[f].second);
			
				f=dzie[f].second;
				//f=dzie[i].first;	
			}
		}
	}
	/* 
	for(int i=1; i<=n; i++)
	{
		printf("%d ", t[i]);
	}
	 */
	 ///*
	for(int i=0; i<m; i++)
	{
		int a=zap[i].first, b=zap[i].second;
		
		if(t[a]==t[b]) printf("TAK \n");
		
		else printf("NIE \n");
	} 
	 //*/
}

