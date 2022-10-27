#include <bits/stdc++.h>

#define LOL 1000006
#define DWA 2097152

using namespace std;

int tree[DWA], odp[LOL], odj[DWA];
int dwa=1;

void fill(int v)
{
	while(v!=1)
	{
		v/=2;
		tree[v]=min(tree[2*v], tree[2*v+1]);
	}
	return;
}

void find_base(int v, int L, int R, int a, int b) 
{
	if (L == a && R == b) {
		tree[v]--;
		fill(v);
		return;
	}

	int mid = (a + b - 1) / 2;
	if (R <= mid) {
		find_base(2 * v, L, R, a, mid);
	} else if (L > mid) {
		find_base(2 * v + 1, L, R, mid + 1, b);
	} else {
		find_base(2 * v, L, mid, a, mid);
		find_base(2 * v + 1, mid + 1, R, mid + 1, b);
	}
}

int insert(int a, int b)
{
	find_base(1, a, b, 0, DWA);
}

int query (int v)
{
	if(v>=(dwa/2)) return v;
	if(tree[v]==0)
	{
		if(tree[2*v+1]>=tree[2*v])
		{
			query(2*v+1);
		}
		else
		{
			query(2*v);
		}
	}
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	while(dwa<=n)
	{
		dwa*=2;
	}
	dwa*=2; 
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &tree[dwa/2+i]);
	}
	
	for(int i=1; i<=n; ++i)
	{
		int b=query(1);
		find_base(1,b,dwa-1,1,dwa);
		b-=dwa;
		odp[b]=i;
	}
	
	for(int i=0; i<n; ++i)
	{
		printf("%d", odp[i]);
	}
}
