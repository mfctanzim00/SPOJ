#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl
 
struct Trie{
    struct node{
        int cnt[2];
        node *nxt[2];
        node(){
            cnt[0]=cnt[1]=0;
            nxt[0]=nxt[1]=NULL;
        }
    }*root;
 
    Trie(){
        root = new node();
    }
 
    void Insert(int n){
        node *cur = root;
        for(int i=25; i>=0; i--){
            bool f = (bool)((1<<i)&n);
            if(cur->nxt[f] == NULL){
                cur->nxt[f] = new node();
            }
            cur->cnt[f]++;
            cur = cur->nxt[f];
        }
    }
 
    int get(int x, int k){
        node *cur = root;
        int cnt=0;
        for(int i=25; i>=0; i--){
            bool xB = (bool)((1<<i)&x);
            bool kB = (bool)((1<<i)&k);
 
            if(kB){
                cnt+=cur->cnt[xB];  // as, x^x=0 and kB=1
                if(cur->nxt[!xB] == NULL){
                    break;
                }
                cur = cur->nxt[!xB];
            }
            else{
                if(cur->nxt[xB] == NULL){
                    break;
                }
                cur = cur->nxt[xB];
            }
        }
        return cnt;
    }
};
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
 
        Trie tree;
        tree.Insert(0);
 
        int prefXOR=0, val;
        long long ans=0;
 
        for(int i=0; i<n; i++){
            scanf("%d", &val);
            prefXOR^=val;
            ans+=tree.get(prefXOR, k);
            tree.Insert(prefXOR);
        }
        printf("%lld\n", ans);
    }
 
	return 0;
}
