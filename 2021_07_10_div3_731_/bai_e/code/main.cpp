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
bool cmp( ii x , ii y  ){
    if( x.fi != y.fi ) return x.fi < y.fi ;
    return x.se < y.se ;
}
void solve1(int n){
    int val , id ; cin>>id>>val ;
    int ans[n+1];
    for(int i = id ; i <= n ; i++){
        ans[i] = val + ( i - id );
    }
    for(int i = id ; i >= 1 ; i--){
        ans[i] = val + ( id - i );
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n , k ; cin>>n>>k ;
    if( k == 1 ){
        //cout<<"xuli"<<endl;
        solve1(n) ;
        return ;
    }
    ii a[k+1] ;
    for(int i = 1;  i <= k ; i++ ){
        cin>>a[i].se;
    }
    for(int i = 1;  i <= k ;  i++){
        cin>>a[i].fi ;
    }
    int ans[n+1] ;
    for(int i = 1 ; i <= n ; i++){
        ans[i] = -1 ;
    }
    sort( a + 1 , a + k + 1  );
    queue< ii > ds ;
    ds.push( a[1] ) ;
    int dem = 2 ;
    while( ds.size() != 0 ){
        ii x =ds.front() ;
        //debug(x.fi);debug(x.se);
        while(dem <= k && x.fi == a[dem].fi ){
            ds.push( a[dem] ) ;
            dem++;
        }
        if( ans[x.se] == -1 ){
            ans[x.se] = x.fi ;
            if( x.se + 1 <= n ){
                ds.push( { x.fi + 1 , x.se + 1 } );
            }
            if( x.se >= 2){
                ds.push( { x.fi + 1 , x.se - 1 } );
            }
        }
        ds.pop();
    }
    for(int i = 1 ; i<= n ;i++){
        cout<<ans[i]<<" ";
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
