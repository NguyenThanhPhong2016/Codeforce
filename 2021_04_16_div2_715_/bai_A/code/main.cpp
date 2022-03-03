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
    int a[ n+1 ];
    for(int i = 0 ; i < n ;i++){
        cin>>a[i];
    }
    for(int i =0 ; i< n; i++){
        if( a[i]%2 == 0) cout<<a[i]<<" ";
    }
    for(int i =0 ; i <n;i++){
        if( a[i]%2 ==1  ) cout<<a[i]<<" ";
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
