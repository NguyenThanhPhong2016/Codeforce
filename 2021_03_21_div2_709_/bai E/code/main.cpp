#include<bits/stdc++.h>
#define int long long
#define pii pair< int , int>
using namespace std;
const int N = 300010 * 5;
int t[N];
void update(int x , int value){
    t[x] = value;
    while( x>=1 ){
        x /= 2;
        t[ x ] = max( t[2*x] , t[2*x+1] );
    }
}
int searchtree( int v , int a1 , int a2 , int b1 , int b2  ){
    if( b1 <= a1 && a2 <= b2 ) return t[v] ;
    if( a1 > b2 || a2 < b1  ) return -1e18;
    int mid = (a1+a2) /2 ;
    return max(  searchtree( v*2 , a1 , mid ,b1,b2) , searchtree( v*2+1 , mid +1 , a2 , b1 , b2 )   ) ;
}
signed main(){
    int n;cin>>n;
    pii ss[n+1];
    for(int i = 0 ; i < n; i++){
        cin>>ss[i].first;
        ss[i].first--;
    }
    for(int i = 0 ; i < n; i++){
        cin>>ss[i].second;
    }
    int k = 1;
    while(k < n){
        k = k*2 ;
    }
    for(int i = 0 ; i< 2*k ; i++){
        t[i] = -1e18;
    }
    int c[n];
    deque<pii> s;
    for(int i = 0; i< n;i++){
        c[i] = -1 ;
    }
    for(int i = 0; i < n ; i++){
        while( s.size()!=0 && s.front().first > ss[i].first ){
            s.pop_front();
        }
        if( s.size() != 0 ){
            c[i] = s.front().second;
        }
        s.push_front( {ss[i].first , i });
    }
    int dp[n];
    for(int i = 0 ; i < n;i++){
        dp[i] = -1e18 ;
    }
    dp[0] = ss[0].second;
    update( k , dp[0] ) ;
    for(int i = 1 ; i < n ;i++){
        if( c[i] == -1 ){
            int v = searchtree( 1 , 1 , k , 1 , i );
            v = max( v , 0ll ) ;
            dp[i] = v + ss[i].second ;
            update( k+i , dp[i] ) ;
        }
        else{
            int v = searchtree( 1 , 1 , k , c[i]+1  , i );
            dp[i] =max( v + ss[i].second , dp[c[i]] ) ;
            update( k +i , dp[i] ) ;
        }
    }
    cout<<dp[n-1];
}
