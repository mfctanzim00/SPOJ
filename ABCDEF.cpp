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
    //cin >> t;

    while(t--){
             cin >> n;
             vector<ll>v, left, right;
             for(ll i=0; i<n; i++){
                          cin >> k;
                          v.pb(k);
             }
             ///(a*b)+c
             ///d*(e+f)
             for(ll a=0; a<n; a++){
                          for(ll b=0; b<n; b++){
                                        for(ll c=0; c<n; c++){
                                                      ll ii = (v[a]*v[b])+v[c];
                                                      left.pb(ii);
                                        }
                          }
             }
             for(ll d=0; d<n; d++){
                          if(!v[d]){
                                   continue;
                          }
                          for(ll e=0; e<n; e++){
                                        for(ll f=0; f<n; f++){
                                                     ll ii = v[d]*(v[e]+v[f]);
                                                     right.pb(ii);
                                        }
                          }
             }
             map<ll, ll>mp, mp2;
             sort all(left);
             sort all(right);
             for(auto x: left){
                          mp[x]++;
             }
             for(auto x: right){
                          mp2[x]++;
             }

             left.erase(unique all(left), left.end());
             right.erase(unique all(right), right.end());

             ll i = 0, j = 0, ans = 0;
             while(i<left.size()&&j<right.size()){
                         if(left[i]==right[j]){
                                       ans+=(mp[left[i]]*mp2[right[j]]);
                                       i++;
                                       j++;
                         }
                         else if(left[i]>right[j]){
                                       j++;
                         }
                         else{
                                       i++;
                         }
             }
             cout << ans << endl;
    }
    return 0;
}
