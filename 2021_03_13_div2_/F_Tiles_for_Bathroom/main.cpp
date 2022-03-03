#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define N 1505
using namespace std;
typedef  pair<int,int> ii;
vector< ii > s[N][N];
int a[N][N];
vector<ii> res ;
int mp[N*N];
int n,q ;
int ans[N];
void begins1(vector<ii> &r , vector<ii> res1 ){
    for(auto o : res1) r.pb({o.fi+1,o.se});
}
void begins( int i , int j  ){
    res.clear();
    res.pb( {1,a[i][j]}) ;
    if( i < n ) begins1(res, s[i+1][j] );
    if( j < n ) begins1(res, s[i][j+1] );
    if( i< n && j < n ) begins1(res, s[i+1][j+1] );
    sort(res.begin(),res.end());
    for( auto x : res ){
        if( mp[x.se] !=0 ) continue;
        mp[x.se] =1;
        s[i][j].pb( x );
        if( s[i][j].size() == q+1 ) break ;
    }
    for(auto x : res ){
        mp[x.se] =0 ;
    }
}
int main()
{
    cin>>n>>q;
    for(int i = 1 ; i <= n;i++){
        for(int j = 1 ; j<= n ;j++){
            cin>>a[i][j];
        }
    }
    for(int i = n ; i >= 1; i--){
        for(int j = n ; j >=1;j--){
            begins( i , j ) ;
        }
    }

    for(int i = n ; i >= 1; i--){
        for(int j = n ; j >=1;j--){
            cout<<endl;
            cout<<"i: "<<i<<" j : "<<j<<endl;
            cout<<endl;
            for(int k = 0 ; k < s[i][j].size() ;k++){
                cout<<s[i][j][k].fi<<" ";
            }
            cout<<endl;
            for(int k = 0 ; k < s[i][j].size() ;k++){
                cout<<s[i][j][k].se<<" ";
            }
        }
    }
    ans[1] = n*n;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n;j++){
            int temp = min( n +1 - i , n + 1 - j ) ;
            if( s[i][j].size() == q+1){
                temp = min( temp , s[i][j][q].fi -1  );
            }
            cout<<"temp :"<<temp<<endl;
            ans[temp+1]--;
        }
    }
    int kq=ans[1];
    for(int i = 1 ; i<=n;i++){
        cout<<kq<<endl;
        kq += ans[i+1];
    }
    return 0;
}
