#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int canduoi( int x , int y  ){
    return x /y;
}
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
    int dem = 0 ;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if( a[i] > d  ){
            dem++;
        }
    }
    if( dem ==0 ){
        cout<<"YES"<<endl;
        return;
    }
    sort( a , a + n  );
    if( a[0] + a[1] <= d ) cout<<"YES"<<endl;
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
