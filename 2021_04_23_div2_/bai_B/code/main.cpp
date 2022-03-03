#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int xet[101][101];
void solve(){
    int n ,m ;cin>>n>>m;
    set< iii > sss;
    int ss[n][m];
    for(int i = 0 ; i< n ;i++){
        for(int j = 0 ; j< m ;j++){
            cin>>ss[i][j];
            sss.insert( { ss[i][j] , {i,j} } ) ;
        }
    }
    int dem1 = 0;
    int kq[n][m];
    for(int i = 0 ; i< n ;i++){
        for(int j = 0 ; j< m ;j++){
            kq[i][j] = 0;
        }
    }
    int dem2 = 0 ;
    for(auto x : sss){
        if( dem2 == m ) break;
        dem2++;
        kq[  x.se.fi  ][ dem1] = x.fi ;
        xet[ x.se.fi ][ (x.se).se ] = 1;
        dem1++;
    }
    vector< int > v[n];
    for(int i = 0 ; i< n ;i++){
        for(int j = 0 ; j< m ;j++){
            if( xet[i][j] == 0 ){
                v[i].push_back( ss[i][j] );
            }
        }
    }
    for(int i = 0 ; i< n ;i++){
        int dem = 0 ;
        for(int j = 0 ; j< m ;j++){
            if( kq[i][j] == 0 ){
                kq[i][j] = v[i][dem];
                dem++;
            }
        }
    }
    for(int i= 0 ; i < n; i++){
        for(int j = 0 ; j < m ;j++){
            cout<<kq[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i= 0 ; i < n; i++){
        for(int j = 0 ; j < m ;j++){
            xet[i][j] = 0;
        }
    }
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
