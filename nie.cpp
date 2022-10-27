#include <cstdio>
#include <vector>

#define LOL 100001

using namespace std;

vector<int> graf[LOL];

bool odw[LOL];

int post[LOL], pre[LOL], oj[LOL][28];
int po, pr;

int g[LOL];
int gl;

void dfs(int x, int o, int gl) 
{
	//printf("dfs%d %d %d\n",x,o,gl);
	g[x]=gl;
    odw[x]=true;
    
    pre[x]=pr; // preorder
    pr++;
    
    oj[x][0]=o; // ojciec wierzcholka
	
    for(int i=0; i<graf[x].size(); i++)
    {
        int sy=graf[x][i];
        
         if (!odw[sy])
            {
                dfs(sy, x, gl+1);
            }
    }
    
    post[x]=po; // postorder
    po++;
}

bool a_nad_b(int a, int b)
{
	return (post[b]<=post[a]&&pre[b]>=pre[a]);
}

int lca(int a,int b)
{
	if(a_nad_b(b,a)) return b;
	
	if(a_nad_b(a,b)) return a;
	
	for(int i=17;i>=0;i--)
	{
		if(!a_nad_b(oj[a][i],b))a=oj[a][i];
		if(!a_nad_b(oj[b][i],a))b=oj[b][i];
	}
	return  oj[a][0];
}

int main()
{
    int w, k, m;
    pre[0]=-1;
    post[0]=1000000000;

    scanf("%d",&w);
    
    k=w-1;
    
	for(int i=0; i<k; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);

        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    
    scanf("%d", &m);
    
	
    dfs(1, 0, 1);
    
    for(int i=1; i<18; i++)			// Jump Pointery
    {
    	for(int k=1; k<=w; k++)
    	{
    		oj[k][i]=oj[oj[k][i-1]][i-1];
    		//printf("  %d[%d]: %d\n",k,i,oj[k][i]);
		}
	}

	for(int i=0; i<m; i++)
	{
		int wyn, c, d;
		
		scanf("%d%d", &c, &d);
		wyn = g[c]+g[d]-2*g[lca(c, d)];
		
		printf("%d \n", wyn);
	}
}

