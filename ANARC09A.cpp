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
const ll mx = 1e9+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d, cs = 1;
    //cin >> t;
    while(t--){
              read:
              string x;
              cin >> x;
              bool ok = count(x.begin(), x.end(), '-')>0;
              if(ok){
                      continue;
              }
              ll left = 0, right = 0, res = 0;
              for(auto ch: x){
                      if(ch=='{'){
                                left++;
                      }
                      else{
                                right++;
                                if(left){
                                         right--;
                                         left--;
                                }
                                else{
                                         res+=(right/2);
                                         k = right/2;
                                         right-=(k*2);
                                }
                      }
              }
              res+=(left/2);
              k = (left/2);
              left-=(k*2);
              res+=(left+right);
              cout << cs++ << ". " << res << endl;
              goto read;
    }
    return 0;
}
