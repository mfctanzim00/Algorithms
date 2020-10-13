/*
     problem link : https://cses.fi/problemset/task/1652/
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
int res[200009];
int row[2000][2000], col[2000][2000];
int sz = 1000, cnt, X1, X2, Y1, Y2;
char ch[2000][2000];

struct Info
{
    ll x1, x2, y1, y2, idx;
} mo[200009];

int query(int x1,int y1,int x2,int y2)
{
    while(X1<x1)
    {
        cnt-=row[X1][Y2]-row[X1][Y1-1];
        X1++;
    }
    while(X1>x1)
    {
        X1--;
        cnt+=row[X1][Y2]-row[X1][Y1-1];
    }
    while(X2<x2)
    {
        X2++;
        cnt+=row[X2][Y2]-row[X2][Y1-1];
    }
    while(X2>x2)
    {
        cnt-=row[X2][Y2]-row[X2][Y1-1];
        X2--;
    }
    while(Y1<y1)
    {
        cnt-=col[X2][Y1]-col[X1-1][Y1];
        Y1++;
    }
    while(Y1>y1)
    {
        Y1--;
        cnt+=col[X2][Y1]-col[X1-1][Y1];
    }
    while(Y2<y2)
    {
        Y2++;
        cnt+=col[X2][Y2]-col[X1-1][Y2];
    }
    while(Y2>y2)
    {
        cnt-=col[X2][Y2]-col[X1-1][Y2];
        Y2--;
    }
    return cnt;
}

void mos_query(int q)
{
    X1 = mo[0].x1;
    X2 = mo[0].x2;
    Y1 = mo[0].y1;
    Y2 = mo[0].y2;

    for(int i=X1; i<=X2; i++)
        cnt+=(row[i][Y2]-row[i][Y1-1]);

    res[mo[0].idx] = cnt;

    for(int i=1; i<q; i++)
        res[mo[i].idx] = query(mo[i].x1, mo[i].y1, mo[i].x2, mo[i].y2);
}
bool cmp(Info a, Info b)
{
    if((a.x1/sz)<(b.x1/sz))
        return 1;
    if((a.x1/sz)>(b.x1/sz))
        return 0;
    if(a.x2<b.x2)
        return 1;
    if(a.x2>b.x2)
        return 0;
    if(a.y1<b.y1)
        return 1;
    if(a.y1>b.y1)
        return 0;
    if(a.y2<b.y2)
        return 1;
    return 0;
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int n, q, a, b, c, d;
    scanf("%d %d", &n, &q);

    for(int i=1; i<=n; i++)
    {
        getchar();
        for(ll j=1; j<=n; j++)
        {
            scanf("%c", &ch[i][j]);
            row[i][j]=(row[i][j-1]+(ch[i][j]=='*'));
            col[i][j]=(col[i-1][j]+(ch[i][j]=='*'));
        }
    }

    for(int i=0; i<q; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        mo[i].x1 = a;
        mo[i].y1 = b;
        mo[i].x2 = c;
        mo[i].y2 = d;
        mo[i].idx = i+1;
    }
    sort(mo, mo+q, cmp);
    mos_query(q);
    for(int i=1; i<=q; i++)
        printf("%d\n", res[i]);


    return 0;
}
