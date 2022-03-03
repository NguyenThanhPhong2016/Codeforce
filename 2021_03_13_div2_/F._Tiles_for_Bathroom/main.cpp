#include <bits/stdc++.h>

using namespace std;
#define rep(i, l, r) for(auto i=(l);i<=(r);++i)
#define per(i, r, l) for(auto i=(r);i>=(l);--i)
#define N 1505
int n, q, a[N][N];
typedef pair<int, int> Col;
vector<Col> col[N][N];

inline void Add(vector<Col> &A, const vector<Col> &B) {
    for (auto v:B){
        cout<<"dang them v : "<<v.first<<" "<<v.second<<endl;
        A.push_back({v.first + 1, v.second});
    }
}

vector<Col> res;
int mp[N * N];

inline void work(int x, int y) {
    cout<<"chay x : "<<x<<" y : "<<y<<endl;
    res.clear();
    res.push_back({1, a[x][y]});
    if (x < n)Add(res, col[x + 1][y]);
    if (y < n)Add(res, col[x][y + 1]);
    if (x < n && y < n)Add(res, col[x + 1][y + 1]);
    sort(res.begin(), res.end());
    for (auto v:res) {
        if (mp[v.second]){
          //  cout<<"thoat : v.second : "<<v.second<<endl;
            continue;
        }
        mp[v.second] = 1 ;
        cout<<"col dang them : "<<v.first<<" "<<v.second<<endl;
        col[x][y].push_back(v);
        if (col[x][y].size() == q + 1)break;
    }
    for (auto v:res)mp[v.second] = 0;
}

int ans[N];

int main() {
    scanf("%d%d", &n, &q);
    rep(i, 1, n)rep(j, 1, n)scanf("%d", &a[i][j]);
    per(i, n, 1)per(j, n, 1)work(i, j);
    rep(i, 1, n)
        rep(j, 1, n) {
            int o = min(n - i + 1, n - j + 1);
            cout<<"o1 : "<<o<<endl;
            if (col[i][j].size() == q + 1){
                o = min(o, col[i][j][q].first - 1);
                cout<<"o2 : "<<o<<endl;
            }
            ++ans[1], --ans[o + 1];
        }
    int sm = 0;
    rep(i, 1, n)printf("%d\n", sm += ans[i]);
}
