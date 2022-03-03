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
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m  ;
    cin>>n>>m;
    string a ; cin>>a ;
    a = ' ' + a ;
    string s1[6] ;
    s1[0] = "abc" ;
    s1[1] = "acb" ;
    s1[2] = "bac" ;
    s1[3] = "bca" ;
    s1[4] = "cab" ;
    s1[5] = "cba" ;
    int s[6][n+1];
    for(int i = 0 ; i< 6 ;i++){
        for(int j = 1 ; j <= 3 ;j++){
            char h = s1[i][j-1] ;
            int id = j ;
            while( id <= n ){
                if( a[ id ] != h  ){
                    s[i][ id ] = 1 ;
                }
                else{
                    s[i][id] = 0 ;
                }
                id=  id  +3 ;
            }
        }
    }
    for(int i = 0; i < 6 ; i++){
        s[i][0] = 0 ;
    }
    for(int i = 0; i < 6 ; i++){
        for(int j = 1 ; j <= n ; j++){
            s[i][ j ] = s[i][j-1] + s[i][ j ];
        }
    }

    while( m-- ){
        int l , r ; cin>>l>>r ;

        int ans = 2*n ;
        for(int i = 0 ; i < 6 ; i++){
            ans = min( ans , s[i][r] - s[i][l-1] );
        }
        cout<<ans<<endl;
    }
}
