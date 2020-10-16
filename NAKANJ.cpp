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

int posx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int posy[] = {1, -1, 1, -1, 2, 2, -2, -2};
bool vis[8][8];
int dis[8][8];

int Bfs(int src_row, int src_col, int dest_row, int dest_col)
{
    ///As it is 8x8 grid
    for(int i=0; i<8; i++){
             for(int j=0; j<8; j++){
                      vis[i][j] = false;
                      dis[i][j] = 0;
             }
    }
    queue<pair<int, int> >q;
    q.push({src_row, src_col});
    vis[src_row][src_col] = true;
    dis[src_row][src_col] = 0;

    while(!q.empty()){
             int x = q.front().first;
             int y = q.front().second;
             q.pop();

             for(int i=0; i<8; i++){
                       int row = posx[i]+x;
                       int col = posy[i]+y;

                       if(row>=0 && row<8 && col>=0 && col<8 && !vis[row][col]){
                                   dis[row][col] = dis[x][y]+1;
                                   vis[row][col] = true;
                                   q.push({row, col});
                       }
             }
    }
    return dis[dest_row][dest_col];
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, mx_weight;
    cin >> t;
    while(t--){
              string ch, ch2;
              cin >> ch >> ch2;

              int src_col = ch[0]-'a';
              int src_row = ch[1]-'1';
              int dest_col = ch2[0]-'a';
              int dest_row = ch2[1]-'1';

              cout << Bfs(src_row, src_col, dest_row, dest_col) << endl;
    }

    return 0;
}

