#include<bits/stdc++.h>

#define s second 
#define f first
#define XD 1505
#define mp make_pair

using namespace std;

typedef pair<long long, long long> pll;

int quad (pll a)
{
	if(a.s==0)
	{
		if(a.f==0) exit(69);
		if(a.f>0) return 1;
		else return 5;
	}
	if(a.s>0)
	{
		if(a.f==0) return 3;
		if(a.f>0) return 2;
		else return 4;
	}
	else
	{
		if(a.f==0) return 7;
		if(a.f>0) return 8;
		else return 6;
	}
}

long long cpr (pll a, pll b)
{
	return ( b.f * a.s) - ( b.s * a.f);
}

long long scal (pll a, pll b)
{
	return (a.f * b.f) + (a.s * b.s);
}

bool cmp (pll a, pll b)
{
	if(quad(a) != quad(b)) return quad(a) < quad(b);
	long long c=cpr(a,b);
	if(cpr(a, b)==0) 
	{
		if (a.f==0) return abs(a.s)<abs(b.s);
		return abs(a.f)<abs(b.f);
	}
	if (cpr(a,b)>0) return 1;
	return 0;
}

set<pll> se;
vector<pll> vec;
int n;
long long out;
pll pon [XD];


int main ()
{
	
	scanf("%d", &n);
	
	for(int i = 0; i<n; ++i)
	{
		scanf("%lld%lld", &pon[i].f, &pon[i].s);
		se.insert(pon[i]);
	}
	
	for(int i=0; i<n; ++i)
	{
		vec.clear();
		for(int j=0; j<n; ++j)
		{
			if(i==j) continue;
			vec.push_back(mp(pon[j].f-pon[i].f, pon[j].s-pon[i].s));
		}
		
		sort(vec.begin(),vec.end(), cmp);
		
		for(int k = 0; k < n - 1; k++)
        {
            vec.push_back(vec[k]);
        }
		vec.push_back(mp(69,96));
		
		long long p=1;
		for(long long k=0; k<n; ++k)
		{
			
			while(scal(pon[k],pon[p])>=0)
			{
				if(scal(pon[k],pon[p])!=0)
				{
					p++;
					continue;
				}
				
				out = max(cpr(pon[k], pon[p]),out);
			}
		}
		p=n-3;
		for(int k=n-2; k>0; --k)
		{
			
			while(scal(pon[k],pon[p])>=0)
			{
				if(scal(pon[k], pon[p])!=0)
				{
					p--;
					continue;
				}
				
				out = max(cpr(pon[k], pon[p]),out);
			}
		}
	}
	
}
