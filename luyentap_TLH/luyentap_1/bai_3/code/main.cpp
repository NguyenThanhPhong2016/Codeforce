#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n ;cin>>n;
    int a , b ;
    a = 2 ;
    b = 3 ;
    int c ;
    if( n ==1 ){
        cout<<0;
        return;
    }
    if( n==2 ){
        cout<<1;
        return ;
    }
    int x = 1;
    for(int i = 1 ; i <= n ; i++){
        x = ( x*2 )%mod ;
    }
    for(int i = 3 ; i <= n ;i++){
        c = ( a + b ) % mod ;
        a = b ;
        b = c ;
    }
    cout<<( x + mod - b )%mod;

}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1;
    while(t--){
        solve();
    }
}
