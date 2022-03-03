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
    int n , m ; cin>>n>>m ;
    if( n > m ){
        cout<<0<<endl;
        return ;
    }
    else if( n == 0 ){
        cout<<m+1<<endl;
        return ;
    }
    //debug( n ^ m );
    int dem = 40 ;
    int ans = 0 ;
    int kq = 1e12 ;
    while( true ){
        if( n >> dem == 0 ){
            dem--;
        }
        else break;
    }
    int p =  m >>( dem + 1 )   ;
    ans = ans + ( p<<(dem+1) ) ;
    while( dem != -1 ){
        //debug( kq  );
     //   debug(ans);
        int k = dem + 1 ;
        while( true ){
            if( ( ans >> k) & 1 == 1 ) k++;
            else break;
        }
        kq = min( kq ,( (ans>>k )+1 )<< k )  ;
        int h = ( n >> dem ) & 1 ;
        k = (m >> dem )  & 1 ;
        if( k==1 ){
            if( h==1 ){
            }
            else{
                ans = ans + ( 1<<dem );
            }
        }
        else{
            if( h== 1 ){
                kq = min( ans , kq  );
                break;
            }
            else{
                kq = min( kq , ans + ( 1 << dem ) );
            }
        }
        dem--;
    }
    cout<<kq<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
