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
const ll maxx = (int)2e5+5;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

vector<pair<ll, pair<ll, ll> > >graph, res;
ll parent[maxx], mstValue=0;

void initPar(ll r)
{
    for(ll i=0; i<r; i++)
        parent[i]=i;
}

int Find(ll r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}

void kruskals_Algorithm(ll n)
{
    sort all(graph);
    initPar(n);
    ll cnt=0;
    for(ll i=0; i<graph.size(); i++)
    {
        ll uPr=Find(graph[i].ss.ff);
        ll vPr=Find(graph[i].ss.ss);


        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            res.pb(graph[i]);
            mstValue+=graph[i].ff;
            parent[uPr]=vPr;
            cnt++;
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
             ll e;
             cin>>n>>e;

             for(ll i=0; i<e; i++){
                          ll u,v,w;
                          cin>> u >> v >> w;
                          graph.pb({w, {u, v}});
            }
            kruskals_Algorithm(n);

           cout << mstValue << endl;

            return 0;
    }
}

