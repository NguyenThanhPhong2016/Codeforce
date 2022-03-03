#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ktra(int n ){
    int sum = 0;
    int h = n;
    while( h>0 ){
        sum += h%10;
        h=h/10;
    }
    if( __gcd(n,sum) == 1 ) return 1 ;
    else return 0 ;
}
void solve(){
    int n ;cin>>n;
    if( n%3 ==0 ){
    cout<<n<<endl;return;
    }
    if( n%3 ==1 ){
        if( ktra(n) == 0 ){
            cout<<n<<endl;
            return;
        }
        if( ktra(n+1) ==0){
            cout<<n+1<<endl;
            return;
        }
        cout<<n+2<<endl;
        return;
    }
    if( ktra(n) ==0){
            cout<<n<<endl;
            return;
    }
    cout<<n+1<<endl;
}
signed main()
{
    int t ;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
