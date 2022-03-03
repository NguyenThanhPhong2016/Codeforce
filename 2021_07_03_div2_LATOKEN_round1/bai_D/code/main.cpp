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
const int N =2e3 + 10 ;
int tt[N];
int tt1[N];
int n ;
vector<int> s[2];
void read( int p ){
    if( p==1 ){
        for(int i = 1 ; i<= n ; i++){
            tt[i] = tt1[i];
        }
        return ;
    }
    cout<<"? "<<p<<endl;
    fflush(stdout);
    for(int i = 1 ; i<= n ; i++){
        cin>>tt[i];
    }
}
void read1( int p ){
    cout<<"? "<<p<<endl;
    fflush(stdout);
    for(int i = 1 ; i<= n ; i++){
        cin>>tt1[i];
    }
}
signed main(){
    cin>>n ;
    read1( 1 );
    for(int i = 1 ; i <= n; i++){
        s[ tt1[i] & 1 ].push_back( i );
    }
    int id = 0 ;
    if( s[0].size() == s[1].size()  ){
        id = 0 ;
    }
    else if( s[0].size() < s[1].size() ){
        id = 0 ;
    }
    else{
        id = 1;
    }
    vector< ii > edge ;
    for(auto x : s[id]){
        read( x );
        for(int i = 1 ; i <= n ; i++){
            if( tt[i] == 1 ){
                int a = x , b = i ;
                if( a < b ) swap( a , b);
                edge.pb( {a , b} );
            }
        }
    }
    if( edge.size() != n-1 ){
        cout<<edge.size()<<endl;
        return 0;
    }
    cout<<"!"<<endl;
    for(auto [x , y ] : edge){
        cout<<x<<" "<<y<<endl;
    }
}
