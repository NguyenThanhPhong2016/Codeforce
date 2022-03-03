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
    int h = 0;
    int x= n ;
    while( x!=0 ){
        h++;
        x = x/10 ;
    }
    int t = 0 ;
    for(int i = 0 ; i< h; i++){
        t = t*10 + 1 ;
    }
    //cout<<"t: "<<t<<endl;
    int ans = 0 ;
    ans += ( h -1 )*9 ;
    for(int i = 9 ; i >=1 ;i--){
        int v = t * i ;
        if( v <= n  ){
            ans += i ;
            break;
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
