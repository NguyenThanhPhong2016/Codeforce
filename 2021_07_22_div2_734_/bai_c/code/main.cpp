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
    string s ; cin>>s ;
    ii dp0[6] ;
    ii dp1[6] ;
    dp0[0].fi = dp0[0].se = dp1[0].fi = dp1[2].se = 0;
    for(int i = 1 ; i <= 5 ; i++){
        int h = ( i-1 )*2 ;
        if( s[h] == '0' ){
            dp0[ i ].fi = dp0[ i - 1 ].fi ;
            dp0[ i ].se = dp0[ i - 1 ].se ;
        }
        else if( s[h] == '1' ){
            dp0[ i ].fi = dp0[ i - 1 ].fi + 1 ;
            dp0[ i ].se = dp0[ i - 1 ].se + 1 ;
        }
        else{
            dp0[ i ].fi = dp0[ i - 1 ].fi ;
            dp0[ i ].se = dp0[ i - 1 ].se + 1 ;
        }
    }
    for(int i = 1 ; i <= 5 ; i++){
        int h = ( i-1 )*2 + 1 ;
        if( s[h] == '0' ){
            dp1[ i ].fi = dp1[ i - 1 ].fi ;
            dp1[ i ].se = dp1[ i - 1 ].se ;
        }
        else if( s[h] == '1' ){
            dp1[ i ].fi = dp1[ i - 1 ].fi + 1 ;
            dp1[ i ].se = dp1[ i - 1 ].se + 1 ;
        }
        else{
            dp1[ i ].fi = dp1[ i - 1 ].fi ;
            dp1[ i ].se = dp1[ i - 1 ].se + 1 ;
        }
    }
    for(int i = 5 ; i <= 9 ; i++){
      //  debug(i);
        int h = i/2 + 1 ;
        int minbt = 5 - h + 1;
       // debugp( dp0[h] ) ; debugp(dp1[h]);
        if( i%2 == 0 ){
           // debugp( dp1[h-1] );
            if( dp0[h].se - dp1[h-1].fi >= minbt +1 ){
                cout<<i+1<<endl; return ;
            }
            if( dp1[h-1].se - dp0[h].fi >= minbt  ){
                cout<<i+1<<endl; return ;
            }
        }
        else{
            if( dp1[h].se - dp0[h].fi >= minbt ){
                cout<<i+1<<endl; return ;
            }
            if( dp0[h].se - dp0[h].fi >= minbt ){
                cout<<i+1<<endl; return ;
            }

        }
    }
    cout<<10<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
