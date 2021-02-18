#include<bits/stdc++.h>
#include<cstring>
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
const ll mod = 10000007;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};

ll Bigmod(ll a, ll b)
{
  ll res=1;
  a%=mod;
  while(b){
         if(b&1)res=(res*a)%mod;
         a=(a*a)%mod;
         b>>=1;
  }
  return res;
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d;
    //cin >> t;

    while(1){
            cin >> n >> k;

            if(n==0&&k==0)break;

            ll x=(Bigmod(n, k)+Bigmod(n, n))%mod;
            ll y=(2*Bigmod(n-1, k))%mod;
            ll z=(2*Bigmod(n-1, n-1))%mod;

            cout << (x+y+z)%mod << endl;
    }
    return 0;
}
