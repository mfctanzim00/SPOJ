#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define ll long long
#define ull unsigned long long
#define pb push_back
#define ff first
#define ss second
#define all(v) (v.begin(), v.end())
#define pi acos(-1.0)
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define bug(a) cerr << #a << " : " << a << endl
using namespace std;
const ll mx = 4010;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d;
    cin >> t;

    while(t--){
             cin >> n;
             vector<pair<ll, ll> >v(n);
             priority_queue<ll>pq;
             for(auto &i: v){
                       cin >> i.ss >> i.ff;
             }
             sort all(v);
             pq.push(v[0].ff);
             ll res = 1;
             v.erase(v.begin());

             for(auto x: v){
                       if(x.ss>=pq.top()){
                                pq.push(x.ff);
                                res++;
                       }
             }
             cout << res << endl;
    }
    return 0;
}
