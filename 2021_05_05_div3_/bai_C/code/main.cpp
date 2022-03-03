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
    if( n==2 ){
        cout<<"-1"<<endl;
        return;
    }
    if( n==1 ){
        cout<<"1"<<endl;
        return;
    }
    int a[n+1][n+1];
    int dem = 0;
    for(int i = n-1 ; i>=1 ;i-- ){
        for(int j = 0 ; j <= n-i ;j++ ){
            dem++;
            a[i+j][ 1 + j ] = dem;
        }
    }
    for(int i = 2 ; i <= n-1 ;i++ ){
        for(int j = 0 ; j <= n-i ;j++ ){
            dem++;
            a[1+j][ i + j ] = dem;
        }
    }
    a[ n ][1] = dem+1;
    a[1][n] = dem + 2 ;
    for(int i =1; i<= n ;i++){
        for(int j = 1; j<= n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
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
