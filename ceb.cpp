#inc
lude <cstdio>
#define XD 505

char lol[XD][XD];
int n;

bool ceb (int pier, int licz)
{
	
	if((n/2-1)<=pier) return true;
	
	for(int i=pier-1; i<licz; i++)
	{
		if(lol[pier][pier]!=lol[i][pier]) return false;
	}
	
	for(int i=pier-1; i<licz; i++)
	{
		if(lol[pier][pier]!=lol[pier][i]) return false;
	}
	
	for(int i=pier-1; i<licz; i++)
	{
		if(lol[pier][licz]!=lol[i][licz]) return false;
	}
	
	for(int i=pier-1; i<licz; i++)
	{
		if(lol[licz][pier]!=lol[licz][i]) return false;
	}
	
	ceb (pier+1, licz-1);
}


int main ()
{
	

	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%s", lol[i]);
	}
	
	int c = ceb(0, n);
	
	if(c) printf("XXD");
	else printf("DDX");
}
