#include <cstdio>

using namespace std;

int main ()
{
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	m+=n;
	m%=2;
	
	int k;
	
	scanf("%d", &k);
	
	for(int i=0; i<k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		a+=b;
		a%=2;
		if(m==a) printf("Arm \n");
		else printf("Miko \n");
	}	
}
