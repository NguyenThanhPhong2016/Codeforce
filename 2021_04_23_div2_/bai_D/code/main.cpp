#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 1004;
int sss[N][N][21] ;
int ss[N][N] ;
void solve(){
    int n , m , k ;cin>>n>>m>>k;
    for(int i = 2 ; i <= 2*n ; i=i+2 ){
        for( int j = 3 ; j <= 2*m ;j=j+2 ){
            cin>>ss[i][j];
        }
    }
    for(int j = 3 ; j<= 2*n; j= j+2){
        for(int i = 2; i <= 2*m;i=i+2){
            cin>>ss[j][i];
        }
    }
    /*
    for(int i = 2 ; i <= 2*m ; i = i +2){
        for(int j = 3 ; j <= 2*n;j=j+2){
            cin>>ss[j][i];
        }
    }
    */
    if( k%2 == 1 ){
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1 ; j<= m ;j++){
                cout<<"-1 ";
            }
            cout<<endl;
        }
        return;
    }
    for(int h = 2 ;h <= k ;h = h +2){
        for(int i = 2 ; i <= 2*n ; i= i +2 ){
            for(int j = 2 ; j <= 2*m;j = j +2){
                sss[i][j][h] = (int) 1e10;
                if( i> 2 ){
                    sss[i][j][h] = min( sss[i][j][h] , sss[i-2][j][h-2] + 2*ss[i-1][j] );
                }
                if( j > 2 ){
                    sss[i][j][h] = min( sss[i][j][h] , sss[i][j-2][h-2] + 2*ss[i][j-1] );
                }
                if( j < 2*m ){
                    sss[i][j][h] = min( sss[i][j][h] , sss[i][j+2][h-2] + 2*ss[i][j+1] );
                }
                if( i < 2*n ){
                    sss[i][j][h] = min( sss[i][j][h] , sss[i+2][j][h-2] + 2*ss[i+1][j] );
                }
            }
        }
    }
    for(int i = 2 ; i <= 2*n;i=i+2){
        for(int j = 2 ; j<= 2*m;j=j+2){
            cout<<sss[i][j][k]<<" ";
        }
        cout<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1 ;
    while(t--){
        solve();
    }
}
