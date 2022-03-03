#include <iostream>
#define ll long long
using namespace std;
ll a[(ll)1e6+10] ;
const ll N = (ll) 1e9 +7;
int main()
{
    int n ;cin>>n ;
    if( n ==3){
        cout<<2;
        return 0;
    }
    ll temp = 6;
    a[3] = 2;
    for(int i = 4 ;i<= n ;i++){
        a[i] =( ( i*temp - 2*temp ) + 2*a[i-1] )%N ;
        temp = ( temp *i)%N;
    }
    cout<<a[n];
    return 0;
}
