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

const int N = 1e5 + 10 ;
int a[N];
int b[N];
int sa[N];
int n ;
int tinh( int a , int b ){
    if( a%b == 0 ) return a/b ;
    else return 1 + a/ b ;
}
int tinh1( int x ,int y ){
    return ( x - x / 4  ) - ( y - y /4 ) ;
}
int value( int k ){
   // debug(k);
    if( k== n ) return sa[n-1];
    return sa[n-1] - sa[n-k-1] ;
}
int tinha( int id ){
    int maxbt = id - n ;
    int h = id - id / 4 ;
    if( maxbt >= h ){
        return h*100;
    }
    return  maxbt * 100 + value( h - maxbt );
}
void solve(){
    cin>>n ;
    int sl1 = n /4 ;
    int sl = n - sl1;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>b[i];
    }
    sort( a , a + n  ) ;
    sa[0] = a[0] ;
    for(int i = 1 ; i< n;i++){
        sa[i] = sa[i-1] + a[i];
    }
    int suma = 0 , sumb = 0 ;
    for(int i = n - sl ; i < n ; i++){
        suma += a[i] ;
    }
    sort( b , b + n ) ;
    for(int i = n - sl ; i < n ; i++){
        sumb += b[i] ;
    }
    if( suma >= sumb ){
        cout<<0<<endl; return ;
    }
    int sum = sumb ;
    for(int i = 0; i < n - sl ; i++){
        sum += b[i];
    }
    //debug(sumb);debug(sum);debug(suma);
    int bg = n -sl -1 ;
    int ans = 0;
    while( tinha( n + ans ) < sumb ){
       // debug( tinha( n + ans ) );
        ans++;
        int k = tinh1( n + ans , n + ans -1 ) ;
        if( k==0 ) continue;
        if( bg >=0 ) sumb += b[bg] ;
        bg--;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
