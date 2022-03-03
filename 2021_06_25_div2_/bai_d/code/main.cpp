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
const int mod = 1e9 + 7 ;

const int N = 210 ;
vector<int > a[N];
int ans[N];
int cn[N];
int ckn[N];
int check[N];
int n ;
int f[N][N];
int pow( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = pow( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
ii dfs( int  i ){
    int value = 1 ;
    int sl = 1 ;
    if( a[i].size() == 0 ){
        return { 1 , 1 };
    }
    for( auto x : a[i] ){
        if( check[x] != 0 ) continue;
        //debug( x );
        check[x] = 1 ;
        ii y = dfs(  x  );
        sl += y.se ;
        value = value * ckn[ y.se ]  % mod * y.fi % mod ;
        check[x] = 0 ;
    }
    value = value * cn[sl-1] % mod ;
    //debug( i );debug( value );
    return { value , sl  };
}
signed main(){
       // srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cn[0] = 1 ;
    for(int i = 1 ; i < N ; i++){
        cn[i] = cn[i-1]* i ;
    }
    for(int i = 1 ; i < N ; i++){
        ckn[i] = pow( cn[i] , mod - 2  );
    }
    cin>> n ;
    for(int i = 1 ; i < n; i++){
        int x , y ; cin>>x>>y ;x--;y--;
        a[x].pb( y );
        a[y].pb( x );
    }
    for(int i = 0; i < n ; i++ ){
        //cout<<"chay : "<<i<<endl;
        check[i] = 1 ;
        ii x = dfs( i );
        ans[i] = x.fi ;
        check[i] = 0;
     }
     //for(int i = 0 ;i < n ;i++) debug( ans[i] );
     for(int i = 0; i  < n ; i++){
        f[i][0] = 0 ;
        f[ 0 ][i] = 1 ;
     }
     for( int i = 1 ; i < n ; i++ ){
        for(int j = 1 ; j < n ; j++){
            f[i][j] = ( f[i-1][j] + f[i][j-1] ) * ckn( 2 ) % mod ;
        }
     }

}
