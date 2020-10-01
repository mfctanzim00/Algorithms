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
const ll mx = 2e5+10;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
vector<int>graph[mx], ret;
bool found = false, ok = false;
int last_node = -1, vis[mx];

void Dfs(int src)
{
    vis[src] = true;
    for(auto x: graph[src]){
              if(!vis[x]){
                       Dfs(x);
              }
              else{
                       ret.pb(x);
                       ret.pb(src);
                       last_node = x;
                       return;
              }
              if(found){
                       return;
              }
              if(~last_node){
                       ret.pb(src);
                       if(src==last_node){
                                 found = true;
                       }
                       return;
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

    int n, e;
    cin >> n >> e;
    while(e--){
             int a, b;
             cin >> a >> b;
             graph[a].pb(b);
    }
    for(int i=1; i<=n&&!found; i++){
             ret.clear();
             if(!vis[i]){
                      Dfs(i);
             }
    }
    if(!found){
             cout << "IMPOSSIBLE" << '\n';
    }
    else{
             cout << ret.size() << '\n';
             reverse all(ret);
             for(auto x: ret){
                        cout << x << " ";
             }
             cout << '\n';
    }

    return 0;
}
