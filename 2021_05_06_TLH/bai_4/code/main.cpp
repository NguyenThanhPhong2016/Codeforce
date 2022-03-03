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

void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int n , maxbt ;
const int N = 1e5+ 10 ;
int a[N]  ;
int s[N]  ;
void solve(){
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t ;cin>>n>>t>>maxbt;
    cout<<"maxbt : "<<maxbt<<endl;
    for(int i = 1 ;  i <= n ; i++){
        cin>>a[i] ;
    }
    a[0] = 0 ;
    int sum = 0 ;
    int u = 0 ;
    for(int i = 1 ; i<= n ; i++ ){
        sum = sum - a[i-1] ;
        while( sum <= maxbt && u +1 <= n ){
            u++;
            sum += a[u];
            cout<<"SUM : "<<sum<<endl;
        }
        if( u ==n ) u++;
        cout<<i<<" "<<u<<" "<<sum<<endl;
        s[ i ] =  u  ;
    }
    for(int i = 1 ; i <= n ;i++){
        cout<<i<<" "<<s[i]<<endl;
    }
    while(t--){
        solve();
    }
}
