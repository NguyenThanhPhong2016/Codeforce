#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
const int x = 1e9 + 7  ;
const int y = 1e9 + 21 ;
void solve(){
    int n ;cin>>n;
    int a[n+1];
    for(int i = 1;  i <= n ; i++){
        cin>>a[i];
    }
    int z = 0 ;
    int t = 0 ;
    vector< pair<ii,ii> > kq;
    for(int i = 1; i < n ; i++){
        if( __gcd( a[i] , a[i+1] ) != 1 ){
            if( z==0 ){
                if( a[i] < a[i+1] ){
                    a[i+1] = x ;
                    z = 1 ;
                    kq.pb( { {i,i+1} , { a[i] , x } } );
                }
                else{
                    a[i] = x ;
                    z = 1 ;
                    kq.pb( { {i,i+1} , { x , a[i+1] } } );
                }
            }
            else{
                if( a[i] < a[i+1] ){
                    a[i+1] = y ;
                    z = 0 ;
                    kq.pb( { {i,i+1} , { a[i] , y } } );
                }
                else{
                    a[i] = y ;
                    z = 0 ;
                    kq.pb( { {i,i+1} , { y , a[i+1] } } );
                }
            }
        }
    }
    cout<<kq.size()<<endl;
    for(int i = 0 ; i < kq.size() ; i++){
        cout<<kq[i].fi.fi<<" "<<kq[i].fi.se<<" "<<kq[i].se.fi<<" "<<kq[i].se.se<<endl;
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
