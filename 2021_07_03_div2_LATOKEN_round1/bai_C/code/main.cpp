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
int pow( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = pow( a , c ) % mod ;
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
const int mod = 1e9 + 7 ;
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void solve(){
    int n ; cin>>n ;
    int a[n+1];
    int b[n+1];
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        cin>>b[i];
    }
    int c[n+1];
    for(int i =1 ;i <= n ; i++){
        c[ a[i] ] = b[ i ];
    }
    int dem = 0;
    int d[n+1];
    for(int i = 1 ; i <= n ; i++ ) d[i] = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if( d[i] != -1  ) continue;
        //debug(i);
        int h = i ;
        d[h] = 1 ;
        int a = c[h]; dem++;
        while( a != h ){
            d[a] = 1 ;
            a = c[a] ;
        }
    }
    cout<<power( 2 , dem )<<endl;
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
