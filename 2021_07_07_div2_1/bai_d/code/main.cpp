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
const int N = 2e5 + 10 ;
int a[N][30];
int n , k ;
int maxbt = 1e8 ;
int query( int  k ){
    cout<<k<<endl;
    fflush(stdout) ;
    int c ; cin>>c ;
    //c = 0 ;
    return c ;
}
bool xuli0(int i){
    int doan = 0 ;
    int kq = 1 ;
    for(int j = 0 ; j < 30 ; j++){
        if( j != 0 ) kq *= k ;
        if( kq > maxbt ) break ;
        doan = doan + (  ( a[i][j] + k - a[i-1][j] )% k  )*kq ;
    }
    int c = query(doan);
    if( c == 1) return true ;
    return false ;
}
bool xuli1(int i){
    int doan = 0 ;
    int kq = 1 ;
    for(int j = 0 ; j < 30 ; j++){
        if( j != 0 ) kq *= k ;
        if( kq > maxbt ) break ;
        doan = doan + (  ( a[i-1][j] + k - a[i][j] )% k  )*kq ;
    }
    int c = query(doan);
    if( c == 1) return true ;
    return false ;
}
void solve(){
    cin>>n>>k ;
    for(int i = 0 ; i <  n ;i++){
        for(int j = 0 ; j < 30 ; j++){
            a[i][j] = 0 ;
        }
    }
    for(int i = 0 ; i <  n ;i++){
        int m = i ;
        int dem = -1;
        while( m > 0 ){
            dem++;
            a[i][dem] = m % k ;
            m = m / k ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        debug(i);
        if( i==0 ){
            int s = query( 0 );
            if( s == 1 ) return ;
            continue;
        }
        if( i% 2 ==  0 && xuli0( i ) == true ) return ;
        if( i% 2 ==  1 && xuli1( i ) == true ) return ;
    }
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
