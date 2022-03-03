#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
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
const int inf = 1e18 ;
void solve(){
    int n ;
    cin>>n ;
    int a[n];
    vector<int > s1 ;
    vector<int > s0 ;
    s1.pb(0);
    s0.pb(0);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        if( a[i] ==1 ) s1.pb( i ) ;
        else s0.pb( i ) ;
    }
    int dp[ s1.size() ][ s0.size() ] ;
    for(int i = 0 ; i < s1.size() ; i++){
        for(int j = 0 ; j < s0.size() ; j++){
            dp[i][j] = inf ;
        }
    }
    for(int i = 0 ; i < s0.size() ; i++  ){
        dp[0][i] = 0;
    }
    for(int i = 1 ; i < s1.size() ; i++  ){
        dp[i][0] = inf;
    }
    for(int i = 1 ; i < s1.size() ; i++){
        for(int j = 1 ; j < s0.size() ; j++){
            dp[i][j] = min( dp[i][j-1] , dp[i][j] );
            dp[i][j] = min( dp[i][j] , dp[i-1][j-1] + abs( s1[i] - s0[j] ) );
        }
    }
    cout<<dp[ s1.size() -1 ][ s0.size() -1 ]<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1 ;
    while(t--){
        solve();
    }
}
