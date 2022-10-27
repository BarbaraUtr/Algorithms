#include <bits\stdc++.h>

#define LOL 100005

using namespace std;

pair <int, long long> mia [LOL];

pair <long long, int> aim [LOL];

/*
bool kms (pair x, pair y)
{
	if(x.second > y.second) return 1;
	
	if(x.second < y.second) return 0;
	
	else
	{
		if(x.first > y.first) return 1;
		
		if (x.first < y.first) return 0;
		
		else return 1; 
	}
}
*/

int main ()
{
	int n, k;
	
	scanf("%d%d", &n, &k);
	
	for(int i=0; i<n; i++)
	{
		int x;
		
		scanf("%lld", &mia[i].first);
		mia[i].second=i;
	}
	
}
