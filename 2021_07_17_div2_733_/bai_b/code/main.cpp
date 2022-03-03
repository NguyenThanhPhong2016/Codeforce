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

/*
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void solve(){
    int n , m ; cin>>n>>m ;
    int a[n][m] ;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            a[i][j] = 0 ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if( i %2 ==0  ) a[i][0] = 1 ;
    }
    for(int i = 0 ; i < m ;i++){
        if( i%2 ==0  ) a[0][i] = 1;
        if(i >= 2 && i%2 == 0 ) a[n-1][i] = 1;
     }
    for(int i = 2 ; i< n ;i++ ){
        if( i%2 == 0 ) a[i][m-1] = 1;
    }
    if( a[n-2][m-1] ==1 && a[n-1][m-2] ==1  ){
        a[n-2][m-1] = 0 ;
    }
    if( a[n-2][m-1] ==1 && a[n-1][m-1] ==1  ){
        a[n-1][m-1] = 0 ;
    }
    if( a[n-1][m-2] ==1 && a[n-1][m-1] ==1  ){
        a[n-1][m-1] = 0 ;
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
