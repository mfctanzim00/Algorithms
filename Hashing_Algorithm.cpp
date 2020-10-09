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

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
ll pw[mx];
ll HASH[mx];
const int base = 6091; ///any prime

void pre_calc()
{
    pw[0] = 1;
    for(int i=1; i<mx; i++)
        pw[i] = (pw[i-1]*base)%mod;
}
ll get_hashval(string str)
{
    int len=str.length();
    ll hash_val=0;
    for(int i=0; i<len; i++)
    {
        hash_val=((hash_val*base)+str[i])%mod;
        HASH[i+1]=hash_val;
    }
    return hash_val;
}
ll get_hashval2(string str)
{
    int len=str.length();
    ll hash_val=0;
    for(int i=0; i<len; i++)
    {
        hash_val=((hash_val*base)+str[i])%mod;
    }
    return hash_val;
}
ll SubstringHash(int l, int r)
{
    return (HASH[r] - (HASH[l-1]*pw[r-l+1])%mod + mod) % mod;
}

int main()
{
     FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    pre_calc();
    string str, pattern;
    cin >> str >> pattern;

    ll str_len = str.size();
    ll pattern_len = pattern.size();
    ll str_hash = get_hashval(str);
    ll pattern_hash = get_hashval2(pattern);
    ll ret = 0;

    for(ll i=1; i+pattern_len-1<=str_len; i++){
               ll x = SubstringHash(i, i+pattern_len-1);
               if(x==pattern_hash){
                          ret++;
               }
    }
    cout << ret << endl;

    return 0;
}
/*
Main String: saippuakauppias
Pattern String:  pp

The Number of occurences of pattern_string in the main_string is : 2

Output: 2
*/
