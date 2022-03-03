#include <iostream>

using namespace std;
int a[102][102];
string b[102];
int ans;
int n , m ;
void dfs( int i , int j ){
    if( i>= n || j >=m ){
        ans++;
        return;
    }
    if( a[i][j] ==1 ) return;
    a[i][j] =1;
    if( b[i][j] =='R'){
        dfs( i,j+1);
    }
    else if( b[i][j] =='D' ){
        dfs(i+1,j);
    }
    else{
        ans++;
        return;
    }
}
void solve(){
    ans = 0 ;
    cin>>n>>m;
    for(int i = 0 ; i< n; i++){
        cin>>b[i] ;
    }
    a[n-1][m-1] = 1;
    for(int i = 0 ; i< n;i++){
        for(int j = 0 ;j<m;j++){
            if( a[i][j] ==0) dfs( i , j );
        }
    }
    cout<<ans<<endl;
    for(int i = 0; i<n;i++){
        b[i] ="" ;
    }

    for(int i = 0 ; i< n;i++){
        for(int j = 0 ;j<m;j++){
            a[i][j] = 0;
        }
    }
}
int main()
{
    int t;cin>>t;
    while( t-- ){
        solve();
    }
    return 0;
}
