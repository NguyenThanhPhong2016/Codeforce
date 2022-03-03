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
const int N =1e6 + 10 ;
int kt[N];
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m , k ; cin>>m>>k;
    vector<int> a[k];
    int s[k] ;
    for(int i = 0 ; i< k ; i++){
        a[i].resize(m);
        s[i] = 0;
        for(int j = 0 ; j < m ; j++){
            cin>>a[i][j];
            s[i] += a[i][j] ;
        }
    }
    int ds[k] ;
    for(int i = 1 ; i < k; i++  ){
        ds[i] = s[i] - s[0] ;
    }
    int id = -1 ;
    for(int i = 1 ; i < k ; i++){
        if( ds[i] % i != 0 ){
            id  = i ; break ;
        }else{
            ds[i] /= i ;
        }
    }
    if( id == -1 ){
        int value ;
        map<int , int > a1 ;
        for(int i = 1 ; i< k ; i++){
            a1[ ds[i] ]++;
        }
        for(auto x : a1){
            if( x.se == 1 ){
                value = x.fi ;
            }
        }
        for(int i = 1 ; i< k ; i++){
            if( ds[i] == value  ){
                id = i ;
            }
        }
    }
    for(int i = 0 ; i< m ; i++){
        kt[ a[id][i] ]++;
    }
    int y  = rand()%4 + 1  ;
    y = 1;
    if( y == id ) y++;
    int sumbt = 0 ;
    sumbt = s[0] + ( s[y] - s[0] )/y * id ;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if( a[0][i] > a[y][j] ) continue;
            int z = a[y][j] - a[0][i] ;
            if( z % y !=0  ) continue;
            int p = s[0] - a[0][i] ;
            int q = s[y] - a[y][j] ;
            int kq = p + ( ( q - p )/y )*id ;
            kq = sumbt - kq ;
            if( false &&  i ==0 && j == 1 ){
                debug( a[0][i]  );debug( a[y][j] );
                debug( kq );
            }
            kt[kq]--;
        }
    }
    int ans = -1 ;
    for(int i= 0 ; i < 50 ;i++){
        //cout<<i<<" "<<kt[i]<<endl;
    }
    for(int i = 0 ; i < N ; i++){
        if( kt[i] > 0 ){
            ans = i ; break ;
        }
    }
    cout<<id<<" "<<ans + sumbt - s[id]<<endl;
}
