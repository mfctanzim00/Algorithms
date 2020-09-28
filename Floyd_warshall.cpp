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
ll graph[600][600];

void warshal()
{
    ll nodes, edges, a, b, c, query;
    for(int i=0; i<600; i++)
    {
        for(int j=0; j<600; j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=1e18;
        }
    }
    scanf("%lld %lld %lld", &nodes, &edges, &query);
    while(edges--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    /*for(i=1; i<=nodes; i++)
    {
        for(j=1; j<=nodes; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }*/

    for(int k=1; k<=nodes; k++)
    {
        for(int i=1; i<=nodes; i++)
        {
            for(int j=1; j<=nodes; j++)
            {
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    while(query--)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", graph[a][b]==1e18?-1: graph[a][b]);
    }
}
int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    int n, m, u, v, w, src, tar, q;
    warshal();

    return 0;
}

