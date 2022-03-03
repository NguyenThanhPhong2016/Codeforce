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
    int n ;cin>>n;
    int x = pow( (double) n , (double) 1.0/3 );
    for( int i = 1 ; i<= x ; i++ ){
        int h = n - i*i*i;
        int k = pow( (double) h , (double) 1.0/3 );
        if( k == 0 ) continue;
        if( h == k * k * k  || h == (k+1)*(k+1)*(k+1) || ( k>=2 && h == (k-1)*(k-1)*(k-1)  ) ){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
