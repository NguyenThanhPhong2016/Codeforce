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
struct node{
    int a[5];
    node();
};
void solve(){
    int n ; cin>>n ;
    if( n==1 ){
        for(int i = 0 ; i< 5 ; i++ ){
            int x ; cin>>x;
        }
        cout<<1<<endl;return ;
    }
    int a[n][5];
    int kq[5] ;
    kq[0] = -1 ;
    int id = 0 ;
    for(int i = 0;  i< n ; i++){
        for(int j = 0 ; j< 5 ; j++){
            cin>>a[i][j];
            a[i][j] = 50000 - a[i][j];
        }
    }
    for(int i = 0 ; i < 5 ;i++){
        kq[i] = a[0][i];
    }
    for(int i = 1 ; i< n ; i++){
        int dem = 0 ;
        for(int j = 0 ; j  < 5 ; j++){
            if( a[id][j] > a[i][j]  ) dem++;
        }
        if( dem < 3 ) id = i ;
    }
    for(int i = 0 ; i < n ; i++){
        if( i == id ) continue;
        int dem =0 ;
        for(int j = 0 ; j  < 5 ; j++){
            if( a[id][j] > a[i][j]  ) dem++;
        }
        if( dem <= 2 ){
            cout<<-1<<endl; return ;
        }
    }
    cout<<id+1<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
