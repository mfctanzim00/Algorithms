/*
     Problem Link: https://cses.fi/problemset/task/1734
*/
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
const ll mx = 1e6+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
int arr[200009], res[200009], mp[200009];
vector<pair<int, pair<int, int> > > mo;
vector<pair<int, int> >arr2;
int left_pos, right_pos, cnt, c, sz = 1000;

void add(int x)
{
    if(!mp[x])
        cnt ++;
    mp[x]++;
}
void del(int x)
{
    mp[x]--;
    if(!mp[x])
        cnt--;
}
int query(int l,int r)
{
    while(right_pos < r)
    {
        right_pos++;
        add(arr[right_pos]);
    }
    while(right_pos > r)
    {
        del(arr[right_pos]);
        right_pos--;
    }
    while(left_pos < l)
    {
        del(arr[left_pos]);
        left_pos++;
    }
    while(left_pos > l)
    {
        left_pos--;
        add(arr[left_pos]);
    }
    return cnt;
}
bool cmp(const pair<int, pair<int, int> >a, const pair<int, pair<int, int> >b)
{
    if((a.ff/sz)<(b.ff/sz))
        return 1;
    if((a.ff/sz)>(b.ff/sz))
        return 0;
    if(a.ss.ff<b.ss.ff)
        return 1;
    else
        return 0;
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, m, a, b, c, d;
    //cin >> t;

    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a);
            arr2.pb({a, i});
        }
        sort (arr2.begin(), arr2.end());

        ///Array_Compression
        arr[arr2[0].ss] = ++c;
        for(int i=1; i<n; i++)
        {
            if(arr2[i].ff!=arr2[i-1].ff)
            {
                    arr[arr2[i].ss] = ++c;
            }
            else{
                    arr[arr2[i].ss] = arr[arr2[i-1].ss];
            }
        }

        ///MO's Algorithm
        for(int i=1; i<=k; i++)
        {
            scanf("%d %d", &a, &b);
            mo.pb({a, {b, i}});
        }
        sort (mo.begin(), mo.end(), cmp);

        left_pos = mo[0].ff, right_pos = mo[0].ss.ff;
        for(int i=left_pos; i<=right_pos; i++)
        {
            add(arr[i]);
        }
        res[mo[0].ss.ss] = cnt;
        for(int i=1; i<mo.size(); i++)
        {
            res[mo[i].ss.ss]=query(mo[i].ff, mo[i].ss.ff);
        }
        for(int i=1; i<=k; i++)
        {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}
