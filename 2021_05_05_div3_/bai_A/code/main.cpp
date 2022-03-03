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
int a[200];
void solve(){
    int n ;
    cin>>n;
    string s ;
    cin>>s;
    a[ s[0] ] = 1;
    for(int i = 1; i < n ; i++){
        if( s[i] == s[i-1] ) continue ;
        if( a[ s[i] ] == 1 ){
            cout<<"NO"<<endl;
            for(int i = 0; i <199;i++){
                a[i] = 0;
            }
            return;
        }
        a[ s[i] ] = 1;
    }
    cout<<"YES"<<endl;
    for(int i = 0; i <199;i++){
        a[i] = 0;
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
