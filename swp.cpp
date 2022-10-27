#include <bits/stdc++.h>

#define licz 100000

using namespace std;

int main ()
{
	int n;
	
	bool odp=true;
	
	char p[licz], d[licz];
	
	scanf("%d", &n);
	
	scanf ("%s",&p);
	scanf ("%s", &d);
	
	sort(p,p+n);
	sort(d,d+n);
	
	for(int i=0; i<n; i++)
	{
		if(p[i]!=d[i]) odp=false;
	}
	
	if(odp) printf("TAK");
	else printf("NIE");
	
}

