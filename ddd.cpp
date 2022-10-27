#include <cstdio>

using namespace std;

int main() 
{
	long long int n;
	
	int sil=1;
	
	scanf("%lld", &n);
	
	if(n<10)
	{
	
		for(int i=1; i<=n; i++)
		{	
			sil*=i;
			
			sil%=100;
		}
		
		printf("%d",sil);
	}
	else printf("00");
}

