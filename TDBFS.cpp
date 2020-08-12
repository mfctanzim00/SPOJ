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
vector<ll>vec[1234];
map<ll, bool>vis;

void Dfs(ll src)
{
    printf("%lld ", src);
    vis[src] = true;
    for(auto x: vec[src]){
               if(!vis[x]){
                        Dfs(x);
               }
    }
}

void Bfs(ll src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
               ll u = q.front();
               printf("%lld ", u);
               q.pop();
               for(auto x: vec[u]){
                          if(!vis[x]){
                                  q.push(x);
                                  vis[x] = true;
                          }
               }
    }
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d, cs = 1;
    scanf("%lld", &t);

    for(ll i=1; i<=t; i++){
             scanf("%lld", &n);
             while(n--){
                     scanf("%lld %lld", &k, &m);
                     while(m--){
                               scanf("%lld", &a);
                               vec[k].pb(a);
                     }
             }
             ll u, v;
             bool ok = true;
             while(1){
                     scanf("%lld %lld", &u, &v);
                     if(!u && !v){
                               ok = true;
                               break;
                     }
                     if(ok){
                               printf("graph %lld\n", cs++);
                               ok = false;
                     }
                     if(v){
                               Bfs(u);
                               vis.clear();
                               printf("\n");
                     }
                     else{
                               Dfs(u);
                               vis.clear();
                               printf("\n");
                     }
            }
            for(ll i=1; i<=1010; i++){
                     vec[i].clear();
            }
    }

    return 0;
}
