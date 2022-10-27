/*
 * DWUKRYTERIALNY WYBÓR DROGI <-
 */
 
#include <bits/stdc++.h>

#define LOL 110
#define M 310
#define MAXC 10010
#define mp make_pair
#define f first
#define s second
#define INF INT_MAX - 2137
 
using namespace std;
 
typedef pair<int, int> pii;
 
struct Edge
{
    int from;
    int dir;
    int price;
    int time;
    Edge () {}
    Edge (int a, int b, int c) : dir(a), price(b), time(c) {}
    Edge (int a, int b, int c, int d) : from(a), dir(b), price(c), time(d) {}
    ~Edge () {}
};
 
int n, m, s, e;
int fastest;
int out;
 
vector<Edge> zero[LOL];
vector<Edge> non_zero;
 
int dp[LOL][MAXC]; 
int dist[LOL]; 
int gd(int x, int c)
{
    if(c < 0) return INF;
    return dp[x][c];
}
 
void sd (int x, int c, int val)
{
    dp[x][c] = val;
}
 
priority_queue<pii> q;
 
void dijkstra (int k)
{
    for(int i = 1; i <= n; i++)
    {
        dist[i] = gd(i, k);
        q.push(mp(-dist[i], i));
    }
    while(!q.empty())
    {
        pii tmp = q.top();
        q.pop();
        for(Edge e : zero[tmp.s])
        {
            int u = e.dir;
            if(dist[u] > -tmp.f + e.time)
            {
                dist[u] = -tmp.f + e.time;
                q.push(mp(-dist[u], u));
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        sd(i, k, dist[i]);
    }
}
 
void setup ()
{
    for(int k = 0; k < MAXC; k++)
    {
        for(int x = 1; x <= n; x++)
        {
            dp[x][k] = INF;
        }
    }
    sd(s, 0, 0);
}
 
void fix (int k)
{
    for(Edge e : non_zero)
    {
        if(gd(e.dir, k) > gd(e.from, k - e.price) + e.time)
        {
            sd(e.dir, k, get_dist(e.from, k - e.price) + e.time);
        }
    }
}
 
int main ()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);
    setup();
    for(int i = 1; i <= m; i++)
    {
        int p, r, c, t;
        scanf("%d%d%d%d", &p, &r, &c, &t);
        if(c == 0)
        {
            zero[p].push_back(Edge(r, c, t));
            zero[r].push_back(Edge(p, c, t));
            continue;
        }
        non_zero.push_back(Edge(p, r, c, t));
        non_zero.push_back(Edge(r, p, c, t));
    }
    dijkstra(0);
    if(get_dist(e, 0) != INF) ++out, fastest = get_dist(e, 0);
    else fastest = INF;
    for(int k = 1; k < MAXC; k++)
    {
//      cerr << "BEGIN K: " << k << endl;
        for(int i = 1; i <= n; i++) set_dist(i, k, INF);
        fix(k);
        dijkstra(k);
        if(get_dist(e, k) < fastest)
        {
            ++out;
            fastest = get_dist(e, k);
        }
    }
    printf("%d\n", out);
}
 
/*
 * MARSJAÑSKIE MAPY
 */
 
#include <bits/stdc++.h>
#define N 10010
#define RANGE 1<<17
 
using namespace std;
 
struct Op
{
    int x;
    int y_b;
    int y_e;
    int val;
    Op () {}
    Op (int a, int b, int c, int d) : x(a), y_b(b), y_e(c), val(d) {}
    ~Op () {}
    bool operator< (const Op &a) const
    {
        return this->x > a.x;
    };
};
 
priority_queue<Op> q;
int n;
int tree[RANGE];
int sub[RANGE];
int *drzewo = tree;
int out;
int starter = 1<<15;
 
void tree_update (int x, int range)
{
    if(tree[x] != 0)
    {
        sub[x] = range;
    }
    else
    {
        if(range == 1) sub[x] = 0;
        else sub[x] = sub[2 * x] + sub[2 * x + 1];
    }
}
 
void tree_insert (int pp, int pk, int zp, int zk, int x, int v)
{
    if(pp > zk || pk < zp) return;
    if(pp >= zp && pk <= zk)
    {
        tree[x] += v;
        tree_update(x, pk - pp + 1);
        return;
    }
    int mp = (pp + pk) >> 1;
    tree_insert(pp, mp, zp, zk, 2 * x, v);
    tree_insert(mp + 1, pk, zp, zk, 2 * x + 1, v);
    tree_update(x, pk - pp + 1);
}
 
void input ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ++b;
        ++d;
        q.push(Op(a, b, d - 1, 1));
        q.push(Op(c, b, d - 1, -1));
    }
}
 
void solve ()
{
    int curr_x = q.top().x;
    int prev_x = q.top().x;
    while(!q.empty())
    {
        prev_x = curr_x;
        curr_x = q.top().x;
        out += sub[1] * (curr_x - prev_x);
        while(!q.empty() && q.top().x == curr_x)
        {
            Op curr = q.top();
//          cout << curr.x << " " << curr.y_b << " " << curr.y_e << " " << curr.val << endl;
            tree_insert(1, starter, curr.y_b, curr.y_e, 1, curr.val);
            q.pop();
        }
    }
    printf("%d\n", out);
}
 
int main ()
{
    input();
    solve();
}
 
/*
 * HAKER
 */
 
#include <bits/stdc++.h>
#define N 1<<20
 
using namespace std;
 
int n;
int komputery[N];
int prefix[N];
int tree[N];
int starter = 1;
 
int suma (int a, int b)
{
//  a--;
//  b--;
//  a %= n;
//  b %= n;
//  a++;
//  b++;
    if(a > n) a -= n;
    if(b > n) b -= n;
    if(a > b)
    {
        return prefix[n] - prefix[a - 1] + prefix[b];
    }
    else
    {
        return prefix[b] - prefix[a - 1];
    }
}
 
void prep_tree ()
{
    while(starter < n) starter <<= 1;
    for(int i = 1; i <= n; i++)
    {
        int sum = suma(i, i + n/2 - 1);
//      cout << sum << " " << i << " " << i + n/2 - 1 << endl;
        tree[starter + i - 1] = sum;
//      cout << tree[starter + i - 1] << " ";
    }
    for(int i = starter - 1; i > 0; i--)
    {
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
}
 
int query (int zp, int zk, int pp, int pk, int w)
{
/// cerr << zp << " " << zk << " " << pp << " " << pk << " " << w << " " << tree[w] << endl;
    if(zp > pk || zk < pp) return 0;
    if(zp >= pp && zk <= pk) return tree[w];
    int midpoint = (zp + zk) >> 1;
    int syn1 = 0;
    if(!(midpoint < pp)) syn1 = query(zp, midpoint, pp, pk, w * 2);
    int syn2 = 0;
    if(!(midpoint + 1 > pk)) syn2 = query(midpoint + 1, zk, pp, pk, w * 2 + 1);
    return max(syn1, syn2);
}
 
int zapytaj (int a, int b)
{
//  a--;
//  b--;
//  a %= n;
//  b %= n;
//  a++;
//  b++;
//  cout << "kolejnezapytanie" << a << " " << b << endl;
    if(a > n) a -= n;
    if(b > n) b -= n;
    if(a > b)
    {
        return max(query(1, starter, a, n, 1), query(1, starter, 1, b, 1));
    }
    else
    {
        return query(1, starter, a, b, 1);
    }
}
 
void solve ()
{
    int _min = INT_MAX;
    if(n == 1) _min = 0;
    for(int i = 1; i <= n; i++)
    {
//      cout << zapytaj(i + 1, i + n/2) << ": ZAPYTANIE" << " ";
        int qu = zapytaj(i + 1, i + n/2 + n%2);
        _min = min(_min, qu);
//      cout << i << " " << qu << endl;
//      cout << i << " " << _min << " " << i + 1 << " " << i + n/2 << endl;
    }
    printf("%d\n", prefix[n] - _min);
}
 
int main ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &komputery[i]);
        prefix[i] = prefix[i - 1] + komputery[i];
    }
    prep_tree();
    solve();
}
 
/*
 * OGRANICZENIA PRÊDKOŒCI
 */
 
#include <bits/stdc++.h>
#define N 160
#define V 510
#define L 510
#define mp make_pair
#define f first
#define s second
 
using namespace std;
 
typedef long double ld;
typedef pair< int, pair<int, int> > pild;
typedef pair<ld, int> pldi;
typedef pair<int, int> pii;
 
vector<pild> vec[N];
vector<int> zeroes[N];
ld zerodist[N][N];
ld dist[151000];
int father[151000];
 
ld one = 1;
 
int n, m, d;
 
priority_queue<pldi> q;
stack<int> road;
 
void dijkstra ()
{
    for(int i = 0; i < 151000; i++)
    {
        dist[i] = 21372137;
    }
    dist[70] = 0;
    q.push(mp(0, 70));
    while(!q.empty())
    {
        pldi curr = q.top();
        q.pop();
//      cerr << curr.s << endl;
        if(curr.s / 1000 == d)
        {
            int vert = curr.s;
            while(vert != 70)
            {
                road.push(vert / 1000);
                vert = father[vert];
            }
            printf("0 ");
            while(!road.empty())
            {
                printf("%d ", road.top());
                road.pop();
            }
            printf("\n");
            return;
        }
        for(pild x : vec[curr.s / 1000])
        {
            int u = x.f;
            u = 1000 * u + x.s.s;
            if(dist[u] > -curr.f + (ld)((one * x.s.f) / (one * x.s.s)))
            {
                father[u] = curr.s;
                dist[u] = -curr.f + (ld)((one * x.s.f) / (one * x.s.s));
                q.push(mp(-dist[u], u));
            }
        }
        int speed = curr.s - ((curr.s / 1000) * 1000);
        for(int u : zeroes[curr.s / 1000])
        {
            u = 1000 * u + speed;
            if(dist[u] > -curr.f + zerodist[curr.s / 1000][u / 1000] / speed)
            {
                father[u] = curr.s;
                dist[u] = -curr.f + zerodist[curr.s / 1000][u / 1000] / speed;
                q.push(mp(-dist[u], u));
            }
        }
    }
}
 
int main ()
{
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        int v, l;
        scanf("%d%d%d%d", &a, &b, &v, &l);
        if(v != 0)
        {
            vec[a].push_back(mp(b, mp(l, v)));
        }
        else
        {
            zeroes[a].push_back(b);
            zerodist[a][b] = l;
        }
    }
    dijkstra();
}
 
/*
 * TRÓJK¥TY - WIP, 18 PKT
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
struct Plaster
{
    int x;
    int y;
    int wysokosc;
    Plaster () {}
    Plaster (int a, int b, int c) : x(a), y(b), wysokosc(c) {}
    ~Plaster () {}
    bool operator< (const Plaster &a) const
    {
        return this->x > a.x;
    }
};
 
struct Op
{
    int y;
    int typ; // poczatek - 1, koniec - 2
    Op () {}
    Op (int a, int b) : y(a), typ(b) {}
    ~Op () {}
    bool operator< (const Op &a) const
    {
        if(this->y == a.y)
        {
            return this->typ < a.typ;
        }
        return this->y < a.y;
    }
};
 
int n;
long double out;
 
priority_queue<Plaster> q;
 
multiset<Op> s;
 
void input ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for(int i = 0; i < c; i++)
        {
            q.push(Plaster(a + i, b, c - i));
        }
    }
}
 
void solve ()
{
    int curr_x;
    while(!q.empty())
    {
        curr_x = q.top().x;
//      cout << curr_x << ": " << endl;
        while(!q.empty() && q.top().x == curr_x)
        {
            Plaster curr = q.top();
            q.pop();
            s.insert(Op(curr.y, 1));
            s.insert(Op(curr.y + curr.wysokosc - 1, 2));
        }
        int curr_rectangles = 0;
        int prev_y = s.begin()->y;
        while(!s.empty())
        {
            Op curr = *(s.begin());
            s.erase(s.begin());
//          cout << " " << curr.y << " " << curr.typ << endl;
            if(curr_rectangles > 0) out += curr.y - prev_y;
            prev_y = curr.y;
            if(curr.typ == 1)
            {
                curr_rectangles++;
            }
            else
            {
                curr_rectangles--;
                if(curr_rectangles == 0) out += 0.5;
            }
        }
    }
    cout << out << endl;
}
 
int main ()
{
    input();
    solve();
}
 
/*
 * PROSTOK¥T
 */
 
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define N 1510
 
using namespace std;
 
typedef pair<long long, long long> pii;
 
set<pii> s;
 
short quad (pii a)
{
    if(a.s > 0)
    {
        if(a.f > 0) return 1;
        else if(a.f == 0) return 2;
        else return 3;
    }
    else if(a.s == 0)
    {
        if(a.f > 0) return 0;
        else if(a.f == 0) __builtin_unreachable();
        else return 4;
    }
    else
    {
        if(a.f > 0) return 7;
        else if(a.f == 0) return 6;
        else return 5;
    }
}
 
inline int sign (long long a)
{
    return (a > 0) - (a < 0);
}
 
long long cpr (pii a, pii b)
{
    return (1LL * b.f * a.s) - (1LL * a.f * b.s);
}
 
long long scal (pii a, pii b)
{
    return (a.f * b.f) + (a.s * b.s);
}
 
bool cmp (pii a, pii b)
{
    if(quad(a) != quad(b)) return quad(a) < quad(b);
    long long c = cpr(a, b);
    if(c == 0)
    {
        if(a.f == 0) return abs(a.s) < abs(b.s);
        return abs(a.f) < abs(b.f);
    }
    else if(sign(c) == -1) return 1;
    return 0;
}
 
pii points[N];
int n;
vector<pii> v;
long long out;
 
int main ()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        points[i] = mp(a, b);
        s.insert(points[i]);
    }
    for(int i = 0; i < n; i++)
    {
        v.clear();
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            v.push_back(mp(points[j].f - points[i].f, points[j].s - points[i].s));
        }
        sort(v.begin(), v.end(), cmp);
        for(int j = 0; j < n - 1; j++)
        {
            v.push_back(v[j]);
        }
        v.push_back(mp(21, 37));
        int k = 0;
        for(int j = 0; j < n - 1; j++)
        {
            while(k <= 2 * n - 3 && sign(scal(v[j], v[k + 1])) >= 0)
            {
                ++k;
                if(sign(scal(v[j], v[k]) != 0)) continue;
                pii dir = mp(v[j].f + v[k].f + points[i].f, v[j].s + v[k].s + points[i].s);
                if(s.find(dir) != s.end()) out = max(out, abs(cpr(v[j], v[k])));
            }
        }
        k = v.size() - 2;
        for(int j = v.size() - 2; j >= n; j--)
        {
            while(k >= 1 && sign(scal(v[j], v[k - 1])) >= 0)
            {
                --k;
                if(sign(scal(v[j], v[k])) != 0) continue;
                pii dir = mp(v[j].f + v[k].f + points[i].f, v[j].s + v[k].s + points[i].s);
                if(s.find(dir) != s.end()) out = max(out, abs(cpr(v[j], v[k])));
            }
        }
 
    }
   printf("%lld\n", out);
}
 
/*
 * TRÓJK¥TY JEDNOBARWNE
 */
 
#include <bits/stdc++.h>
#define N 1010
 
using namespace std;
 
int n, m;
int ile[N];
int out;
 
int main ()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ile[a]++;
        ile[b]++;
    }
    for(int i = 1; i <= n; i++)
    {
        out += (n - 1 - ile[i]) * ile[i];
    }
    out /= 2;
    out = ((n) * (n - 1) * (n - 2)) / 6 - out;
    printf("%d\n", out);
}
