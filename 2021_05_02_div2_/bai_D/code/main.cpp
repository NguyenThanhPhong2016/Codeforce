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
    int n , l , r ;
    cin>>n>>l>>r;
    int a[n+1];
    int sl[n+1];
    int sr[n+1];
    for(int i = 0 ; i <= n ; i++){
        a[i] = 0;
        sl[i] = 0;
        sr[i] = 0;
    }
    for(int i =1 ;i <= l ; i++){
        cin>>a[i];
        sl[ a[i] ]++;
    }
    for(int i = l+1 ;i <= n ; i++){
        cin>>a[i];
        sr[ a[i] ]++;
    }
    int ans = n/2 ;
    for(int i = 1 ; i <= n; i++ ){
        if( sl[ i ] >= sr[ i ] ){
            sl[i] -= sr[i];
            ans = ans -  sr[i] ;
            sr[i] = 0;
        }
        else{
            sr[i] -= sl[i];
            ans = ans -  sl[i] ;
            sl[i] = 0;
        }
    }
    //cout<<"ANSQ : "<<ans<<endl;
    if( l > r  ){
        int h = ( l - r  )/2;
        ans += h;
        int x = 0;
        for(int i = 1;  i<= n ;i++){
            x += sl[i]/2;
        }
        if( x<= h ){
            ans = ans - x ;
        }
        else{
            ans = ans - h ;
        }
    }
    else{
        int h = ( r - l  )/2;
        ans += h;
        int x = 0 ;
        for(int i = 1;  i<= n ;i++){
            x += sr[i]/2;
        }
        if( x<= h ){
            ans = ans - x ;
        }
        else{
            ans = ans - h ;
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
