#include <bits\stdc++.h>

#define LOL 100005

int t[LOL];

int main ()
{
	int n; 
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
	}
	
	int wyn=0, zna=0, tym=0;
	
	for(int i=1; i<=n; ++i)
	{
		if(t[i]!=0)
		{
//			printf("%d\n", i);
			
			zna=i;
			tym=i;
			
			wyn++;
			
			while(zna!=t[tym])
			{
				int a=t[tym];
				
				t[tym]=0;
				
				tym=a;
				
//				printf("%d: %d %d\n", i, zna, tym);
			}
			
			t[tym]=0;
		}
	}
	
	printf("%d", wyn);
}
