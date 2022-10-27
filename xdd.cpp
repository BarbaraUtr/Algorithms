#include <bits/stdc++.h>

#define licz 200000

using namespace std;



struct dom
{
	int pier;
	int drug;
};

bool operator<(dom a, dom b)
{
	return a.pier < b.pier;
}

bool operator>(dom a, dom b)
{
	return a.drug > b.drug;
}

 dom t[licz];

int main ()
{
	int n;
	//int a[licz], b[licz]; 
	int wyn[licz];
	int maks=0;
	int a, b;
	bool odw[licz];
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		wyn[i]=1;
	}
	
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &a, &b);
		
		t[i].pier=a;
		t[i].drug=b;
	}
	
	sort(t,t+n);
	
	dom x;
				
	for(int i=0; i<n; i++)
	{
		x.pier=t[i].pier;
		x.drug=t[i].drug;
		
		for(int k=(i+1); k<n; k++)
		{ 
			if(x>t[k])
			{
				wyn[i]++;
				x.pier=t[k].pier;
				x.drug=t[k].drug;
				//printf("%d %d ", x.pier, x.drug);
			}
		}
	}
	/*
	for(int i=0; i<n;i++)
	{
		printf("%d",wyn[i]);
	} */

//printf("%d %d",x.pier, x.drug);
	
	for(int i=0; i<n; i++)
	{
		if(wyn[i]>maks) maks=wyn[i];
	}
	printf("%d",maks);
}

