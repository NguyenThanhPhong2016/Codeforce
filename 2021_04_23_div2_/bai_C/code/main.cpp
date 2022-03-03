#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 503;
int kq[N][N];
void dfs( int value , int dem , int x , int y ){
    //cout<<"X:"<<x<<" "<<y<<endl;
    kq[x][y] = value ;
    if( dem <= 1 ){
        return;
    }
    if( kq[x+1][y] == 0 ){
        dfs( value , dem - 1 , x  + 1 ,y );
    }
    else{
         dfs( value , dem - 1 , x , y -1 );
    }
}
void solve(){
    int n ;cin>>n;
    int a[n+1];
    for(int i =1 ; i <= n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i <= n+1 ;i++){
        kq[0][i] = -1;
        kq[i][0] = -1 ;
        kq[n+1][i] = -1;
        kq[i][n+1] = -1;
    }
    for(int i = n ; i>=1 ; i-- ){
        dfs( a[i] , a[i] , i , i );
    }
    for(int i = 1 ; i <= n ;i++){
        for(int j =  1;  j<= i;j++){
            cout<<kq[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t=1;
    while(t--){
        solve();
    }
}
