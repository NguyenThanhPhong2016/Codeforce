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
const int N = 2e5 + 10 ;
vector< int > a;
int b[N];
void solve(){
    int n ; cin>>n;
    a.clear();
    for(int i = 0 ; i < 2* n+5 ; i++){
        b[i] = - 1;
    }
    for(int i = 1 ; i <= n ; i++){
        int x ;
        cin>>x ;
        a.pb( x  );
        b[ x ] = i ;
    }
    sort( a.begin(), a.end() );
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        //debug(i);debug(a[i]);
        int h = (  2 * n ) / a[i];
        //debug(h);
        auto x = lower_bound( a.begin() , a.end(), h  ) - a.begin() ;
        if( x ==n ) x--;
        for(int j = 0 ;j <= x ; j++){
            int p = b[ a[i] ];
            int q = b[ a[j] ];
            if( p == q ) continue;
            if( p+q == a[i]*a[j] ){
                //debug( a[i] );debug(a[j]);
                ans++;
            }
        }
    }
    cout<<(ans>>1)<<endl;
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
