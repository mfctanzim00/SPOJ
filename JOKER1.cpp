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
#define pq dp
using namespace std;
const ll mx = 4010;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
bool v[6000][6000];

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
              ll ans = 1;
              vector<ll>v(n);
              for(auto &i: v){
                        cin >> i;
              }
              sort all(v);
              reverse all(v);
              bool ok = true;
              for(ll i=0,j=n-1; i<n; i++,j--){
                        if(v[i]-j<1){
                                    ans = 0;
                        }
                        ans = ans*(v[i]-j);
                        ans%=1000000007;
              }
              cout << ans << endl;
    }
    cout << "KILL BATMAN" << endl;

    return 0;
}

