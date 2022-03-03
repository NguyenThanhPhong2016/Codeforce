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

const int N = 1<<20  ;
const int mod = 998244353 ;
int s[N];
void update(int id , int value){
    s[id] = value ;
    id = id>>1;
    while( id != 0 ){
        s[ id ] = ( s[id<<1] + s[id*2+1] ) % mod;
        id = id>>1;
    }
}
int searchp(int id , int l , int r , int u , int v ){
    if( v < l || r < u  ){
        return 0 ;
    }
    if( u <= l && r <= v ){
      //  cout<<s[id]<<endl;
        return s[id] ;
    }
    int mid = ( l + r ) >>1 ;
    return ( searchp( id* 2 , l , mid , u , v  ) + searchp( id * 2 + 1 , mid + 1 ,r , u, v ) ) % mod ;
}
signed main(){
       // srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    int k = 1;
    int a[n+1] ;
    int b[n+1] ;
    int c[n+1] ;
    while( k <= n ) k = k * 2;
  //  debug(k);
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i]>>b[i]>>c[i] ;
        int h = lower_bound( a ,a + i + 1 , b[i] ) - a ;
       // debug( h );
        int kq = 0 ;
        if( h != i ) kq = searchp( 1 , 0 , k-1 , h , i -1  );
       // debug(kq);
        kq = kq + a[i] - b[i] ;
        kq = kq % mod ;
        update( k + i , kq  );
    }
    int ans = a[n-1] + 1;
    for(int i = 0 ; i < n ; i++){
        if( c[i] ==1 ){
            ans += s[k+i];
            ans = ans % mod ;
        }
    }
    ans = ans % mod ;
    while( ans < 0 ) ans += mod ;
    cout<<ans % mod <<endl;
}
