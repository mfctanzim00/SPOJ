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
const ll mx = 1e5+1000;
const ll maxx = 1e19+1000;
ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

vector<ll>vec[mx];
map<pair<ll, ll>, ll>mp;
ll node[mx], dis[mx];
priority_queue<ll>pq;

void Dijkstra(ll u)
{
    pq.push(u);
    dis[u] = 0;
    while(!pq.empty())
    {
        ll x = pq.top();
        pq.pop();
        for(auto i: vec[x])
        {
            ll cost = mp[ {x, i}];
            ll current_node = i;
            if(cost+dis[x]<dis[current_node])
            {
                dis[current_node] = cost+dis[x];
                pq.push(current_node);
            }
        }
    }
}

void init()
{
    for(ll i=0; i<mx; i++)
    {
        vec[i].clear();
        dis[i] = maxx;
    }
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    ll n, m, u, v, w, a, b, t;
    cin >> t;
    while(t--)
    {
        mp.clear();
        cin >> n >> m;
        init();
        vector<ll>v2;
        while(m--)
        {
            cin >> u >> v >> w;
            vec[u].pb(v);
            mp[ {u, v}] = w;
        }
        cin >> a >> b;
        Dijkstra(a);

        if(dis[b]!=maxx)
        {
            cout << dis[b] << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
