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
const int N = 1e6 + 10 ;
const int mod = 998244353 ;
int a[N];
void solve(){
    int n;cin>>n;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 0; j <= n ; j= j + i){
            a[j]++;
        }
    }
    int dp[n+1];
    dp[1] = 1 ;
    int sum = 1 ;
    for( int i = 2 ; i <= n ; i++ ){
        dp[i] = ( sum + a[i] ) %mod ;
        sum   = ( sum + dp[i] )%mod ;
    }
    cout<<dp[n]%mod<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t=1 ;
    while(t--){
        solve();
    }
}
