#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int n ;cin>>n;
    string s ;
    cin>>s;
    int dem = 0;
    int dem1 = 0;
    for(int i = 0; i< s.size() ; i++){
        if( s[i] == 'T' ) dem++;
        else{
            dem1++;
            dem = dem - 1 ;
            if( dem < 0  ){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    int dem2 = 0 ;
    int dem3 = 0 ;
    for(int i = n-1;i>=0;i--){
        if( s[i] =='T' ){
            dem2++;
        }
        else{
            dem3++;
            dem2 = dem2 - 1 ;
            if( dem2 < 0  ){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    if( dem1 == dem && dem2 == dem3 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
