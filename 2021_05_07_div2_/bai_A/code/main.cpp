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

void solve(){
    int a ,b ;cin>>a>>b;
    if(b==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if( b==2 ){
        cout<<3*a<<" "<<a<<" "<<4*a<<endl;
    }
    else{
        cout<<a<<" "<<(b-1)*a<<" "<<b*a<<endl;
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
