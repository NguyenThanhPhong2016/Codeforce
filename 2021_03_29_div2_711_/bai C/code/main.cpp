#include <iostream>
#define int long long
using namespace std;

int const N = 1e9 + 7 ;
void solve(){
    int n , k ;cin>>n>>k;
    if(k==1){
        cout<<1<<endl;
        return;
    }
    if( n==1 ){
        cout<<2<<endl;
        return;
    }
    if( n==2 ){
        cout<<k+1<<endl;
        return ;
    }
    int kq = 0 ;
    int a[n];
    for(int i = 1 ; i < n;i++){
        a[i] = 1;
        kq += a[i] ;
    }
    int h = k;
    h--;
    while( h >=2 ){
        h--;
        if( ( k + h) %2 == 0 ){
            for(int i = n -2 ; i>=1;i--){
                a[i] = (a[i+1] + a[i] )% N ;
            }
        }
        else{
            for(int i = 2 ; i<= n -1 ; i++){
                a[i] = (a[i-1] + a[i] ) % N;
            }
        }
        for(int i = 1 ; i < n;i++){
            kq = ( kq + a[i] )%N;
        }
      //  for(int i = 1; i<n; i++){
       //     cout<<a[i]<<" ";
        //}
    }
 //   for(int i =1 ; i <= n-1;i++ ){
  //      cout<<"a "<<i<<" "<<a[i]<<endl;
  //  }
    cout<<kq+2<<endl;
}
signed main()
{
    int t;cin>>t ;
    while(t--){
        solve();
    }
    return 0;
}
