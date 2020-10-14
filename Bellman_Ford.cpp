/*
      Problem Link : https://cses.fi/problemset/task/1197/
*/

#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define  ll        long long
#define  ull       unsigned long long
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  all(v)    (v.begin(), v.end())
#define  pi        acos(-1.0)
#define  FastRead  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define  bug(a)    cerr << #a << " : " << a << endl
using namespace std;
const ll mx = 2e5+10;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

struct Info
{
    ll u, v, cost;
};
vector<Info>graph;

ll parent[3000], dis[3000], edges, nodes, query, src;
bool Neg_cycle;

void Bellman_Ford(ll src)
{
    for(ll i=1; i<=nodes; i++)
    {
        dis[i]=1e18;
    }
    dis[src]=0;
    for(ll j=1; j<nodes; j++)
    {
        for(ll i=0; i<graph.size(); i++)
        {
            if(dis[graph[i].u]+graph[i].cost<dis[graph[i].v])  ///Relaxation
            {
                dis[graph[i].v] = dis[graph[i].u]+graph[i].cost; ///updating distance
                parent[graph[i].v] = graph[i].u;                 ///updating parent
            }
        }
    }
    for(ll i=0; i<graph.size(); i++)
    {
        if(dis[graph[i].u]+graph[i].cost<dis[graph[i].v])    ///Relaxation
        {
            src = graph[i].v;
            Neg_cycle = true;
            dis[graph[i].v] = dis[graph[i].u]+graph[i].cost; ///updating distance
            parent[graph[i].v] = graph[i].u;                 ///updating parent
        }
    }
    if(!Neg_cycle)
        printf("NO\n");
    else
    {
        printf("YES\n");

        for(ll i=0; i<graph.size(); i++)
            src = parent[src];

        vector<ll>path;
        for(ll node=src; ;node=parent[node])
        {
            path.pb(node);
            if(node==src&&path.size()>1)
                break;
        }

        reverse all(path);
        for(auto x: path)
            printf("%lld ", x);
    }

}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    ll t, u, v, w;
    scanf("%lld %lld", &nodes, &edges);

    for(ll i=0; i<edges; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        Info edge;
        edge.u = u;
        edge.v = v;
        edge.cost = w;
        graph.pb(edge);
    }

    Bellman_Ford(1);

    return 0;
}
