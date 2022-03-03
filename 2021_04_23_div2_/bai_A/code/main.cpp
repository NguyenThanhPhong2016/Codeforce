#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int n;cin>>n;
    if( n% 2050 !=0 ){
        cout<<-1<<endl;
        return;
    }
    int h = n / 2050;
    int sum = 0;
    while( h !=0  ){
        sum += h%10;
        h = h /10;
    }
    cout<<sum<<endl;
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
