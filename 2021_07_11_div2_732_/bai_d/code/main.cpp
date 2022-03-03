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

const int mod = 998244353 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power1( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power1( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power1(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void solve(){
    int n ; cin>>n ;
    string o ;cin>> o;
    vector<int> a(n) ;
    for(int i = 0; i< n; i++){
        if( o[i] == '0' ) a[i] = 0;
        else a[i] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        if( a[i] == 1 && a[i-1] == 1 ){
            break ;
        }
        if( i== n -1 ){
            cout<<1<<endl;
            return ;
        }
    }
    int dem = 0;
    for(int i = 0;  i< n ; i++){
        if( a[i] == 1 ) dem++;
    }
    int dem2 = n - dem ;
    int ans = 0 ;
    int maxbt = ( 2*dem -1 );
    for(int i = dem ; i <= n ; i++){
        debug(i) ;
        for(int j = 0 ; j < dem ; j++){
            if( dem + j > i ) break;
            debug( j );
            int ans1 = fac[dem-1] * fac[dem-1 - j] % mod ;
            ans1 = ans1 * inv[j] % mod ;
            debug( ans1 );
            ans += ans1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
       // srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init( N - 2 ) ;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
