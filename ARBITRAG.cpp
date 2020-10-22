#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define  ll        long long
#define  ull       unsigned long long
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  all(v)    (v.begin(), v.end())
#define  pi        acos(-1.0)
#define  FastRead  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define  bug(a)    cerr << #a << " : " << a << endl
using namespace std;
const ll mx = 2e5+10;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
double graph[600][600], cost;
int cs;

void warshal()
{
    int nodes, edges;
    string str, src, dest;
    map<string, int>mp;
    cin >> nodes;

    if(nodes==0)
        exit(0);

    for(int i=1; i<=nodes; i++)
        for(int j=1; j<=nodes; j++)
            graph[i][j] = 0;

    for(int i=1; i<=nodes; i++)
    {
        cin >> str;
        mp[str]=i;
    }

    cin >> edges;
    while(edges--)
    {
        cin >> src >> cost >> dest;
        int x = mp[src];
        int y = mp[dest];
        graph[x][y] = cost;
    }

    for(int k=1; k<=nodes; k++)
        for(int i=1; i<=nodes; i++)
            for(int j=1; j<=nodes; j++)
                graph[i][j]=max(graph[i][j], graph[i][k]*graph[k][j]);

    bool ok = false;
    for(int i=1; i<=nodes&&!ok; i++)
        if(graph[i][i]>1)
            ok = true;

    cout << "Case " << ++cs << ": ";
    cout << (ok? "Yes": "No") << endl;
}
int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    int n, m, q, t;
    //cin >> t;

    for(int i=1; ; i++)
    {
        warshal();
    }

    return 0;
}

