#include <bits\stdc++.h>

#define ASD 1000000

using namespace std;

int miast[ASD];

int main ()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &miast[i]);
	}
	
	int suma=0;
	
	for(int i=0; i<n; i++)
	{
		suma+=miast[i];
	}
	
	int roz1=1000000, roz2=0, d=0;
	int pier=0, drug=0;
	
	if(miast[0]<suma-miast[0])
	{
	  
		for(int i=0; i<n-1; i++)
		{	
			d=i;
					
			pier+=miast[i];
			drug=suma-pier;
			
//		printf("%d: %d %d \n", d, pier, drug);
			
			roz2=roz1;
			roz1=abs(drug-pier);
			
//		printf("%d: %d %d \n", d, roz2, roz1);
			
			if(roz1>roz2) break;
		}
		
		pier-=miast[d];
		
//		printf("%d", pier);
		
		drug=suma-pier;	
		
		pier*=drug;
		
		
		
		printf("%d", pier);
		
	}
	
	else 
	{
		int lol=miast[0]*(suma-miast[0]);
		printf("%d", lol);
	}
}
