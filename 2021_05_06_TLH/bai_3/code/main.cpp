#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
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
const int N = 2e5+10;
int a[N];
int b[N][33];
int n ;

void solve(){
    int x , y ; cin>>x>>y;
    int ans = x ;
    if( y==0 ){
        cout<<x<<endl;
        return ;
    }
    vector<int> v;
    while( y!=0 ){
        v.pb( y%2 );
        y = y / 2 ;
    }
    for(int i = v.size() -1 ; i >= 0 ; i--  ){
        if( v[i] != 0) ans = b[ ans ][ i ];
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>n>>t;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
        b[i][0] = a[i] ;
    }
    for(int i = 1 ; i < 33 ;i++){
        for(int j = 1 ; j <= n ;j++){
            //cout<<"b : "<<b[j][i-1]<<endl;
            b[ j ][ i ] = b[ b[j][i-1] ][ i-1 ];
        }
    }
    while(t--){
        solve();
    }
}
