#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int a[2002];
int n ;
void solve(){
    cin>>n;
    for(int i = 0 ; i<n;i++){
        cin>>a[i];
    }
    int k = 0 ;
    for(int i = 0  ; i <= n- 1 ; i++){
        k = k ^ a[i];
    }
    if( k == 0 ){

        cout<<"YES"<<endl;
        return;
    }
    else{
        int h = 0;
        int dem = 0;
        for(int i = 0 ; i<= n-1;i++){
            h = h^a[i];
            if( h == k ){
                dem++;
                h =0;
                if( dem==2 ){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
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
