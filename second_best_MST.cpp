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

vector<edge>graph, output;
ll parent[maxn],mstValue=0, cnt=0, mp[maxn], cs;

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
    for(ll i=0 ; i<=r ; i++)
        parent[i]=i;
}
void kruskals_Algorithm(ll n)
{
    sort(graph.begin(), graph.end(), compare);
    initPar(n);
    cnt = mstValue = 0;
    for(ll i=0; i<graph.size() ; i++)
    {
        ll uPr=Find(graph[i].u);
        ll vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            mp[cnt++] = i;
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
        }
    }

}

ll Krushkals_2(ll n, ll m, ll mark)
{
    initPar(n);
    mstValue = 0;
    ll c=0;
    for(ll i=0; i<graph.size() ; i++)
    {
        if(mark==i)continue;

        ll uPr=Find(graph[i].u);
        ll vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            if(c==n-1)
                break;
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
            c++;
        }
    }
    return c==n-1?mstValue: INT_MAX;
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
    cin >> t;

    while(t--)
    {
        cin >> n >> e;
        graph.clear();
        for(ll i=0 ; i<e ; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            u--,v--;

            edge input;
            input.u=u;
            input.v=v;
            input.w=w;
            graph.pb(input);
        }

        kruskals_Algorithm(n);
        cout << "Case #" << ++cs << " : ";

        if(cnt!=n-1)
        {
            cout << "No way" << endl;
            continue;
        }
        ll second_MST = INT_MAX;
        for(ll i=0; i<cnt; i++)
        {
            ll tmp = Krushkals_2(n, e, mp[i]);
            second_MST = min(second_MST, tmp);
        }
        if(second_MST==INT_MAX) cout << "No second way" << endl;
        else cout << second_MST << endl;
    }
    return 0;
}
