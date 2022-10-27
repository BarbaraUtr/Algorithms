#include<bits/stdc++.h>

#define LOL 100005
#define DW 262144
#define NU 1000000009

using namespace std;

int n, k, q, dwa=1, li=0;

long int wyn=0;

int x[LOL];

//;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; ;-; 

int t1[LOL], a1[LOL], b1[LOL], c1[LOL];	

long int tr1[DW], tr0[DW];

int pz[DW], kz[DW];

int poziom(int x)
{
	int d=1, l=0;
	
	while(d<x)
	{
		d*=2;
		l++;
	}
	return l;
}

void zmiana(int x)
{
	while(x!=1)
	{
		x/=2;
		tr1[x]=tr1[2*x+1]+tr1[2*x];
	}
}

void dodawanie(int x, int a, int b)
{
	if(pz[x]>a && kz[x]<b)
	{
		tr1[x]=pow(2,(poziom(x)-1))-tr1[x];
		zmiana(x);
	}
	
	if(pz[x]<a&&kz[x]<b)
	{
		dodawanie(2*x,a,b);
		dodawanie(2*x+1, a, b);
	}
	
	if(pz[x]>a&&kz[x]>b)
	{
		dodawanie(2*x,a,b);
		dodawanie(2*x+1, a, b);
	}
}

void jedynka (int x, int a, int b) // zerowac wynik
{
	if(pz[x]>a && kz[x]<b)
	{
		wyn+=tr1[x];
	}
	
	if(pz[x]<a&&kz[x]<b)
	{
		jedynka(2*x,a,b);
		jedynka(2*x+1, a, b);
	}
	
	if(pz[x]>a&&kz[x]>b)
	{
		jedynka(2*x,a,b);
		jedynka(2*x+1, a, b);
	}
}

void zaznaczenie(int x) 
{
	if(x>dwa/2)
	{
		pz[x]=x;
		kz[x]=x;
	}
	
	else
	{
		pz[2*x]=pz[x];
		kz[2*x]=(kz[x]/2);
		
		pz[2*x+1]=(kz[x]/2)+1;
		kz[2*x+1]=kz[x];
	}
}

void uzupelnienie(int x)
{
	for(int i=x; i>0; --i)
	{
		tr1[i]=tr1[2*i]+tr1[2*i+1];
	}
}

int main ()
{
	
	long long int odp=0; 
	int z=0;
	
	scanf("%d%d%d", &n, &k, &q);

	while(dwa<=n)
	{
		li++;
		dwa*=2;
	}
	dwa*=2;
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &x[i]);
		
		tr1[dwa+i]=x[i];
	}
	
	for(int i=0; i<q; ++i)
	{
		scanf("%d%d%d%d", &t1[i], &a1[i], &b1[i], &c1[i]);
		a1[i]--;
		b1[i]--;
	}
	
	zaznaczenie(1);
	uzupelnienie(dwa/2-1);
	
	for(int i=0; i<q; ++i)
	{
		if(t1[i]==1&&c1[i]==1)
		{
			dodawanie(1, a1[i], b1[i]);
		}
		if(t1[i]==2)
		{
			jedynka(1, a1[i], b1[i]);
			
			if(c1[i]==1)
			{
				wyn-=1;
				odp=wyn*(wyn-1)/2;
				odp%=NU;
				
				z=b1[i]-a1[i]-wyn;
				int li2=0;
				while(li<z)
				{
					odp*=2;
					odp%=NU;
				}
				odp++;
				wyn=0;
				printf("%d", odp);
			}
			
			else
			{
				odp=wyn*(wyn-1)/2;
				odp%=NU;
				
				z=b1[i]-a1[i]-wyn;
				int li2=0;
				while(li<z)
				{
					odp*=2;
					odp%=NU;
				}
				wyn=0;
				odp++;
				printf("%d", odp);
			}
		}
	}
}
