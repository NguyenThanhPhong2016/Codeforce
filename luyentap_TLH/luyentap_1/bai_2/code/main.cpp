#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int mod = 1e9 + 7 ;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int pow( int x , int y , int mod1 ){
    if( y ==0 ) return 1;
    if( y ==1 ) return x;
    int z = y / 2 ;
    z = pow( x , z , mod1 ) % mod1 ;
    z = (z*z) %mod1 ;
    if( y % 2 == 1 ) z =  ( z * x) % mod1;
    //cout<<z<<endl;
    return z ;
}
void solve(){
    int a , b ,c ,d ;
    cin>>a>>b>>c>>d;
    b = b%( mod -1 );
    c = c%( mod - 1 );
    a = a%(mod);
    if( b ==1 ){
        int h =( b + c * ( d -1) ) % (mod -1) ;
        cout<<pow( a , h , mod ) ;
        return ;
    }
    int p = (mod -1) ;
    int h = p /2;
    int k;
    if( d==1 ){
        k = 0;
    }
    else if( ( (b-1) ) % h == 0  ){
        int n = d -2 ;
        if( n%2 == 0 ) k =1 ;
        else k = (b+1)%p ;
    }
    else if( (b -1)%2 == 0 ){
        k =  (  (pow(b , d -1 , h) - 1 ) * pow(b-1 , h -2 , h) ) % h ;
        if( k%2 == 0 ) k = k + h ;
        k = ( k * c )%p;
    }
    else{
        k = ( (  ( c*pow(b , d -1 , p) -c  )%p )  * pow( b-1 , p - 3 , p )  ) % p;
    }
    k = pow( b , d , mod -1 ) +  k ;
    //cout<<k<<endl;
    cout<<pow( a , k ,mod );
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
