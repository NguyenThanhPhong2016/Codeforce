#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 1e5 + 10 ;
int a[N];
int b[N];
int n ;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n ; i++){
        cin>>b[i];
    }
    int ans = 0 ;
    for(int i = 0; i < n ; i++){
        ans += a[i]*b[i];
    }
    int maxbt = 0 ;
    for(int i = 0 ; i < n ; i++){
        int maxbt1 = 0 ;
        for(int x = i ; x >= 0 ; x--){
            int y = 2*i - x  ;
            if( y >  n-1 ) break;
            maxbt1 += ( a[y] - a[x] )*( b[x] - b[y] ) ;
            maxbt = max( maxbt1 , maxbt ) ;
        }
    }
    for(int i = 0 ; i < n -1 ; i++){
        int maxbt1 = 0 ;
        for(int x = i ; x >= 0 ; x--){
            int y = 2*i + 1- x  ;
            if( y >  n-1 ) break;
            maxbt1 += ( a[y] - a[x] )*( b[x] - b[y] ) ;
            maxbt = max( maxbt1 , maxbt ) ;
        }
    }
    cout<<ans+maxbt<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t=1;
    while(t--){
        solve();
    }
}
