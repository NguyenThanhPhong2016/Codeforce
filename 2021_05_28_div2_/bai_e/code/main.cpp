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

int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 5e5 + 10 ;
int a[N];
int b[N];
int c[N];
int d[N];
const int mod = 998244353 ;
int power1( int a, int b  ){
    if( b == 1 ) return a;
    else if( b== 0 ) return 1;
    int u = b/ 2;
    u = power1( a , u ) % mod ;
    u = ( u * u  ) % mod ;
    if( b % 2 == 1 ) u = ( u*a ) % mod ;
    return u;
}

void solve(){
    int n , k ; cin>>n>>k;
    int a[n+1];
    int b[n+1];
    int dem = -1  ;
    for(int i= 0  , x ; i < n  ;i++){
        //debug(i);
        cin>>x;
        dem++;
        a[x] = dem ;
        //debug( a[x] );
        b[ a[x] ] = x ;
    }
    a[n] = -1 ;
    int maxbt = 0 ;
    int sl = 0 ;
    for(int i = 0 ; i< n -1 ; i++){
        int x = b[i];
        int y = b[i+1];
        if(  a[x+1] < a[y+1]) sl++;
    }
    //debug(sl);
    k += sl;
    int ans = 0 ;
    if( n < k ){
        ans =1 ;
        ans = ( ans * ( (  d[ k ] *  power1( d[ n ] , mod -2  ) )%mod )  ) % mod ;
        ans = ( ans * power1( d[k - n ] , mod -2 ) ) % mod;
    }
    else if( k== n ){
        ans = 1;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    d[0] = 1 ;
    d[1] = 1 ;
    for(int i = 2 ; i < N ; i++ ){
        d[i] = ( d[i-1] * i ) % mod ;
    }
    int t;t =1 ;
    while(t--){
        solve();
    }
}
