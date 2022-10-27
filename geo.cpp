#include<bits/stdc++.h>

#define LOL 100005
#define s second
#define f first

using namespace std;

typedef pair<int, int> pii;

int n;
int g, h;

///*
struct Odcx
{
	int p;
	int k;
	int y;  
};

bool operator< (Odcx a, Odcx b)
{
	if(a.y>b.y) return 0;
	if(a.y==b.y) return a.p > b.p;
	else return 1;
}

Odcx odcx[LOL];

struct Odcy;
{
	int p;
	int k;
	int x;
};

bool operator< (Odcy a, Odcy b)
{
	if(a.x>b.x) return 0;
	if(a.y==b.y) return a.p > b.p;
	else return 1;
}

Odcy odcy[LOL];
//*/

int main ()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
{	
//	/*

	scanf("%d", &n);
	
	for(int i=0; i<n; ++i)
	{
		int a, b, c, d; 
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		if(a==c)
		{
			if(d>b) swap(b, d);
			odcy[g].p=b;
			odcy[g].k=d;
			odcy[g].x=a;
			g++;
		}
		if(b==d&&a!=c)
		{
			if(c>a) swap(a,c);
			odcx[h].p=a;
			odcx[h].k=c;
			odcx[h].y=b;
			h++;
		}
	}
	
	sort(odcx, odcx+(h+1));
	sort(odcy, odcy+(g+1));
	
	for(int i=0; i<h; ++i)
	{
		while(odcx[i].k>odcx[i+1].p)
		{
					
		}
	}
//	*/
}
