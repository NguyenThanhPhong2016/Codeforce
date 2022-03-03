#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
const int mod = 1e9 + 7 ;
const int N = (1e5 + 2 )*20 ;
int a[N];
using namespace std;
int mu( int n , int k ){
    if( k == 1 ) return n ;
    int h = k/2 ;
    int x = mu( n , h );
    x = (x * x )%mod;
    if( k%2 ==1 ) x = (x*n )%mod;
    return x ;
}
void solve(){
    int n ,k;cin>>n>>k;
    cout<<mu(n,k)<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    a[0] = 1;
    for(int i = 1; i<N;i++){
        a[i] = ( a[i-1]*2 )% mod;
    }
    while(t--){
        solve();
    }
}
