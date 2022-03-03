#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int a[ (int)1e5+10 ];
void solve(){
    int n  ;cin>>n;
    vector<int> kq ;
    for(int i = 1 ; i <= n ;i++){
        if( __gcd( n , i ) == 1  ) a[i] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        if( a[i] ==1 ) kq.pb(i);
    }
    int k = 1;
    for(int i = 0 ; i < kq.size() ; i++){
        k= ( k*kq[i] ) % n ;
    }
    int x ;
    if( k == 1 ) x = kq.size();
    else x = kq.size()  - 1 ;
    //cout<<"in"<<endl;
    //cout<<kq.size()<<endl;
    cout<<x<<endl;
    for(int i = 0 ;i < x ; i++){
        cout<<kq[i]<<" ";
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; ;t=1;
    while(t--){
        solve();
    }
}
