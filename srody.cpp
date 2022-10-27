Kulki:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define xd puts("XD")
#define endl puts("")
#define ub upper_bound
#define lb lower_bound
#define mn 100010
 
int n,q,a,b,korzen;
vector <int> v[mn];
int czas;
int post[mn], oj[mn];
long long int wsk;
bool wyn[mn];
int g[mn];
int LOG=17;
int p[mn][20];
priority_queue <pair <int,int> > kol;
int mini[mn];
 
bool comp(int a, int b)
{
    if (mini[a]<mini[b])
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test_post()
{
    puts ("--------------------------------TEST POST-------------------------");
    for (int i=1; i<=n; i++)
    {
        printf ("i=%d post[i]=%d g[i]=%d\n", i, post[i], g[i]);
    }
}
void dfsp(int x, int y)
{
    int l=v[x].size();
    mini[x]=x;
    for (int i=0; i<l; i++)
    {
        if (v[x][i]!=oj[x])
        {
            dfsp(v[x][i], y+1);
            mini[x]=min(mini[x], mini[v[x][i]]);
        }
    }
}
void dfsk(int x, int y)
{
    int l=v[x].size();
    g[x]=y;
    for (int i=0; i<l; i++)
    {
        if (v[x][i]!=oj[x])
        {
            dfsk(v[x][i], y+1);
        }
    }
    czas++;
    post[x]=czas;
    kol.push(mp(-1*post[x], x));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        if (a==0)
        {
            korzen=i;
            p[i][0]=i;
        }
        else
        {
            v[i].pb(a);
            v[a].pb(i);
            oj[i]=a;
            p[i][0]=a;
        }
    }
    dfsp(korzen, 0);
    for (int i=1; i<=n; i++)
    {
        sort (v[i].begin(), v[i].end(), comp);
    }
    dfsk(korzen, 0);
    //test_post();
    for (int l=1; l<=LOG; l++)
    {
        for (int i=1; i<=n; i++)
        {
            p[i][l]=p[p[i][l-1]][l-1];
            //printf ("l=%d i=%d p[i][l]=%d\n", l, i, p[i][l]);
        }
    }
    for (int t=1; t<=q; t++)
    {
        //printf ("t=%d\n", t);
        cin >> a >> b;
        if (a==1)
        {
            for (int i=1; i<=b; i++)
            {
                int x=kol.top().ss;
                //printf ("x=%d\n", x);
                wyn[x]=true;
                if (i==b)
                {
                    printf ("%d\n", x);
                }
                kol.pop();
            }
        }
        else
        {
            int l=LOG;
            int x=b;
            while (l>=0)
            {
                if (wyn[p[x][l]]==true)
                {
                    x=p[x][l];
                }
                l--;
            }
            //printf ("b=%d x=%d post[x]=%d\n", b, x, post[x]);
            printf ("%d\n", g[b]-g[x]);
            wyn[x]=false;
            kol.push(mp(-1*post[x], x));
        }
    }
    return 0;
}

 
Lider:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define xd puts("XD")
#define endl puts("")
#define ub upper_bound
#define lb lower_bound
 
int n,a,ile,kto;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        if (a==kto)
        {
            ile++;
        }
        else
        {
            if (ile==0)
            {
                ile++;
                kto=a;
            }
            else
            {
                ile--;
            }
        }
    }
    printf ("%d", kto);
    return 0;
}
 
Skarpetki:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define xd puts("XD")
#define endl puts("")
#define ub upper_bound
#define lb lower_bound
 
long long int n,a,wynik;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        wynik=wynik^a;
    }
    printf ("%lld\n", wynik);
    return 0;
}
 
Kefir:
#include <bits/stdc++.h>
using namespace std;
 
#define MINF 0.000000000001
 
long double x,y,xa,xb,xc,ya,yb,yc,fa1,fa2,fb1,fb2,fc1,fc2,ax,ay,bx,by,cx,cy,pole,a,b,c,p,pp;
long double ix[3], iy[3];
long long int wynik;
 
int main()
{
    cin >> x >> y;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    fa1=xa/(ya+MINF);
    fa2=ya/(xa+MINF);
    fb1=xb/(yb+MINF);
    fb2=yb/(xb+MINF);
    fc1=xc/(yc+MINF);
    fc2=yc/(xc+MINF);
    //printf ("fa1=%Lf fa2=%Lf fb1=%Lf fb2=%Lf fc1=%Lf fc2=%Lf\n", fa1, fa2, fb1, fb2, fc1, fc2);
    ax=(y+x*fa1)/(fa1+fa2);
    bx=(y+x*fb1)/(fb1+fb2);
    cx=(y+x*fc1)/(fc1+fc2);
    ay=ax*fa2;
    by=bx*fb2;
    cy=cx*fc2;
    //printf ("ax=%Lf ay=%Lf   bx=%Lf by=%Lf   cx=%Lf cy=%Lf\n", ax, ay, bx, by, cx, cy);
    ix[0]=ax;
    ix[1]=bx;
    ix[2]=cx;
    iy[0]=ay;
    iy[1]=by;
    iy[2]=cy;
    sort (ix+1, ix+4);
    sort (iy+1, iy+4);
    a=sqrt((abs(ax-bx))*(abs(ax-bx))+(abs(ay-by))*(abs(ay-by)));
    b=sqrt((abs(ax-cx))*(abs(ax-cx))+(abs(ay-cy))*(abs(ay-cy)));
    c=sqrt((abs(cx-bx))*(abs(cx-bx))+(abs(cy-by))*(abs(cy-by)));
    p=(a+b+c)/2;
    //printf ("p=%Lf\n", p);
    p=sqrt(p*(p-a)*(p-b)*(p-c));
    //printf ("p=%Lf\n", p);
    pp=floor(p);
    //printf ("a=%Lf b=%Lf c=%Lf p=%Lf pp=%Lf\n", a, b, c, p, pp);
    wynik=(long long int)pp;
    if (pp!=p)
    {
        wynik++;
    }
    printf ("%lld\n", wynik);
    return 0;
}
 
Najdzielniejszy dzielnik:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define endl puts("")
#define xd puts("XD")
#define mn 610
 
int n;
long long int a[mn];
long long int k,wsk,liczba,zakres;
bool sito[1000010];
 
long long int nwd(long long int a, long long int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b)
        {
            a%=b;
        }
        else
        {
            b%=a;
        }
    }
    return max(a, b);
}
void skroc(long long int p)
{
    //printf ("SKROC p=%lld\n", p);
    long long int kr=0;
    for (int i=1; i<=n; i++)
    {
        //printf ("i=%d a[i]=%d\n", i, a[i]);
        while (a[i]%p==0)
        {
            a[i]/=p;
            kr++;
        }
    }
    k=max(k, kr);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (long long int i=2; i<=1000000; i++)
    {
        if (sito[i]==false)
        {
            //printf ("i=%d\n", i);
            for (long long int j=i*i; j<=1000000; j+=i)
            {
                sito[j]=true;
            }
        }
    }
    cin >> n;
    //printf ("%d\n", clock());
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        zakres=max(zakres, (long long int)cbrt(a[i])+1);
    }
    //printf ("%d\n", clock());
    //printf ("zakres=%lld\n", zakres);
    for (int j=2; j<=zakres; j++)
    {
        if (sito[j]==false)
        {
            skroc(j);
        }
    }
    //printf ("k=%lld\n", k);
    //xd;
    //printf ("%d\n", clock());
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            long long int d=nwd(a[i], a[j]);
            if (d<max(a[i], a[j]) && d>1)
            {
                //printf ("i=%d j=%d d=%lld\n", i, j, d);
                skroc(d);
            }
        }
    }
    //printf ("k=%lld\n", k);
    //xd;
    //printf ("%d\n", clock());
    for (int i=1; i<=n; i++)
    {
        long long int d=sqrt(a[i]);
        if (d*d==a[i] && d>1)
        {
            //printf ("i=%d d=%lld a[i]=%d\n", i, d, a[i]);
            skroc(d);
        }
    }
    //printf ("k=%lld\n", k);
    //xd;
    //printf ("%d\n", clock());
    sort (a+1, a+1+n);
    wsk=1;
    for (int i=1; i<=n; i++)
    {
        //printf ("i=%d a[i]=%lld\n", i, a[i]);
        if (a[i]!=1 && liczba==0)
        {
            wsk=i;
            liczba=a[i];
        }
        else if (a[i]!=liczba && a[i]!=1)
        {
            k=max(k, i-wsk);
            //printf ("wsk=%d i=%d i-wsk=%d\n", wsk, i, i-wsk);
            liczba=a[i];
            wsk=i;
        }
    }
    //printf ("%d\n", clock());
    printf ("%lld\n", k);
    return 0;
}

 
Obwód drukowany:
#include <bits/stdc++.h>
using namespace std;
 
#define mn 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define zakres 2097160
 
int n,a,b,r;
vector <pair <int,int> > v;
int tree[zakres];
int dp[zakres];
int wynik;
 
void insert (int x)
{
    x+=r-1;
    while (x>0)
    {
        tree[x]++;
        x/=2;
    }
}
int query (int x, int pp, int pk, int zp, int zk)
{
    if (zk<pp || pk<zp)
    {
        return 0;
    }
    if (zp<=pp && pk<=zk)
    {
        return tree[x];
    }
    int sr=(pp+pk)/2;
    return query(2*x, pp, sr, zp, zk)+query(2*x+1, sr+1, pk, zp, zk);
}
void insertdp(int x)
{
    x/=2;
    while (x>0)
    {
        dp[x]=max(dp[x*2], dp[x*2+1]);
        x/=2;
    }
}
int querydp(int x, int pp, int pk, int zp, int zk)
{
    //printf ("x=%d pp=%d pk=%d zp=%d zk=%d\n", x, pp, pk, zp, zk);
    if (zk<pp || pk<zp)
    {
        //puts ("CASE 1");
        return 0;
    }
    if (zp<=pp && pk<=zk)
    {
        //puts ("CASE 2");
        return dp[x];
    }
    //puts ("CASE 3");
    int sr=(pp+pk)/2;
    return max(querydp(2*x, pp, sr, zp, zk), querydp(2*x+1, sr+1, pk, zp, zk));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    r=zakres-8;
    r/=2;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a >> b;
        v.pb(mp(a, b));
    }
    sort (v.begin(), v.end());
    for (int i=0; i<n; i++)
    {
        int a=i+1;
        a+=r-1;
        int x=v[i].ff;
        int y=v[i].ss;
        int gg=query(1, 1, r, y+1, 1000000);
        if (gg==0)
        {
            dp[y+r-1]=max(dp[y+r-1], 1);
        }
        else
        {
            //printf ("i-gg+1=%d i=%d\n", i-gg+1, i);
            dp[y+r-1]=max(dp[y+r-1], querydp(1, 1, r, y+1, 1000000)+1);
        }
        //printf ("i=%d y+r-1=%d dp[y+r-1]=%d gg=%d\n", i, y+r-1, dp[y+r-1], gg);
        insertdp(y+r-1);
        insert(y);
        wynik=max(wynik, dp[y+r-1]);
    }
    printf ("%d\n", wynik);
    return 0;
}

 
Kubki:
#include <bits/stdc++.h>
using namespace std;
 
#define mn 100005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mn 20005
#define mm 1005
 
int n,m,k;
int ile1[mm], ile2[mm];
int tab[mn];
int pom[mm];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> tab[i];
    }
    for (int i=2; i<=n; i+=2)
    {
        ile2[tab[i-1]]++;
        ile2[tab[i]]++;
        ile2[tab[i/2]]--;
        ile1[tab[i/2]]++;
        for (int j=1; j<=m; j++)
        {
            pom[j]=ile2[j];
        }
        int wsk=1;
        while (pom[wsk]==0)
        {
            wsk++;
        }
        bool odp=true;
        int suma=0;
        for (int j=1; j<=m && odp==true; j++)
        {
            if (j>=wsk)
            {
                odp=false;
            }
            suma+=ile1[j];
            while (suma>0)
            {
                if (pom[wsk]>=suma)
                {
                    pom[wsk]-=suma;
                    suma=0;
                }
                else
                {
                    suma-=pom[wsk];
                    pom[wsk]=0;
                }
                while (pom[wsk]==0)
                {
                    wsk++;
                }
            }
        }
        if (odp==true)
        {
            k=max(k, i/2);
        }
    }
    printf ("%d\n", k);
    return 0;
}
 
Okrêgi:
#include <bits/stdc++.h>
using namespace std;
 
int n,x,r;
int ist[305][305];
int dp[305][305];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x >> r;
         ist[x+100-r][x+100+r]++;
    }
    for (int roz=1; roz<=300; roz++)
    {
        if (roz<=2)
        {
            for (int i=1; i<=299; i++)
            {
                dp[i][i+2]=ist[i][i+2];
                //printf ("i=%d roz=%d i+roz=%d dp[i][i+roz]=%d\n", i, roz, i+roz, dp[i][i+roz]);
            }
        }
        else
        {
            for (int i=1; i<=300-roz; i++)
            {
                for (int j=i+1; j<i+roz; j++)
                {
                    dp[i][i+roz]=max(dp[i][i+roz], dp[i][j]+dp[j][i+roz]+ist[i][i+roz]);
                }
                //if (roz<=8) printf ("i=%d roz=%d i+roz=%d dp[i][i+roz]=%d\n", i, roz, i+roz, dp[i][i+roz]);
            }
        }
    }
    printf ("%d\n", n-dp[1][300]);
    return 0;
}

 
Tablica:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define endl puts("")
#define xd puts("XD")
#define mn 1005
#define INF 1000696969
 
int t,n,m,q;
int tab[mn][mn];
int w1[mn], w2[mn], k1[mn], k2[mn];
pair <int,int> znak[2000005];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    q=1000000;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        cin >> n >> m;
        for (int i=1; i<=2000000; i++)
        {
            znak[i]=mp(INF, INF);
        }
        for (int i=1; i<=max(n, m); i++)
        {
            w1[i]=w2[i]=k1[i]=k2[i]=INF;
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cin >> tab[i][j];
                w1[i]=min(w1[i], tab[i][j]);
                k1[j]=min(k1[j], tab[i][j]);
            }
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                znak[tab[i][j]+q]=mp(w1[i], k1[j]);
                //printf ("i=%d j=%d tab[i][j]+q=%d w1[i]=%d k1[j]=%d\n", i, j, tab[i][j]+q, w1[i], k1[j]);
            }
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cin >> tab[i][j];
                w2[i]=min(w2[i], tab[i][j]);
                k2[j]=min(k2[j], tab[i][j]);
            }
        }
        bool joker=true;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                //printf ("i=%d j=%d tab[i][j]+q=%d znak[tab[i][j]+q]=(%d, %d) w2[i]=%d k2[j]=%d\n", i, j, tab[i][j]+q, znak[tab[i][j]+q].ff, znak[tab[i][j]+q].ss, w2[i], k2[j]);
                if (znak[tab[i][j]+q]!=mp(w2[i], k2[j]))
                {
                    joker=false;
                }
            }
        }
        if (joker==false)
        {
            puts ("NIE");
        }
        else
        {
            puts ("TAK");
        }
    }
    return 0;
}
 
Dawid:
#include <bits/stdc++.h>
using namespace std;
 
#define mn 300005
#define pb push_back
 
int n,m,a,b;
vector <int> v[mn];
int odw[mn], oj[mn], lou[mn], g[mn], roz[mn];
int wynik;
 
void dfs(int x, int y)
{
    odw[x]=1;
    g[x]=y;
    //printf ("DFS x=%d g[x]=%d\n", x, g[x]);
    lou[x]=g[x];
    int l=v[x].size();
    for (int i=0; i<l; i++)
    {
        if (oj[x]!=v[x][i])
        {
            if (odw[v[x][i]]!=1)
            {
                oj[v[x][i]]=x;
                dfs(v[x][i], y+1);
                lou[x]=min(lou[x], lou[v[x][i]]);
            }
            else
            {
                lou[x]=min(lou[x], g[v[x][i]]);
            }
        }
    }
    //printf ("x=%d lou[x]=%d\n", x, lou[x]);
}
void oblicz(int x)
{
    odw[x]=2;
    int l=v[x].size();
    roz[x]=1;
    for (int i=0; i<l; i++)
    {
        if (oj[x]!=v[x][i])
        {
            if (odw[v[x][i]]!=2)
            {
                oblicz(v[x][i]);
                if (lou[v[x][i]]!=g[v[x][i]])
                {
                    roz[x]+=roz[v[x][i]];
                }
            }
        }
    }
    wynik=max(wynik, roz[x]);
}
void test_dfs()
{
    puts ("-------------------------TEST DFS-----------------");
    for (int i=1; i<=n; i++)
    {
        printf ("i=%d g[i]=%d lou[i]=%d\n", i, g[i], lou[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, 1);
    //test_dfs();
    oblicz(1);
    printf ("%d\n", wynik);
    return 0;
}
/*
7 9
4 3
2 6
7 1
4 1
7 3
3 5
7 4
6 5
2 5
*/
 
Ograniczenia prêdkoœci:
#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 155
#define MAXSPEED 505
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef long double ld;
 
int n, m, d, a, b, c, l, sp;
pair <ld, pair <int,int> > dp[MAXN][MAXSPEED];
vector <pair <int, pair <int, int> > > v[MAXN];
priority_queue <pair <pair <ld, pair <int, int> >, pair <int, ld> > > q;
bool odw[MAXN][MAXSPEED];
vector <int> odp;
pair <int,int> wsk;
 
void dixtra()
{
    while (q.empty()==false)
    {
        ld a=q.top().ff.ff;
        int c=q.top().ff.ss.ff;
        int d=q.top().ff.ss.ss;
        int x=q.top().ss.ff;
        ld y=q.top().ss.ss;
        a*=-1;
        //printf ("x=%d y=%Lf a=%Lf\n", x, y, a);
        q.pop();
        if (odw[x][(int)y]==false)
        {
            //printf ("ACCEPTED x=%d y=%Lf a=%Lf\n", x, y, a);
            dp[x][(int)y]=mp(a, mp(c, d));
            odw[x][(int)y]=true;
            int l=v[x].size();
            for (int i=0; i<l; i++)
            {
                int cel=v[x][i].ff;
                ld spd=v[x][i].ss.ff;
                ld dl=v[x][i].ss.ss;
                if (spd==0)
                {
                    if (odw[cel][(int)y]==false && a+dl/y<dp[cel][(int)y].ff)
                    {
                        dp[cel][(int)y].ff=a+dl/y;
                        //printf ("CASE 1 cel=%d\n", cel);
                        //odw[cel][(int)y]=true;
                        //dp[cel][(int)y]=mp(a+dl/y, mp(x, y));
                        q.push(mp(mp(-(a+dl/y), mp(x, y)), mp(cel, y)));
                    }
                }
                else
                {
                    if (odw[cel][(int)spd]==false && a+dl/spd<dp[cel][(int)spd].ff)
                    {
                        dp[cel][(int)spd].ff=a+dl/spd;
                        //printf ("CASE 2 cel=%d\n", cel);
                        //odw[cel][(int)spd]=true;
                        //dp[cel][(int)spd]=mp(a+dl/spd, mp(x, y));
                        q.push(mp(mp(-(a+dl/spd), mp(x, y)), mp(cel, spd)));
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i=1; i<=m; i++)
    {
        cin >> a >> b >> sp >> l;
        v[a].pb(mp(b, mp(sp, l)));
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=500; j++)
        {
            dp[i][j].ff=1000696969;
        }
    }
    dp[0][70].ff=0;
    //odw[0][70]=true;
    q.push(mp(mp(-0, mp(0, 0)), mp(0, 70)));
    dixtra();
    ld wynik=1000696969;
    for (int i=0; i<=500; i++)
    {
        if (dp[d][i].ff<wynik)
        {
            wsk=mp(d, i);
        }
        wynik=min(wynik, dp[d][i].ff);
    }
    //printf ("%Lf\n", wynik);
    odp.pb(d);
    while (wsk.ff!=0)
    {
        wsk=mp(dp[wsk.ff][wsk.ss].ss.ff, dp[wsk.ff][wsk.ss].ss.ss);
        odp.pb(wsk.ff);
    }
    for (int i=odp.size()-1; i>=0; i--)
    {
        printf ("%d ", odp[i]);
    }
    return 0;
}
 
Haker:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define endl puts("")
#define xd puts("XD")
#define MAXN 1000005
 
int n, ile;
int tab[MAXN];
int suma[MAXN];
deque <pair <int, int> > q;
int wynik;
 
void test()
{
    for (int i=1; i<=2*n; i++)
    {
        printf ("i=%d tab[i]=%d suma[i]=%d\n", i, tab[i], suma[i]);
    }
}
void test_kolejka()
{
    queue <pair <int,int> > pom;
    while (q.empty()==false)
    {
        printf ("%d %d\n", q.front().ff, q.front().ss);
        pom.push(mp(q.front().ff, q.front().ss));
        q.pop_front();
    }
    while (pom.empty()==false)
    {
        q.pb(mp(pom.front().ff, pom.front().ss));
        pom.pop();
    }
    endl;
}
void dodaj(int x, int y)
{
    while (q.empty()==false && q.back().ff>=x)
    {
        q.pop_back();
    }
    q.pb(mp(x, y));
}
void usun(int x)
{
    while (q.empty()==false && q.front().ss<x)
    {
        q.pop_front();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ile=(n+1)/2;
    for (int i=1; i<=n; i++)
    {
        cin >> tab[i];
        tab[i+n]=tab[i];
    }
    for (int i=2*n; i>=1; i--)
    {
        if (i>2*n-ile)
        {
            suma[i]=suma[i+1]+tab[i];
        }
        else
        {
            suma[i]=suma[i+1]+tab[i]-tab[i+ile];
        }
    }
    //test();
    for (int i=1; i<=ile+n-1; i++)
    {
        if (i<ile)
        {
            dodaj(suma[i], i);
        }
        else
        {
            usun(i-ile+1);
            dodaj(suma[i], i);
            //test_kolejka();
            wynik=max(wynik, q.front().ff);
        }
    }
    printf ("%d", wynik);
    return 0;
}

Trzej finaliœci:
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define endl puts("")
#define xd puts("XD")
#define MAXN 2000005
 
typedef long long int ll;
 
int n;
char s[MAXN];
ll h1=29, h2=31;
ll m1=1000000007, m2=1000000009;
ll hs1[MAXN], hs2[MAXN];
ll pot1[MAXN], pot2[MAXN];
set <pair <ll, ll> > rozwy;
set <pair <ll, ll> > ::iterator it;
int p, k;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n%2==0)
    {
        puts ("NOT POSSIBLE");
        return 0;
    }
    pot1[0]=pot2[0]=1;
    for (int i=1; i<=n; i++)
    {
        pot1[i]=pot1[i-1]*h1;
        pot2[i]=pot2[i-1]*h2;
        pot1[i]%=m1;
        pot2[i]%=m2;
        //printf ("i=%d pot1[i]=%lld pot2[i]=%lld\n", i, pot1[i], pot2[i]);
    }
    cin >> s+1;
    for (int i=1; i<=n; i++)
    {
        //printf ("i=%d s[i]=%c int(s[i])-64=%d\n", i, s[i], int(s[i])-96);
        hs1[i]=hs1[i-1]+pot1[i]*(int(s[i])-64);
        hs2[i]=hs2[i-1]+pot2[i]*(int(s[i])-64);
        hs1[i]%=m1;
        hs2[i]%=m2;
        //printf ("i=%d hs1[i]=%lld hs2[i]=%lld\n", i, hs1[i], hs2[i]);
    }
    for (int i=1; i<=n; i++)
    {
        //printf ("i=%d\n", i);
        ll s11, s12, s21, s22;
        s11=s12=s21=s22=0;
        if (i<=n/2)
        {
            //puts ("SPRAWDZ 1");
            s21=hs1[n]-hs1[(n+1)/2]+m1;
            s21%=m1;
            s22=hs2[n]-hs2[(n+1)/2]+m2;
            s22%=m2;
            s11=hs1[(n+1)/2]-hs1[i]+hs1[i-1]*h1+m1;
            s11%=m1;
            s12=hs2[(n+1)/2]-hs2[i]+hs2[i-1]*h2+m2;
            s12%=m2;
            s11*=pot1[n/2];
            s12*=pot2[n/2];
            s11%=m1;
            s12%=m2;
            //printf ("s11=%lld s12=%lld s21=%lld s22=%lld\n", s11, s12, s21, s22);
            if (s11==s21 && s12==s22)
            {
                //puts ("CASE 1");
                rozwy.insert(mp(s11, s12));
                p=(n+1)/2+1;
                k=n;
            }
        }
        else if (i==(n+1)/2)
        {
            //puts ("SPRAWDZ 2");
            s21=hs1[n]-hs1[i]+m1;
            s22=hs2[n]-hs2[i]+m2;
            s21%=m1;
            s22%=m2;
            s11=hs1[i-1];
            s12=hs2[i-1];
            s11*=pot1[(n+1)/2];
            s12*=pot2[(n+1)/2];
            s11%=m1;
            s12%=m2;
            //printf ("s11=%lld s12=%lld s21=%lld s22=%lld\n", s11, s12, s21, s22);
            if (s11==s21 && s12==s22)
            {
                //puts ("CASE 2");
                rozwy.insert(mp(s11, s12));
                p=1;
                k=i-1;
            }
        }
        else
        {
            //puts ("SPRAWDZ 3");
            s11=hs1[n/2];
            s12=hs2[n/2];
            s21=hs1[n]-hs1[i]+h1*((hs1[i-1]-hs1[n/2]+m1)%m1)+m1;
            s21%=m1;
            s22=hs2[n]-hs2[i]+h2*((hs2[i-1]-hs2[n/2]+m2)%m2)+m2;
            s22%=m2;
            s11*=pot1[(n+1)/2];
            s12*=pot2[(n+1)/2];
            s11%=m1;
            s12%=m2;
            //printf ("s11=%lld s12=%lld s21=%lld s22=%lld\n", s11, s12, s21, s22);
            if (s11==s21 && s12==s22)
            {
                //puts ("CASE 3");
                rozwy.insert(mp(s11, s12));
                p=1;
                k=(n+1)/2-1;
            }
        }
    }
    //for (it=rozwy.begin(); it!=rozwy.end(); it++)
    {
        //printf ("%lld %lld\n", (*it).ff, (*it).ss);
    }
    if (rozwy.empty()==true)
    {
        puts ("NOT POSSIBLE");
    }
    else if (rozwy.size()==1)
    {
        for (int i=p; i<=k; i++)
        {
            printf ("%c", s[i]);
        }
    }
    else
    {
        puts ("NOT UNIQUE");
    }
    return 0;
}
 
Prostok¹t:
#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 1505
#define mp make_pair
#define ff first
#define ss second
#define endl puts("")
#define pb push_back
#define INF 1000696969
 
typedef long long int ll;
 
int n;
ll x[MAXN], y[MAXN];
map <pair <int, int>, bool> mapa;
vector <pair <ll, ll> > gora, dol;
pair <ll, ll> tab[2*MAXN];
ll wynik;
 
bool comp(pair <ll, ll> a, pair <ll, ll> b)
{
    ll xa=a.ff;
    ll xb=b.ff;
    ll ya=a.ss;
    ll yb=b.ss;
    if (xa*yb-xb*ya>0)
    {
        return true;
    }
    else if (xa*yb-xb*ya<0)
    {
        return false;
    }
    else
    {
        if (xa*xa+ya*ya<=xb*xb+yb*yb)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void test_tab(int www)
{
    for (int i=1; i<=2*n-2; i++)
    {
        printf ("x=%d i=%d tab[i]=(%lld, %lld)\n", www, i, tab[i].ff, tab[i].ss);
    }
    endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x[i] >> y[i];
        mapa[mp(x[i], y[i])]=true;
    }
    for (int i=1; i<=n; i++)
    {
        gora.clear();
        dol.clear();
        for (int j=1; j<=n; j++)
        {
            if (i!=j)
            {
                if (y[j]>y[i])
                {
                    gora.pb(mp(y[j]-y[i], x[j]-x[i]));
                }
                else if (y[j]<y[i])
                {
                    dol.pb(mp(y[j]-y[i], x[j]-x[i]));
                }
                else
                {
                    if (x[j]>x[i])
                    {
                        gora.pb(mp(y[j]-y[i], x[j]-x[i]));
                    }
                    else
                    {
                        dol.pb(mp(y[j]-y[i], x[j]-x[i]));
                    }
                }
            }
        }
        sort(gora.begin(), gora.end(), comp);
        sort(dol.begin(), dol.end(), comp);
        int l1=gora.size();
        int l2=dol.size();
        for (int j=0; j<l1; j++)
        {
            tab[j+1]=tab[j+n]=mp(gora[j].ff, gora[j].ss);
        }
        for (int j=0; j<l2; j++)
        {
            tab[j+1+l1]=tab[j+n+l1]=mp(dol[j].ff, dol[j].ss);
        }
        //test_tab(i);
        int wsk=1;
        for (int j=2; j<=2*n-2; j++)
        {
            //printf ("START i=%d     j=%d wsk=%d\n", i, j, wsk);
            if (wsk!=j)
            {
                ll a=tab[j].ff*tab[wsk].ff;
                ll b=tab[j].ss*tab[wsk].ss;
                if (a+b==0) //prosty
                {
                    //puts ("PROSTY");
                    ll va=tab[j].ff+tab[wsk].ff;
                    ll vb=tab[j].ss+tab[wsk].ss;
                    //printf ("va=%lld vb=%lld\n", va, vb);
                    if (mapa[mp(x[i]+vb, y[i]+va)]==true)
                    {
                        //wynik=max(wynik);
                        ll xa=tab[j].ss;
                        ll ya=tab[j].ff;
                        ll xb=tab[wsk].ss;
                        ll yb=tab[wsk].ff;
                        ll pole=abs(xb*ya)+abs(xa*yb);
                        //pole*=2;
                        wynik=max(wynik, pole);
                        //printf ("1: %lld %lld   2: %lld %lld   3: %lld %lld   4: %lld %lld\n", y[i], x[i], y[i]+tab[j].ff, x[i]+tab[j].ss, y[i]+tab[wsk].ff, x[i]+tab[wsk].ss, y[i]+tab[j].ff+tab[wsk].ff, x[i]+tab[j].ss+tab[wsk].ss);
                        //printf ("pole=%lld\n", pole);
                    }
                }
                else if (a+b<0) //rozwarty
                {
                    while (wsk+1<j && tab[j].ff*tab[wsk+1].ff+tab[j].ss*tab[wsk+1].ss<=0)
                    {
                        wsk++;
                    }
                    if (tab[j].ff*tab[wsk].ff+tab[j].ss*tab[wsk].ss==0)
                    {
                        //puts ("PROSTY");
                        ll va=tab[j].ff+tab[wsk].ff;
                        ll vb=tab[j].ss+tab[wsk].ss;
                        //printf ("va=%lld vb=%lld\n", va, vb);
                        if (mapa[mp(x[i]+vb, y[i]+va)]==true)
                        {
                            //wynik=max(wynik);
                            ll xa=tab[j].ss;
                            ll ya=tab[j].ff;
                            ll xb=tab[wsk].ss;
                            ll yb=tab[wsk].ff;
                            ll pole=abs(xb*ya)+abs(xa*yb);
                            //pole*=2;
                            wynik=max(wynik, pole);
                            //printf ("1: %lld %lld   2: %lld %lld   3: %lld %lld   4: %lld %lld\n", y[i], x[i], y[i]+tab[j].ff, x[i]+tab[j].ss, y[i]+tab[wsk].ff, x[i]+tab[wsk].ss, y[i]+tab[j].ff+tab[wsk].ff, x[i]+tab[j].ss+tab[wsk].ss);
                            //printf ("pole=%lld\n", pole);
                        }
                    }
                }
            }
            //printf ("KONIEC i=%d     j=%d wsk=%d\n", i, j, wsk);
        }
    }
    printf ("%lld\n", wynik);
    return 0;
}

 
Waga:
#include <bits/stdc++.h>
using namespace std;
 
#define endl puts("")
 
typedef short int si;
 
char s[105];
int liczba[105];
int pot[105][215];
int p[215];
int rt[215];
bool prawy[215], lewy[215];
int ip, il;
 
void test_liczba()
{
    for (int i=1; i<=liczba[0]; i++)
    {
        printf ("%d ", liczba[i]);
    }
    endl;
    endl;
}
void calc(int x)
{
    for (int i=0; i<=209; i++)
    {
        p[i]=0;
    }
    int l=pot[0][x-1];
    for (int i=l; i>=1; i--)
    {
        int lic=pot[i][x-1]*3;
        p[l-i]+=lic%10;
        p[l-i+1]+=lic/10;
        if (p[l-i]>9)
        {
            p[l-i]-=10;
            p[l-i+1]++;
        }
    }
    //for (int i=0; i<=l; i++)
    {
        //printf ("%d", p[i]);
    }
    //endl;
    if (p[l]==0)
    {
        pot[0][x]=l;
        for (int i=1; i<=l; i++)
        {
            pot[i][x]=p[l-i];
        }
    }
    else
    {
        pot[0][x]=l+1;
        for (int i=1; i<=l+1; i++)
        {
            pot[i][x]=p[l+1-i];
        }
    }
}
void test_pot()
{
    for (int i=0; i<=209; i++)
    {
        printf ("lc=%d   ", pot[0][i]);
        for (int j=1; j<=pot[0][i]; j++)
        {
            printf ("%d", pot[j][i]);
        }
        endl;
    }
    endl;
}
bool niemniejszy(int x)
{
    int l1=liczba[0];
    int l2=pot[0][x];
    if (l1>l2)
    {
        return true;
    }
    if (l2>l1)
    {
        return false;
    }
    for (int i=1; i<=l1; i++)
    {
        if (pot[i][x]>liczba[i])
        {
            return false;
        }
        if (pot[i][x]<liczba[i])
        {
            return true;
        }
    }
    return true;
}
void odejmij(int x)
{
    int l1=liczba[0];
    int l2=pot[0][x];
    //printf ("liczba[0]=%d\n", liczba[0]);
    //test_liczba();
    for (int i=0; i<l2; i++)
    {
        //printf ("i=%d l1-i=%d l2-i=%d liczba[l1-i]=%d pot[l2-i][x]=%d\n", i, l1-i, l2-i, liczba[l1-i], pot[l2-i][x]);
        liczba[l1-i]-=pot[l2-i][x];
        if (liczba[l1-i]<0)
        {
            //puts ("POPRAW");
            liczba[l1-i-1]--;
            liczba[l1-i]+=10;
        }
        //printf ("liczba[l1-i]=%d\n", liczba[l1-i]);
    }
    //printf ("liczba[0]=%d\n", liczba[0]);
    int ile=0;
    for (int i=1; i<=103; i++)
    {
        if (liczba[i]==0)
        {
            ile++;
        }
        else
        {
            break;
        }
    }
    for (int i=ile+1; i<=103; i++)
    {
        liczba[i-ile]=liczba[i];
    }
    liczba[0]-=ile;
    //printf ("liczba[0]=%d\n", liczba[0]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int l=strlen(s);
    for (int i=0; i<l; i++)
    {
        liczba[i+1]=int(s[i])-48;
    }
    liczba[0]=l;
    //test_liczba();
    pot[1][0]=1;
    pot[0][0]=1;
    pot[1][1]=3;
    pot[0][1]=1;
    pot[1][2]=9;
    pot[0][2]=1;
    pot[1][3]=2;
    pot[2][3]=7;
    pot[0][3]=2;
    pot[1][4]=8;
    pot[2][4]=1;
    pot[0][4]=2;
    //test_liczba();
    for (int i=5; i<=210; i++)
    {
        calc(i);
    }
    //test_liczba();
    //test_pot();
    int wsk=209;
    //test_liczba();
    while (wsk>=0)
    {
        if (niemniejszy(wsk)==true)
        {
            //printf ("WSK=%d\n", wsk);
            rt[wsk]++;
            odejmij(wsk);
            //test_liczba();
        }
        else
        {
            wsk--;
        }
    }
    //for (int i=0; i<=210
    for (int i=0; i<=210; i++)
    {
        if (rt[i]>2)
        {
            rt[i]-=3;
            rt[i+1]++;
        }
        if (rt[i]==1)
        {
            //printf ("CASE 1 i=%d\n", i);
            prawy[i]=true;
            ip++;
        }
        else if (rt[i]==2)
        {
            //printf ("CASE 2 i=%d\n", i);
            rt[i+1]++;
            il++;
            lewy[i]=true;
        }
    }
    printf ("%d ", il);
    for (int i=0; i<=210; i++)
    {
        if (lewy[i]==true)
        {
            for (int j=1; j<=pot[0][i]; j++)
            {
                printf ("%d", pot[j][i]);
            }
            printf (" ");
        }
    }
    puts ("");
    printf ("%d ", ip);
    for (int i=0; i<=210; i++)
    {
        if (prawy[i]==true)
        {
            for (int j=1; j<=pot[0][i]; j++)
            {
                printf ("%d", pot[j][i]);
            }
            printf (" ");
        }
    }
    return 0;
}
 
Nim z utrudnieniem:
#include <bits/stdc++.h>
using namespace std;
 
#define zakres 1048580
#define mn 500010
#define MOD 1000000007
 
int n,d,r;
int tab[mn];
int wyn[10][zakres];
int dp[10][2];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    for (int i=1; i<=n; i++)
    {
        cin >> tab[i];
    }
    sort (tab+1, tab+1+n);
    r=1;
    wyn[0][0]=1;
    for (int u=1; u<=n; u++)
    {
        while (r<=tab[u])
        {
            r*=2;
        }
        for (int j=0; j<r; j++)
        {
            if ((j^tab[u])>j)
            {
                for (int i=0; i<d; i++)
                {
                    dp[i][0]=wyn[i][j^tab[u]]+wyn[(i-1+d)%d][j];
                    dp[i][1]=wyn[i][j]+wyn[(i-1+d)%d][j^tab[u]];
                    dp[i][0]%=MOD;
                    dp[i][1]%=MOD;
                }
                    for (int i=0; i<d; i++)
                {
                    wyn[i][j]=dp[i][0];
                    wyn[i][j^tab[u]]=dp[i][1];
                }
            }
        }
    }
    if (n%d==0)
    {
        printf ("%d\n", (wyn[0][0]-1+MOD)%MOD);
    }
    else
    {
        printf ("%d\n", wyn[0][0]);
    }
    return 0;
}

 
Marsjañskie mapy:
#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 10005
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define zakres 65536
#define endl puts("")
 
int n, xa, xb, ya, yb, r, q, gdzie, a, b, c, d, maxx;
vector <pair <pair <int, int>, pair <int, int> > > v;
int tree[zakres], akt[zakres], ile[zakres];
int wynik;
 
void insert(int x, int pp, int pk, int zp, int zk, int war)
{
    //printf ("x=%d pp=%d pk=%d zp=%d zk=%d war=%d\n", x, pp, pk, zp, zk, war);
    if (zk<pp || pk<zp)
    {
        return;
    }
    if (zp<=pp && pk<=zk)
    {
        //printf ("BAZOWY x=%d pp=%d pk=%d\n", x, pp, pk);
        if (war==1)
        {
            ile[x]++;
            tree[x]=pk-pp+1;
        }
        else
        {
            ile[x]--;
            if (ile[x]==0)
            {
                tree[x]=0;
            }
        }
        if (x<r)
        {
            if (ile[x]>0)
            {
                tree[x]=max(tree[x], tree[2*x]+tree[2*x+1]);
            }
            else
            {
                tree[x]=tree[2*x]+tree[2*x+1];
            }
        }
        //printf ("x=%d tree[x]=%d--------------------------------------\n", x, tree[x]);
        return;
    }
    int sr=(pp+pk)/2;
    insert (2*x, pp, sr, zp, zk, war);
    insert (2*x+1, sr+1, pk, zp, zk, war);
    if (x<r)
    {
        if (ile[x]>0)
        {
            tree[x]=max(tree[x], tree[2*x]+tree[2*x+1]);
        }
        else
        {
            tree[x]=tree[2*x]+tree[2*x+1];
        }
    }
    //printf ("x=%d tree[x]=%d-------------------------------------\n", x, tree[x]);
}
void dolicz_bez()
{
    wynik+=(q-gdzie)*tree[1];
    //printf ("DOLICZ BEZ a=%d     gdzie=%d q=%d (q-gdzie)=%d ile[1]=%d wynik=%d\n", a, gdzie, q, q-gdzie, tree[1], wynik);
    gdzie=q;
}
void dolicz_z()
{
    wynik+=(q-gdzie+1)*tree[1];
    //printf ("DOLICZ Z a=%d     gdzie=%d q=%d (q-gdzie+1)=%d ile[1]=%d wynik=%d\n", a, gdzie, q, q-gdzie+1, tree[1], wynik);
    gdzie=q+1;
}
void test_tree()
{
    for (int i=1; i<2*r; i++)
    {
        printf ("i=%d tree[i]=%d ile[i]=%d akt[i]=%d\n", i, tree[i], ile[i], akt[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    r=32768;
    for (int i=1; i<=n; i++)
    {
        cin >> xa >> ya >> xb >> yb;
        xa++;
        ya++;
        v.pb(mp(mp(xa, 0), mp(ya, yb)));
        v.pb(mp(mp(xb, 1), mp(ya, yb)));
        maxx=max(maxx, max(xa, xb));
    }
    sort (v.begin(), v.end());
    for (int i=0; i<2*n; i++)
    {
        if (tree[1]==0)
        {
            gdzie=v[i].ff.ff;
        }
        a=v[i].ff.ff;
        b=v[i].ff.ss;
        c=v[i].ss.ff;
        d=v[i].ss.ss;
        q=a;
        //printf ("a=%d b=%d c=%d d=%d\n", a, b, c, d);
        if (i>0 && a!=v[i-1].ff.ff && b==0)
        {
            dolicz_bez();
        }
        if (i>0 && a!=v[i-1].ff.ff && b==1)
        {
            dolicz_z();
        }
        if (i>0 && b==1 && v[i-1].ff.ss==0)
        {
            dolicz_z();
        }
        if (b==0)
        {
            insert(1, 1, r, c, d, 1);
        }
        else
        {
            insert(1, 1, r, c, d, -1);
        }
        //endl;
        //test_tree();
        //endl;
        //endl;
        //endl;
    }
    printf ("%d\n", wynik);
    return 0;
}

Haker:

#include<bits/stdc++.h>

#define LOL 1000006

using namespace std;

typedef pair<int,int> pii;

int n, mak, poz, f, sum;
int kom[LOL], tab1[LOL];

deque <pii> kol;

void add (int a, int b)
{
//	cerr << "add():"<< a << " " << b << endl;
	
	while( !kol.empty()&&kol.back().first<a)
	{
		kol.pop_back();
	}
	
	kol.push_back(make_pair(a,b));
}

void rem ( int c)
{
	if(kol.front().second==c) kol.pop_front();
}

int main()
{
	scanf("%d", &n);
	f=n/2+n%2;
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &kom[i]);
		
		sum+=kom[i];
	}
	
	
	
	for(int i=0; i<n/2; ++i)
	{
		tab1[0]+=kom[i];
	}
	
	for(int i=1; i<n; ++i)
	{
		int a=i+n/2-1;
		if(a>=n) a=a%n;
		
		tab1[i]=tab1[i-1]-kom[i-1]+kom[a];
	}
	
	
		for(int i=0; i<(n/2+n%2); ++i)
	{
		add(tab1[i], i); 
		
	}
	
	mak=kol.front().first;
	poz=0;
	
	for(int i=1; i<n; ++i)
	{
		int a=i+f-1;
		if(a>=n) a=a%n;
		
		add(tab1[a], a);
		
		rem(i-1);
		
//		cerr << "i:" << i << " " << "mak:" << mak << "p:" << kol.front().first << "k:" << kol.back().first << endl;
		
		if(mak>kol.front().first)
		{
			mak=kol.front().first;
			poz=i;
		}
	}
	
	int wyn=0;
	
	
	
	if(poz==0) wyn=n-1;
	else wyn=poz-1;
	
	printf("%d", sum-mak);
	
}

Chrzaczsz:

#include <bits/stdc++.h>
using namespace std;

#define MAXN 305
#define endl puts("")

typedef long long int ll;

int INF=1000696969;
int n, m, s;
int tab[MAXN];
bool joker;
int p[MAXN][MAXN][2], l[MAXN][MAXN][2], cl[MAXN][MAXN][2], cp[MAXN][MAXN][2];
int wynik, dod;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> tab[i];
		if (tab[i]==0)
		{
			joker=true;
		}
	}
	dod=m;
	if (joker==false)
	{
		n++;
		tab[n]=0;
		dod=0;
	}
	sort (tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==0)
		{
			s=i;
		}
		//printf ("i=%d tab[i]=%d\n", i, tab[i]);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			for (int k=0; k<=n; k++)
			{
				p[i][j][k]=l[i][j][k]=INF;
			}
		}
	}
	p[s][s][0]=l[s][s][0]=0;
	for (int k=1; k<=n; k++)
	{
		int g=(k+1)%2;
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				p[i][j][k%2]=l[i][j][k%2]=INF;
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				if ((k==1 || j-1!=s) && p[i][j-1][g]+min(m, cp[i][j-1][g]+tab[j]-tab[j-1])<p[i][j][k%2])
				{
					//puts ("CASE 1");
					p[i][j][k%2]=min(p[i][j][k%2], p[i][j-1][g]+min(m, cp[i][j-1][g]+tab[j]-tab[j-1]));
					cp[i][j][k%2]=cp[i][j-1][g]+tab[j]-tab[j-1];
				}
				if ((k==1 || i!=s) && l[i][j-1][g]+min(m, cl[i][j-1][g]+tab[j]-tab[i])<p[i][j][k%2])
				{
					//puts ("CASE 2");
					p[i][j][k%2]=min(p[i][j][k%2], l[i][j-1][g]+min(m, cl[i][j-1][g]+tab[j]-tab[i]));
					cp[i][j][k%2]=cl[i][j-1][g]+tab[j]-tab[i];
				}
				if ((k==1 || j!=s) && p[i+1][j][g]+min(m, cp[i+1][j][g]+tab[j]-tab[i])<l[i][j][k%2])
				{
					//puts ("CASE 3");
					l[i][j][k%2]=min(l[i][j][k%2], p[i+1][j][g]+min(m, cp[i+1][j][g]+tab[j]-tab[i]));
					cl[i][j][k%2]=cp[i+1][j][g]+tab[j]-tab[i];
				}
				if ((k==1 || i+1!=s) && l[i+1][j][g]+min(m, cl[i+1][j][g]+tab[i+1]-tab[i])<l[i][j][k%2])
				{
					//puts ("CASE 4");
					l[i][j][k%2]=min(l[i][j][k%2], l[i+1][j][g]+min(m, cl[i+1][j][g]+tab[i+1]-tab[i]));
					cl[i][j][k%2]=cl[i+1][j][g]+tab[i+1]-tab[i];
				}
				wynik=max(wynik, k*m-p[i][j][k%2]+dod);
				wynik=max(wynik, k*m-l[i][j][k%2]+dod);
				//printf ("k=%d i=%d j=%d l[i][j][k]=%d cl[i][j][k]=%d     p[i][j][k]=%d cp[i][j][k]=%d wynik=%d\n", k, i, j, l[i][j][k%2], cl[i][j][k%2], p[i][j][k%2], cp[i][j][k%2], wynik);
			}
		}
	}
	printf ("%d\n", wynik);
	return 0;
