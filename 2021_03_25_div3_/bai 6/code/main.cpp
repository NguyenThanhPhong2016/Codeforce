#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int time( int r1 , int c1 , int r2 , int c2 ){
    if( r1 - c1 == r2 - c2 ) return ( (r1+c1+1)%2 )*(r2-r1);
    int h1 = (r1 -c1) /2 ;
    int h2 = (r2 - c2 ) / 2 ;
    return h2 - h1 ;
}
void solve(){
    int n ;cin>>n;
    vector<pii> a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i].first;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i].second;
    }
    a.push_back( {1,1} );
    int sum = 0;
    sort( a.begin() , a.end() ) ;
    for(int i = 0 ; i<n;i++){
        sum = sum + time( a[i].first , a[i].second , a[i+1].first, a[i+1].second );
    }
    cout<<sum<<endl;
}
int main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
