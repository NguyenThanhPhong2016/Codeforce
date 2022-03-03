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
    int n , y ; cin>>n>>y;
    int a[n];
    int maxbt = -1 ;
    for(int i = 0, x ; i <n ;i++){
        cin>>a[i];
    }
    sort( a, a + n ) ;
    if( y % a[n-1] == 0  ){
        cout<<y/a[n-1]<<endl;
        return ;
    }
    int ans = y/a[n-1];
    int h = y % a[n-1];
    for(int i = 0 ; i < n ; i++){
        if( h == a[i] ){
            cout<<ans+1<<endl;
            return;
        }
    }
    ans = ans +2 ;
    int minbt = y / ( ans - 1 ) ;
    for(int i = n-1 ;i >= 0 ;i--){
        if( a[i] >= minbt ){
            if( y % a[i] ==0 ){
                ans = min( y / a[i] , ans );continue;
            }
            int k = y % a[i];
            int u  = lower_bound( a , a + i +1 , k ) - a ;
            if( a[u] == k ){
                ans = min( y / a[i] + 1 , ans  );
            }
        }
        else{
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
