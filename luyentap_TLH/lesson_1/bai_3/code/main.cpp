#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n ; cin>>n;
    int a[n] ;
    for(int i = 0 ; i <n ; i++){
        cin>>a[i];
    }
    sort( a,a+n );
    int minbt = a[1] - a[0];
    for(int i = 1 ; i < n ;i++ ){
        minbt = min( minbt , a[i] - a[i-1] );
    }
    cout<<minbt<<endl;
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
