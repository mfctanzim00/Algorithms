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
vector<int>euler_path, graph[mx];
ll st[mx], en[mx], tree[4*mx], val[mx];
 
void Dfs(int src, int par)
{
    euler_path.pb(src);
    bool ok=false;
    for(auto x: graph[src]){
             if(x==par)
                   continue;
             ok=true;
             Dfs(x, src);
    }
    if(ok)euler_path.pb(src);
}
 
void init_euler()
{
    Dfs(1, 0);
    int idx=1;
    for(auto x: euler_path){
            if(st[x]==0)
                  st[x]=idx;
            en[x]=idx;
            idx++;
    }
}
 
void update(int idx, int n, ll val)
{
    while(idx<=n){
             tree[idx]+=val;
             idx+=(idx&(-idx));
    }
}
 
ll query(int idx)
{
    ll sum=0;
    while(idx>0){
            sum+=tree[idx];
            idx-=(idx&(-idx));
    }
    return sum;
}
 
int main()
{
    FastRead
 
#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim
 
    ll t=1, n, q, type, s, v, u;
    //cin >> t;
 
    while(t--){
            cin >> n >> q;
            for(int i=1; i<=n; i++){
                     cin >> val[i];
            }
            for(int i=1; i<n; i++){
                     cin >> u >> v;
                     graph[u].pb(v);
                     graph[v].pb(u);
            }
 
            init_euler();
 
            for(ll i=1; i<=n; i++){
                      update(st[i], euler_path.size(), val[i]);
            }
 
            for(ll i=1; i<=q; i++){
                     cin >> type;
                     if(type==1){
                              cin >> s >> v;
                              update(st[s], euler_path.size(), -val[s]);
                              val[s]=v;
                              update(st[s], euler_path.size(), val[s]);
                     }
                     else{
                              cin >> s;
                              cout << (query(en[s])-query(st[s]))+val[s] << endl;
                     }
            }
    }
    return 0;
}
