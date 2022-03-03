#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int n ;cin>>n;
    int dem =0;
    for(int i = 0 , x ; i< n ;i++){
        cin>>x;
        int a = sqrt( x );
        if( x != a*a ){
            dem = 1;
        }
    }
    if( dem ==0 ) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
