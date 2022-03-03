#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define gcd __gcd
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
const int N = 2e5 + 10 ;
int a[N];
int n = 6;
int solve1( ){
    int m[n] ;
    for(int i = 0 ; i < n ; i++){
        m[i] = a[i];
    }
    int ans = 0 ;
    while( true){
        for(int i = 1;  i< n ; i++){
            if( m[i] != m[i-1] ){
                break;
            }
            if( i == n-1  ){
                return ans ;
            }
        }
        ans++;
        int h = m[0] ;
        for(int i = 0 ; i + 1 < n ; i++){
            m[ i ] = gcd( m[i] , m[i+1] );
        }
        m[n-1] = gcd( m[n-1] , h );
    }
}
ii solve(){
    for(int i = 0 ; i < n ; i++){
        a[i] = rand()% 20  +1   ;
    }
    int p = solve1();
    int x ;
    int kt[n];
    for(int i = 0 ; i < n ; i++){
        //cin>>a[i];
        kt[i] = -1 ;
        if( i==0 ) x = a[i];
        else{
            x = gcd( x , a[i] );
        }
    }
    for(int i = 0 ; i< n ; i++){
       // a[i] = a[i] / x ;
    }
    int dem = 0 ;
    int ans = 0 ;
    while( kt[dem] == -1 ){
        //debug(dem);
        dem = dem % n ;
        kt[dem] = 1 ;
        if( a[dem] == x ){
            dem++; continue;
        }
        int val = 0 ;
        int val1 = a[dem] ;
        while( 1 ){
            //debug(dem);cout<<" p"<<endl;
            dem++;
            dem = dem % n ;
            val++;
            val1 = gcd( val1 , a[dem] ) ;
            if( val1 == x ) break ;
            kt[dem] = 1;
        }
        //debug(val);
        ans = max( ans , val);
    }
    return { ans , p }  ;
}
signed main(){
       srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =100 ;
    while(t--){
        ii l = solve();
        if( l.fi != l.se ){
            debug( l.fi );debug( l.se);
            for(int i =0 ; i < n ; i++){
                cout<<a[i]<<" ";
            }
            return 0 ;
        }
    }
}
