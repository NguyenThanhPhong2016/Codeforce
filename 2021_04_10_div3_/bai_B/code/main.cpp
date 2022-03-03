#include    <bits/stdc++.h>
#define fi  first
#define se  second
#define ll  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int n ; cin>>n;
    string a[n];
    vector< ii > aa;
    for(int i = 0 ; i<n;i++){
        cin>>a[i];
        for(int j = 0 ; j < a[i].size();j++){
            if( a[i][j] == '*' ){
                aa.pb( {i,j} );
            }
        }
    }
    if( aa[0].fi == aa[1].fi ){
        if( aa[0].fi == 0 ){
            a[1][ aa[0].se ] ='*';
            a[1][ aa[1].se ] = '*';
        }
        else{
            a[0][ aa[0].se ] = '*';
            a[0][ aa[1].se ] = '*';
        }
    }
    else if( aa[0].se == aa[1].se ){
        if( aa[0].se == 0 ){
            a[ aa[0].fi ][ 1 ] ='*';
            a[ aa[1].fi ][ 1 ] ='*';
        }
        else{
            a[ aa[0].fi ][ 0 ] = '*';
            a[ aa[1].fi ][ 0 ] = '*';
        }
    }
    else{
        a[ aa[0].fi ][ aa[1].se ] = '*';
        a[ aa[1].fi ][ aa[0].se ] = '*';
    }
    for(int i =0 ; i< n ; i++){
        cout<<a[i]<<endl;
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
