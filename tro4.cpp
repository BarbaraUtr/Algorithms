#include<cstdio>

#define LOL 550000000

using namespace std;

//int a[LOL], b[LOL], c[LOL];

int main()
{
	
	int n, wyn=0, naj=0;
	
	scanf("%d", &n);
/*	
		for(int i=0; i<n; ++i)
	{
//		printf("i: %d\n", i);	
		
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
*/	
	int tym=0;
	
	for(int i=0; i<n; ++i)
	{
		int a, b, c;
		
		scanf("%d%d%d", &a, &b, &c);
		
		if(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
		{
			wyn++;
			tym++;
//			printf("i: %d\n", i);

			if(tym>naj) naj=tym;
		}
		else 
		{	
			tym=0;
		}
	}
	
//	naj-=1;
	
	printf("%d\n%d", wyn, naj);
}
