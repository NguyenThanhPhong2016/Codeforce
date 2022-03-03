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
bool scp( int x){
    int y = sqrt( x) ;
    //cout<<y<<" "<<x<<endl;
    if( y*y ==x ) return true;
    else return false;
}
void solve(){
    int x;cin>>x;
    if( x % 2 !=0 ){
        cout<<"NO"<<endl;return;
    }
    if( x%4 == 0 && scp( x ) == true   ){
        cout<<"YES"<<endl;
    }
    else if( x % 2 == 0 && scp( x/2 ) == true  ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
