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
    int n , d ;cin>>n>>d;
    int a[n];
    for(int i = 0 ;  i< n ;i++){
        cin>>a[i];
    }
    for(int i = 1;  i< n;i++){
        int h = a[i] * i ;
        if( h <= d ){
            a[0] += a[i];
            d = d - h ;
        }
        else{
            a[0] += ( d/i );
            break;
        }
    }
    cout<<a[0]<<endl;
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
