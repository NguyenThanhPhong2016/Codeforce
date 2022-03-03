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
const int N = 503 ;
const int inf = 1e3 ;
int a[N];
int b[N];
int sl[N];
int n , k ;
int l , r ;
int ans ;
int cong( int x , int y ){
    return  ( x + y -1 )%n + 1 ;
}
int so( int x ){
    return (x -1 )%n + 1 ;
}
void dfs( int x ){
    if( x == 0  ) return ;
    dfs( b[x] );
    int c = b[x];
    int i = ( c + k - x )>>1;
    //debug(i);debug(c);debug(x);
    cout<<"? ";
    for(int j = l ; j < l + i;j++){
        cout<<so( j )<<" ";
    }
    l = cong(l , i) ;
    int ed = cong( l -1   , x  );
    //cout<<" o ";
    while( r != ed ){
        //cout<<"r: "<<r<<" "<<ed<<endl;
        r= cong(r , 1);
        cout<<r<<" ";
    }
    //debug(ed);debug(l);
    fflush(stdout);
    int p ; cin>>p;ans^= p ;
    r = ed ;
}
signed main(){
    l = 1;  r = 0;ans = 0 ;
    cin>>n>>k;
    for(int i = 0; i <= n + 1 ; i++){
        a[i] = inf ;
    }
    queue<int> ds ;
    a[0] = 0 ;
    b[0] = -1 ;
    ds.push( 0 ) ;
    while( ds.size() != 0 ){
        int c = ds.front();
        ds.pop();
        for(int i = 0 ; i <= min( c , k ); i++){
            int x = c + k - 2 * i ;
            if( x >= 0 && c + k - i <= n && a[x] == inf  ){
                //debug(c) ; debug(i);debug(x);
                a[x] = a[c] + 1 ;
                b[x] = c ;
                //debug(x);debug(a[x]);
                ds.push( x );
            }
        }
    }
    if( a[n] == inf ){
        cout<<"-1"<<endl;return 0 ;
    }
    dfs(n);
    cout<<"! "<<ans<<endl;
}
