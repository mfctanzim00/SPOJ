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
const int mx = 2e5+9;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
ll tree[3*mx], arr[mx];

void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node] = arr[start];
            return;
    }
    ll mid = (start+end)>>1;

    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);

    tree[node] = min(tree[node<<1], tree[node<<1|1]);
}

void update(ll node, ll start, ll end, ll i, ll newvalue)
{
    if(i<start || i>end)
             return;
    if(start>=i && end<=i){
             tree[node] = newvalue;
             return;
    }
    ll mid = (start+end)>>1;

    update(node<<1, start, mid, i, newvalue);
    update(node<<1|1, mid+1, end, i, newvalue);

    tree[node] = min(tree[node<<1], tree[node<<1|1]);
}

ll query(ll node, ll start, ll end, ll i, ll j)
{
    if(i>end || j<start)
            return INT_MAX;
    if(start>=i && end<=j)
            return tree[node];

    ll mid = (start+end)>>1;
    ll x = query(node<<1, start, mid, i, j);
    ll y = query(node<<1|1, mid+1, end, i, j);

    return min(x, y);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, q, m, l, r;
    //cin >> t;

    while(t--){
             cin >> n;
             for(int i=1; i<=n; i++){
                        cin >> arr[i];
             }
             build(1, 1, n);
             cin >> q;
             while(q--){
                        cin >> l >> r;
                        cout << query(1, 1, n, l+1, r+1) << endl;
             }
    }
    return 0;
}
