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
const ll mx = 4444444444;

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
              string x, y, res = "";
              cin >> x >> y;
              ll l = 0, r = 0;
              reverse all(x);
              reverse all(y);
              for(auto xx: x){
                         l= l*10 + (xx-'0');
              }
              for(auto yy: y){
                         r = r*10 + (yy-'0');
              }
              k = l+r;
              while(k){
                      res+=((k%10)+'0');
                      k/=10;
              }
              bool flag = 0;
              for(auto x: res){
                      if(x=='0' && !flag){
                              continue;
                      }
                      else{
                             flag = 1;
                             cout << x;
                      }
              }
              cout << endl;
    }
    return 0;
}

