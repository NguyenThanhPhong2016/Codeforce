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
int color[N];
int a[N];
vector<int> k[N];
void merge(int x, int y , int z) {
    int h = color[x] ^ color[y] ;
    if(  a[x] == a[y]  ){
        if( h == z ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }
    if( k[ a[x] ].size() < k[ a[y] ].size() ){
        swap( x  ,y  );
    }
  //  debug(x);debug(y) ;
    int lp = y ;
    if( h == z ){
        for( auto p : k[ a[y] ] ){
            a[p]  = a[x];
            k[ a[x] ].pb( p );
        }
    }
    else{
        for( auto p : k[ a[y] ]){
            a[p]  = a[x];
            color[p] = 1 - color[p];
            k[ a[x] ].pb( p );
        }
    }
    k[lp].clear();
    cout<<"YES"<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , q ;cin>>n>>q;
    for(int i =1 ; i <= n ;i++){
        k[i].pb( i );
        a[i] = i ;
        color[i] = 0 ;
    }
    while( q-- ){
        int u , v , x ; cin>>u>>v>>x ;
        x= 1 -x ;
        merge( u , v ,x );
        if( q==0 ){
            for(int i = 1 ; i<= 10 ; i++){
                cout<<i<<"  : ";
                for(auto p : k[i]){
                    cout<<p<<" ";
                }
                cout<<endl;
            }
        }

    }
}
