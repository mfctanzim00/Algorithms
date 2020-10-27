#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const ll mod = 1e9+7;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};
map<int, bool>vis;
vector<pair<int,int> >graph[mx];

ll Prims_Algorithm(int src)
{
    ll ret = 0;
    priority_queue<pair<int,int> >pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        int cost=pq.top().first*-1;
        int parent=pq.top().second;
        pq.pop();
        if(!vis[parent])
        {
            ret+=cost;
            for(auto x: graph[parent])
            {
                int child = x.first;
                int child_cost = x.second;
                pq.push({child_cost*-1, child});
            }
            vis[parent] = true;
        }
    }
    return ret;
}
int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int nodes, edges, t;
    cin >> nodes >> edges;
    while(edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << Prims_Algorithm(1) << endl;

    return 0;
}

