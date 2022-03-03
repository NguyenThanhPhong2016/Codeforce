#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int  n , k ;
    cin>>n;cin>>k;
    cout<<"n:"<<n<<" :"<<k<<endl;
    int a[62];
    for(int i = 0 ; i<= 62 ; i++){
        a[i] = 0;
    }
    cout<<k-1<<endl;
    int kp = k - 1;
    cout<<kp<<endl;
    /* int dem = 0;
    while( kp > 0 ){
        dem++;
        if( kp % 2 == 1 ) a[dem] = 1 ;
        else a[dem] = 0 ;
        kp=kp/2;
    }
    a[0] = 0 ;
    cout<<"dem:"<<dem<<endl;
    if(dem > n ){
        cout<<"-1"<<endl;
        return;
    }
    for(int i = n - 1 ; i >=0 ; i--){
        int j = i ;
        while( a[i] == 1 ){
            i--;
        }
        for( int l = n - i ; l >= n - j  ;l-- ){
            cout<<l<<" ";
        }
    }
    cout<<endl;
    */
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
