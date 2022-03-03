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

void solve(){
    int n ;cin>>n;
    int a[n+1];
    int b[2*n+10];
    for(int i =1;i<=n;i++){
        cin>>a[i];
        a[i] = a[i] - i + n +1 ;
        b[i] = 0;
    }
    for(int i = 1 ;i < 2*n +10 ;i++){
        b[ i ] = 0;
    }
    for(int i = 1 ;i <= n ;i++){
        b[ a[i] ]++;
    }
    int ans = 0 ;
    for(int i = 1 ;i < 2*n +10 ;i++){
        if( b[i] >=2 ){
            int t = ( b[i] -1 )*b[i]>>1;
            ans += t ;
        }
    }
    cout<<ans<<endl;

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
