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
const ll mx = 1e9+10;

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
    //cin >> t;

    while(t--){
              read:
              cin >> n >> k;
              vector<ll>v(n), cumu(n, 0);
              for(auto &x: v){
                        cin >> x;
              }
              cumu[0] = v[0];
              for(ll i=1; i<n; i++){
                        cumu[i]+=v[i]+cumu[i-1];
              }
              cumu.insert(cumu.begin(), 0);
              ll res = 0;
              for(ll i=1; i<=n; i++){
                        ll left = i, right = n;
                        while(left<=right){
                                    ll mid = (left+right)>>1;
                                    if(cumu[mid]-cumu[i-1]==k){
                                             res = k;
                                             break;
                                    }
                                    else if(cumu[mid]-cumu[i-1]>k){
                                             right = mid-1;
                                    }
                                    else{
                                             left = mid+1;
                                             res = max(res, cumu[mid]-cumu[i-1]);
                                    }
                        }
              }
              cout << res << endl;
    }
    return 0;
}


