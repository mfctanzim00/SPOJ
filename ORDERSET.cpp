#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

using namespace __gnu_pbds;
template <typename T> using Set = tree<T, null_type,
                            less<T>, rb_tree_tag,
                            tree_order_statistics_node_update>;
Set<int>s;

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    int t, n, a, b, c, value;
    cin >> t;
    while(t--){
              char ch;
              cin >> ch >> n;

              if(ch=='I'){
                       s.insert(n);
              }
              else if(ch=='D'){
                       s.erase(n);
              }
              else if(ch=='K'){
                       n--;
                       if(s.find_by_order(n)!=s.end()){
                               cout << *s.find_by_order(n) << endl;
                       }
                       else{
                               cout << "invalid" << endl;
                       }
              }
              else{
                       cout << s.order_of_key(n) << endl;
              }
              /*for(auto x: s)cout << x << " ";
              cout << endl;*/
    }
    return 0;
}
