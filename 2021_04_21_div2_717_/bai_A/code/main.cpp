#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];
    }
    int sum = 0 ;
    int i = -1 ;
    while( k >= sum ){
        if( i== n -1 ){
            for(int j = 0 ;j < n -1 ; j++ ){
                cout<<0<<" ";
            }
            cout<<sum<<endl;
            return ;
        }
        i++;
        sum += a[i];
    }
    //cout<<sum<<endl;
    sum -= a[i] ;
    int h = k - sum ;
    a[i] = a[i] - h ;
    for(int j  = 0 ; j <i ;j++){
        cout<<0<<" ";
    }
    for(int j = i ; j <n-1;j++){
        cout<<a[j]<<" ";
    }
    cout<<a[n-1] + k<<endl;

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
