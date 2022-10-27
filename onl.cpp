#include <cstdio>
#include <math.h>
#include <algorithm>

#define LOL 500005
#define XD 2097152

using namespace std;

int ab[XD];
int dwa=1;

void zmiana(int x, int y)
{
	x+=dwa/2;
	ab[x]=y;
	
	x/=2;
	
	if(ab[2*x]<ab[2*x+1]) ab[x]=1;
	else ab[x]=0;
	
	while(x>0)
	{
		x/=2;
		
		if(ab[2*x]&&ab[2*x+1]) ab[x]=1;
		else ab[x]=0;
	}
}

int main ()
{
	int n;
	
	scanf("%d", &n);
	
	while(dwa<n)
	{
		dwa*=2;
	}
	dwa*=4;
	
//	printf("%d", dwa);
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &ab[dwa/2+i]);
	}
	
	for(int i=dwa/2-1; i>dwa/4-1; --i)
	{
		if(ab[2*i]<ab[2*i+1]) ab[i]=1;
	}
	
	for(int i=dwa/4-1; i>0; --i)
	{
		if(ab[2*i]&&ab[2*i+1]) ab[i]=1;
	}
	
	int ty=1;
	
	while(ab[ty]!=1)
	{
		ty++;
		
		if(ty>dwa/2) break;
	}
	
	
}
