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
const int N = 3e5 + 10 ;
int n , m ;
int as[N] ;
int ra[N] ;
int solve1( int id ){
    //debug(id);
    int a[ n + 1 ] ;
    int dem = 0 ;
    while( dem != n  ){
        dem++;
        a[dem] = as[id] ;
        id++;
        if( id == n+1 ) id = 1 ;
    }
    int b[n+1] ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        b[i] = 0 ;
       // cout<<a[i]<<" ";
    }
   // cout<<endl;
    for(int i = 1; i<= n; i++){
        if( b[ a[i] ] == 1 ) continue ;
        int h = a[i] ;
        int dem = 0 ;
      //  debug(i);
        while( b[h] == 0 ){
            dem++;
            b[ h ] = 1 ;
            h = a[ h ] ;
        }
        //debug(dem);
        ans = ans + dem - 1 ;
    }
   // debug(ans);
    if( ans <= m ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
void solve(){
    cin>>n>>m ;
    int minbt = n / 3 ;
    minbt = n - 2 * minbt ;
    for(int i = 1;  i<= n ; i++){
        cin>>as[i] ;
        ra[ as[i] ] = i ;
    }
    int s[n+1] ;
    for(int i = 0 ; i <=n ; i++ ){
        s[i] = 0 ;
    }
    for( int i = 1 ;  i<= n ; i++ ){
        if(  ra[i] >= i  ){
            s[ ra[i] - i ]++;
        }
        else{
            s[ ra[i] - i + n ]++;
        }

    }
    vector<int > kq ;
    for(int i = 0 ; i <= n ; i++){
        if( s[i] >= minbt ){
            if( solve1( i + 1 ) == 1){
                kq.pb( i );
            }
        }
    }
    cout<<kq.size()<<" ";
    for(int i = 0 ; i< kq.size() ; i++){
        cout<<kq[i]<<" ";
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
