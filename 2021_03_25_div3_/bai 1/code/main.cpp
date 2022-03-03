#include <iostream>
#define ll long long
using namespace std;
void solve(){
    ll n , m , x;
    cin>>n>>m>>x;
    if( x % n != 0 ){
        ll p = x /n +1;
        ll q = x%n ;
        cout<<m*(q-1)+p<<endl;
    }
    else{
        ll p = x /n ;
        ll q = n ;
        cout<<m*(q-1)+p<<endl;
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
