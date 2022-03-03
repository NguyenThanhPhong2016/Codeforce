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
    string a , b ; cin>>a>>b ;
    int n = a.size();
    int dem = 1 ;
    set< ii > s ;
    for(int i =  0 ; i < n ; i++){
        if(  a[i] ==  b[0] ){
            s.insert( { i , 0 } ) ;
        }
    }
    if( s.size() == 0 ){
        cout<<"NO"<<endl;
        return ;
    }
    while( dem < b.size() ){
        //debug(dem );
        set< ii > s1 ;
       // int kq = 0 ;
        for(auto x : s  ){
            //debugp( x );
            if( x.se == 0 ){
                if( x.fi -1 >= 0 &&  a[ x.fi-1 ] == b[dem] ){
                    s1.insert( { x.fi -1 , 1 } );
                }
                if( x.fi + 1 <= n -1 && a[ x.fi+1 ] == b[dem] ){
                    s1.insert( { x.fi +1 , 0 } );
                }
            }
            else{
                if( x.fi -1 >= 0 &&  a[ x.fi-1 ] == b[dem] ){
                    s1.insert( { x.fi -1 , 1 } );
                }
            }
        }
        if( s1.size() !=0  ){
            s = s1 ;
        }
        else{
            cout<<"NO"<<endl;
            return ;
        }
        dem++;
    }
    cout<<"YES"<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
