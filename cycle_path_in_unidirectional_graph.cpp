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
vector<int>vis(mx), graph[mx], ok(mx);
stack<int>st;

bool Dfs(int src)
{
    vis[src]=true;
    ok[src]=true;
    st.push(src);

    for(auto x: graph[src]){
             if(!vis[x]){
                    if(Dfs(x)){
                           return true;
                    }
             }
             if(ok[x]){
                    st.push(x);
                    return true;
             }
    }
    ok[src]=false;
    st.pop();

    return false;
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, m, u, v;
    //cin >> t;

    while(t--){
            cin >> n >> m;
            for(int i=1; i<=m; i++){
                     cin >> u >> v;
                     graph[u].pb(v);
            }

            for(int i=1; i<=n; i++){
                     if(!vis[i]){
                            if(Dfs(i)){
                                   break;
                            }
                     }
            }

            if(st.empty()){
                     cout << "IMPOSSIBLE" << endl;
                     continue;
            }

            vector<int>path;
            int tmp=st.top();
            while(!st.empty()){
                    path.pb(st.top());
                    st.pop();

                    if(path.size()>1&&path.back()==tmp)
                           break;
            }
            reverse all(path);
            cout << path.size() << endl;
            for(auto x: path)cout << x << " ";
            cout << endl;
    }
    return 0;
}
