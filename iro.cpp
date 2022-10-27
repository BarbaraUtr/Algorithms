#include<bits/stdc++.h>

#define LOL 100005

using namespace std;

int n, k, wa;

int odp[LOL];

bool odw[LOL];

vector<int> wie[LOL], war[LOL];

queue<int> kol;

void def (int x)
{
	wa++;
	odw[x]=1;
	war[wa].push_back(x);
	for(int i=0; i<wie[x].size(); ++i)
	{
		if(odw[wie[x].back()]) continue;
		else
		{
			def(wie[i].front());
		//	wie[i].pop // ???
		}
	}
}

int main ()
{
	scanf("%d%d", &n, &k);
	
	for(int i=0; i<k; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		
		
		wie[a].push_back(b);
		wie[b].push_back(a);	
	}
	
	for(int i=0; i<war[wa].size(); ++i)
	{
		odp[war[wa].front()]=1;
		war[wa].pop_back();
	}
	
	for(int i=(wa-1); i>0; --i)
	{
		for(int j=0; j<war[i].size(); ++j)
		{
			
		}
	}
	
}
