/*
     Problem Link : http://lightoj.com/volume_showproblem.php?problem=1074
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
ll arr[1000], dis[1000], edges, nodes, query, cs;

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
                dis[graph[i].v] = dis[graph[i].u]+graph[i].cost;
            }
        }
    }
    /*for(ll i=0; i<graph.size(); i++)
    {
        if(dis[graph[i].u]+graph[i].cost<dis[graph[i].v])
        {
            ///return Neg_cycle_Found
        }
    }
    */
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    ll t, u, v, w;
    scanf("%lld", &t);

    while(t--)
    {
        graph.clear();
        scanf("%lld", &nodes);
        for(ll i=1; i<=nodes; i++)
            cin >> arr[i];

        scanf("%lld", &edges);
        for(ll i=1; i<=edges; i++)
        {
            scanf("%lld %lld", &u, &v);
            w = arr[v]-arr[u];
            Info edge;
            edge.u = u;
            edge.v = v;
            edge.cost=w*w*w;
            graph.pb(edge);
        }

        Bellman_Ford(1);

        scanf("%lld", &query);
        printf("Case %lld:\n", ++cs);

        while(query--)
        {
            scanf("%lld", &v);
            if(dis[v]<3 || dis[v]==1e18)
                printf("?\n");
            else
                printf("%lld\n", dis[v]);
        }
    }

    return 0;
}
