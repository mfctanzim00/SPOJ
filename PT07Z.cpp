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

vector<ll>vec[10009], dis(10009, 0);
map<ll, bool>vis;

void Bfs(ll src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
                ll u = q.front();
                q.pop();
                for(auto x: vec[u]){
                            if(!vis[x]){
                                      q.push(x);
                                      dis[x]+=dis[u]+1;
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

    ll t=1, n, k, m, a, b, c, d;
    //cin >> t;

    while(t--){
             cin >> n;
             k = n;
             n--;
             while(n--){
                       ll u, v;
                       cin >> u >> v;
                       vec[u].pb(v);
                       vec[v].pb(u);
             }
             Bfs(1);
             vis.clear();

             ll res = 0, res_d = 0;
             for(ll i=1; i<=k; i++){
                       if(res_d<dis[i]){
                                res_d = dis[i];
                                res = i;
                       }
             }
             fill(dis.begin(), dis.end(), 0);

             Bfs(res);

             res = 0;
             for(ll i=1; i<=k; i++){
                       if(res<dis[i]){
                                res = dis[i];
                       }
             }
             cout << res << endl;

    }

    return 0;
}
