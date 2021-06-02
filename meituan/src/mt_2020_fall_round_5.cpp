// AC meituan round 5 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// D AC
const int  maxn=30;

int n;
int a[maxn];
int num_child[maxn];
int num_direct_child[maxn];
bool ans;

set<int> can;
bool check(){
    for(int i=0; i<n; ++i){
        //cout <<num_child[i] <<' ';
        if(a[i]!=num_child[i] || num_direct_child[i]==1)
            return false;
    }
   // cout <<endl;
    return true;
}

void dfs(int node){
    if(node<0){
    bool tmp = true;
        int i=0;
        for(; i<n; ++i){
        //cout <<num_child[i] <<' ';
        if(a[i]-num_child[i] || num_direct_child[i]==1)
            tmp=false ;
        }
        if(tmp) {
            ans=true;
        }
   // cout <<endl;
        return ;
    }
    if(ans) return;
    if (a[node]) can.insert(node);
    for (int p : can) {
        if(p==node) continue;
        if(a[node]+1==a[p]-num_child[p] && !num_direct_child[p]) continue;
        if(a[node]+1<=a[p]-num_child[p]){
            
            num_child[p] += a[node]+1;
            num_direct_child[p]++;
            
            if(!(a[p]-num_child[p])) can.erase(p);
            dfs(node-1);
            if(ans) return; // or will TLE
            if(!(a[p]-num_child[p])) can.insert(p);
            num_child[p] -= a[node]+1;
            num_direct_child[p]--;
        }
    }

}
int main(){

    while(cin >>n){
        bool flag2 = false;
        ans = false;
        memset(num_child, 0, sizeof num_child);
        memset(num_direct_child, 0, sizeof num_child);
        for(int i=0; i<n; ++i) {
            cin >>a[i];
            if(a[i]==2) flag2 = true;
            --a[i];
        }

        sort(a, a+n);
        if((flag2) ||a[n-1]!=n-1 ){
            cout <<"NO\n";
            continue;
        }
        can.insert(n-1);
        dfs(n-2); // 从前至后会超时
        if(ans) cout <<"YES\n";
        else cout <<"NO\n";
    }


    return 0;
}

