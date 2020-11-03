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
const ll mx = 1e5+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
struct data
{
    ll wt, fun;
} dp[mx];
ll weight[mx], value[mx];

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k;

    while(cin >> k >> n)   /// k = mx_weight
    {
        if(k==0&&n==0)break;
        for(int i=0; i<n; i++)
        {
            cin >> weight[i] >> value[i];
        }
        for(int i=0; i<=k; i++)
        {
            dp[i].wt = 0;
            dp[i].fun = 0;
        }

        ///KnapSack
        for(int i=0; i<n; i++)
        {
            for(int j=k; j>=weight[i]; j--)
            {
                if(dp[j].fun<dp[j-weight[i]].fun+value[i])
                {
                    dp[j].fun = dp[j-weight[i]].fun+value[i];
                    dp[j].wt = dp[j-weight[i]].wt+weight[i];
                }
                if(dp[j].fun==dp[j-weight[i]].fun+value[i])
                {
                    dp[j].wt = min(dp[j].wt, dp[j-weight[i]].wt+weight[i]);
                }
            }
        }

        cout << dp[k].wt << " " << dp[k].fun << endl;
    }

    return 0;
}
