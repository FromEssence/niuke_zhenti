/*
 * MeiTuan 2020 Fall Round 4
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
//A. AC
//Two dfs, first from x to index all nodes, then from y to cal ans
const int maxn=5e4+10;
//int gra[maxn][3]; // in binary tree, each node has at most 3 edges
vector<int> gra[maxn]; // we do not know if it is a binary tree
bool vis[maxn];
int depth_of_nodes[maxn];
int max_depth_y=0;

void dfs(int r, int depth){
    vis[r] = true;
    // max_depth = max(depth, max_depth);
    depth_of_nodes[r] = depth;
    for(int i=0; i<gra[r].size(); ++i){
        if(!vis[gra[r][i]]) dfs(gra[r][i], depth+1);
    }
}

void dfs2(int r, int &uplimit_d){
    // from r, only to node with depth<uplimit_d
    vis[r] = true;
    max_depth_y = max(max_depth_y, depth_of_nodes[r]);
    for(int i=0; i<gra[r].size(); ++i){
        if(depth_of_nodes[gra[r][i]]>uplimit_d && !vis[gra[r][i]]) dfs2(gra[r][i], uplimit_d);
    }
}
int main()
{
    int n, x, y, u, v;
    cin >>n >>x >>y;
    for(int i=0; i<n-1; ++i){
        cin >>u >>v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    dfs(x, 0);
    memset(vis, false, sizeof vis);
    int limit = depth_of_nodes[y]/2;
    dfs2(y, limit);
    cout <<max_depth_y <<endl;
    return 0;
}


// B. AC
// two linear scan
int main(){

    int len;
    string str;
    string ans = "";
    cin >>len >>str;

    int head_T=0, tail_M=len-1;
    for(int m=0; m<len; ++m){
        if(str[m]=='M'){
            for(head_T=m+1; head_T<len&&str[head_T]!='T'; ++head_T){
                ;
            }
            break;
        }
    }
    for(int t=len-1; t>0; --t){
        if(str[t]=='T'){
            //cout <<"t:" <<t<<endl;
            for(tail_M=t-1; tail_M>head_T&&str[tail_M]!='M'; --tail_M){
                ;
            }
            break;
        }
    }
    //cout <<tail_M <<endl;
    if(head_T+1==tail_M) cout <<endl;
    else{
        cout <<str.substr(head_T+1, tail_M-head_T-1)<<endl;
    }
    return 0;
}


//C. AC so easy
const int maxn = 300+8;
int matrix[maxn][maxn];
int used[maxn];

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >>matrix[i][j];
        }
        for(int j=0; j<n; ++j){
            if(!used[matrix[i][j]]){
                used[matrix[i][j]] = true;
                cout <<matrix[i][j] <<' ';
                break;
            }
        }

    }


    return 0;
}
*/

//D. AC refer to the answer in discuss
//O(n*nlogn)
const int maxn=1e5+8;
int seq[maxn];

// O(n) check if not decreasing
// l and r is as the problem description
bool check(int nums[], int len, int l, int r){
    int last_e = 0;
    for(int i=0; i<len; ++i){
        if(nums[i]>=l && nums[i]<=r) continue;
        else if(nums[i]<last_e) return false;
        else last_e = nums[i];
    }

    return true;
}
int main(){
    int n, m;
    cin >>n >>m;
    for(int i=0; i<n; ++i) cin >>seq[i];
    int ans = 0;
    int r = m;
    while (r > 0) {
       // cout <<"r:"<<r<<endl;
        int cnt = 0;
        if (!check(seq, n, 0, r)) {
            break;
        }
        int l = 1;
        int temp = r;
        int mid = 0;
        while (l <= r) {
            mid = (l+r)>>1;
            if (check(seq, n, mid, temp)) {
                cnt = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        r = temp - 1;
        ans += cnt;
    }
    cout <<ans<<endl;

    return 0;
}
