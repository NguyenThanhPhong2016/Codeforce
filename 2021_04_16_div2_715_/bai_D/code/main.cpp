#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
const int N = 4e5 +10;
int n ;
using namespace std;
void in( string x , string y , char z ){
   // cout<<x<<endl;
   // cout<<y<<endl;
   // cout<<"z:"<<z<<endl;
    vector<int> a;
    vector<int> b ;
    a.pb( -1 );
    b.pb( -1 );
    char t ;
    if( z=='0' ) t = '1';
    else t = '0';
    for(int i = 0 ; i< 2*n ;i++){
        if( x[i] == z ) a.pb(i);
        if( y[i] == z ) b.pb(i);
    }
    a.pb( n+1 );
    b.pb(n+1);
    for(int i = 0 ; i< n ; i++ ){
        for(int j = a[i] + b[i]  ; j< a[i+1] + b[i+1] - 2 ; j++  ){
            cout<<t;
        }
        cout<<z;
    }
   // cout<<endl;
  //  cout<<"a:"<<a[n]<<endl;
  //  cout<<b[n]<<endl;
    for(int i = a[n] +1; i< 2*n ;i++ ){
        cout<<x[i];
    }
    for(int i = b[n] +1; i< 2*n ; i++){
        cout<<y[i];
    }
    cout<<endl;
}
void solve(){
    cin>>n;
    string s1 ,s2,s3;
    cin>>s1>>s2>>s3;
    int dem1 = 0 ;
    int dem2 = 0 ;
    int dem3 = 0 ;
    for(int i = 0; i < 2*n;i++){
        if( s1[i] == '0'  ) dem1++;
        if( s2[i] == '0' ) dem2++;
        if( s3[i]== '0' ) dem3++;
    }
    if( dem1 <= n){
        if( dem2 <= n ){
            in( s1 , s2 , '1' );
            return;
        }
        else{
            if( dem3 <= n ){
                in( s1,s3 ,'1');
            }
            else{
                in( s2,s3 , '0' );
            }
        }
    }
    else{
        if( dem2 >= n ){
            in( s1 , s2 , '0' );
            return;
        }
        else{
            if( dem3 >= n ){
                in( s1,s3 ,'0' ) ;
            }
            else{
                in( s2,s3 , '1' );
            }
        }
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
