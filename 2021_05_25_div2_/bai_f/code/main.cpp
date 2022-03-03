#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int inf=1000000010;
const long long INF=1000000000000001000LL;
const int mod=1000000007;
const int N=605;
int n, m, k, u, v, x, y, t, a, b;
bool mark[N];
int G[N][N], D[N];
inline void upd(int &x, int y){ if (x>y) x=y;}
void solve(){
    memset(G, 63, sizeof(G));
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u][v]=min(G[u][v], x);
	}
	for (int i=0; i<n; i++){
		memset(D, 63, sizeof(D));
		memset(mark, 0, sizeof(mark));
		for (int v=0; v<n; v++) upd(D[v], G[i][v]);
		while (1){
			int v=-1;
			for (int x=0; x<n; x++) if (!mark[x]){
				if (v==-1 || D[v]>D[x]) v=x;
			}
			if (v==-1) break ;
			mark[v]=1;
			upd(D[(v+1)%n], D[v]+1);
			for (int u=0; u<n; u++)
				upd(D[(u+D[v])%n], D[v]+G[v][u]);

		}
		for (int j=0; j<n; j++){
			if (i==j) cout<<"0 ";
			else cout<<D[j]<<" ";
		}
		cout<<"\n";
	}
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t = 1;
    while(t--){
        solve();
    }
}
