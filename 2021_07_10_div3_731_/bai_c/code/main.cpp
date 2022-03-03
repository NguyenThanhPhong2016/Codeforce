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
    int k , n , m ;
    cin>>k>>n>>m ;
    int a[n] ;
    int b[m] ;
    int ans[n+m] ;
    for(int i =0 ; i < n ; i++) cin>>a[i];
    for(int i =0 ; i < m ; i++) cin>>b[i];
    int dem = -1 ;
    int la = 0 , lb = 0 ;
    while( dem +1 != n+m ){
        dem++;
        if( la < n && a[la] == 0 ){
            la++;
            k++;
            ans[dem] = 0 ;
            continue;
        }
        else if( lb < m &&  b[lb] == 0 ){
            ans[dem] = 0 ;
            k++;
            lb++;
            continue;
        }
        if(la < n && a[la] <= k ){
            ans[dem] = a[la] ;
            la++;continue;
        }
        else if(lb < m && b[lb] <= k ){
            ans[dem] = b[lb] ;
            lb++;continue;
        }
        else{
            cout<<"-1"<<endl;return ;
        }
    }
    for(int i = 0 ; i < n + m ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
