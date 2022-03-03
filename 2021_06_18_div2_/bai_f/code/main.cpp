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
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10;
vector<int> a[N];
int s[N];
int kt[N];
void solve(){
    int n , m ;cin>>n>>m;
    for(int i = 0 ; i < n ; i++){
        a[i].clear();
        s[i] = 0 ;
        kt[i] = -1 ;
    }
    int v[n] ;
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    for(int i = 0,l ; i < n ; i++){
        cin>>l;
        v[i] = l - v[i];
    }
    for(int i = 0 ; i < m ; i++){
        int l , r ;
        cin>>l>>r;
        l--;r--;
        a[l].pb( r );
        a[r].pb(l);
    }
    int sum = 0 ;
    for(int i = 0,l ; i < n ; i++){
        sum += v[i];
    }
    //sum += 1e15;
    //debug(sum);
    if(( (sum % 2) + 10)%2 == 1 ){
        cout<<"NO"<<endl;return;
    }
    queue<int> q ;
    q.push(0);
    kt[0] = 0 ;
    bool ok = false;
    while( !q.empty() ){
        int h = q.front();
        q.pop();
        for(auto x : a[h]){
            if( kt[x] == -1  ){
                kt[x] = 1 - kt[h];
                q.push(x);
            }
            else{
                if( kt[x] != 1 -kt[h] ){
                    ok = true;
                }
            }
        }
    }
    if( ok ){
        cout<<"YES"<<endl;
    }
    else{
        int s0 = 0;
        for(int i = 0; i < n ; i++){
            if( kt[i] == 0 ) s0+= v[i];
            else s0-= v[i];
        }
        //debug(s0);
        if( s0 == 0 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
