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
const ll mod = 1e9+7;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};
vector<int>tree[mx];
bool cycle_found, vis[mx];

void Dfs(int src)
{
    vis[src] = true;
    for(auto x: tree[src]){
             if(!vis[x]){
                      Dfs(x);
             }
             else{
                      cycle_found = true;
                      return;
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

    ll t=1, n, m, u, v;
    //cin >> t;

    while(t--){
            cin >> n >> m;
            for(int i=1; i<=m; i++){
                      cin >> u >> v;
                      tree[u].pb(v);
            }
            if(m!=n-1){
                      cout << "NO" << endl;
                      continue;
            }
            for(int i=1; i<=n&&!cycle_found; i++){
                      if(!vis[i]){
                               Dfs(i);
                      }
            }
            cout << (cycle_found? "NO": "YES") << endl;
    }
    return 0;
}

