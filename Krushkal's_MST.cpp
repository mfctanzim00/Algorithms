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
const ll maxn = 1e6+7;

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
ll parent[maxn],mstValue=0, cnt=0;

bool compare(edge a, edge b)
{
    return a.w<b.w;
}

int Find(ll r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}

void initPar(ll r)
{
    for(ll i=0 ; i<r ; i++)
    {
        parent[i]=i;
    }
}
void kruskals_Algorithm(ll n)
{
    sort(graph.begin(), graph.end(), compare);
    initPar(n);
    for(ll i=0; i<graph.size() ; i++)
    {
        ll uPr=Find(graph[i].u);
        ll vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            output.pb(graph[i]);
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
            cnt++;
        }
    }

}


int main()
{
     FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, k, m, a, b, c, d;
    ll n, e;
    cin >> n >> e;

    for(ll i=0 ; i<e ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        edge input;
        input.u=u;
        input.v=v;
        input.w=w;
        graph.pb(input);
    }

    kruskals_Algorithm(n);
    if(cnt!=n-1){
               cout << "IMPOSSIBLE" << endl;
               return 0;
    }

    cout << mstValue << endl;

    return 0;
}
