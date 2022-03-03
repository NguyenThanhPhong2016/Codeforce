#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
const int N = 1e5 +4;
using namespace std;
void solve(){
    int  n , k ;cin>>n>>k;
    int a[N];
    for(int i = 0 ; i< N ; i++){
        a[i] = 0;
    }
    int k1  = k - 1 ;
    int dem = 0;
    while( k1 > 0 ){
        dem++;
        if( k1 % 2 == 1 ) a[dem] = 1 ;
        else a[dem] = 0 ;
        k1=k1/2;
    }
    //cout<<dem<<endl;
    a[0] = 0 ;
    if(dem >= n ){
        cout<<"-1"<<endl;
        return;
    }
    for(int i = n - 1 ; i >=0 ; i--){
        int j = i ;
        while( a[i] == 1 ){
            i--;
        }
        for( int l = n - i ; l >= n - j  ;l-- ){
            cout<<l<<" ";
        }
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
