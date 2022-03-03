#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int mod = 1e9 + 7 ;
const int mod1 = ( mod - 1 ) /2 ;
int ans ;
int ss[2][2][ 62 ];
int ss5[2][2][ 62 ];
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int pow( int x ,int y , int m ){
    if( y ==1  ) return x ;
    if( y==0  ) return 1 ;
    int z = y /2 ;
    z = pow( x , z , m ) % m  ;
    z = ( z*z )%m;
    if( y %2 ==1 ) z = (z * x ) % m ;
    return z ;
}
void xuli( int dem , int value , int mu1 , int mu2   ){
    //cout<<"dem "<<dem<<"  :  "<<value<<"  "<<mu1<<"  "<<mu2<<endl;
    ans = ( ( ans * pow( 2 , dem*mu1 , mod ) ) % mod )  * ( mod1 +1 ) ;
    ans = ans%mod ;
    ans = (  ans * pow( value , mu2 , mod )  ) % mod ;
    //cout<<ans<<endl;
}
void xuli2( int dem , int value , int mu1 , int mu2   ){
//cout<<"dem1 "<<dem<<"  :  "<<value<<"  "<<mu1<<"  "<<mu2<<endl;
    ans = ( ( ans * pow( 2 , dem*mu1 , mod ) ) % mod ) ;
    ans = (  ans * pow( value , mu2 , mod )  ) % mod ;
    //cout<<ans<<endl;
}
void solve(){
    ans =1 ;
    int a , b , n ;
    cin>>a>>b>>n;
    a = a % mod ;
    b = b % mod ;
    if( n == 1 ){
        cout<<a<<endl;
        return;
    }
    if( n==2 ){
        cout<<b<<endl;
        return ;
    }
    ss[0][0][0] = 1 ;
    ss[0][1][0] = 1 ;
    ss[1][0][0] = 1 ;
    ss[1][1][0] = 0 ;

    ss5[0][0][0] = 1 ;
    ss5[0][1][0] = 1 ;
    ss5[1][0][0] = 1 ;
    ss5[1][1][0] = 0 ;

    for(int k = 1 ; k <= 61 ; k++){
        for(int i = 0 ; i< 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                for( int h = 0 ; h < 2 ; h++ ){
                    ss5[i][j][k] += ss5[i][h][k-1]*ss5[h][j][k-1] ;
                    ss[i][j][k] += ss[i][h][k-1]*ss[h][j][k-1] ;
                }
                ss5[i][j][k] = ss5[i][j][k] % ( mod1 -1 ) ;
                ss[i][j][k] = ss[i][j][k] % ( mod -3 ) ;
            }
        }
    }
    vector<int > v ;
    int x = n - 1 ;
    while( x !=0  ){
        v.pb( x%2 );
        x = x /2;
    }
    int ss1[2][2] ;
    int ss2[2][2] ;
    ss1[0][0] = 1 ;
    ss1[0][1]=  0 ;
    ss1[1][0] = 0 ;
    ss1[1][1] = 1 ;
    ss2[0][0] = 0 ;
    ss2[0][1] = 0 ;
    ss2[1][0] = 0 ;
    ss2[1][1] = 0 ;
    int ss3[2][2];
    ss3[0][0] = 1 ;
    ss3[0][1] = 0 ;
    ss3[1][0] = 0 ;
    ss3[1][1] = 1 ;
    int ss4[2][2] ;
    ss4[0][0] = 0 ;
    ss4[0][1] = 0 ;
    ss4[1][0] = 0 ;
    ss4[1][1] = 0 ;
    int dem3 = 0;
    int dem4 = 0;
    for(int k = 0 ; k< v.size() ; k++){
        if( v[k] ==0  ) continue;
        for(int i = 0 ; i< 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                for( int h = 0 ; h < 2 ; h++ ){
                    ss4[i][j] += ss3[i][h]*ss5[h][j][k] ;
                    ss2[i][j] += ss1[i][h]*ss[h][j][k] ;
                }
            }
        }
        if( ss4[1][0] >= mod1 - 1  ) dem3 = 1 ;
        if( ss4[1][1] >= mod1 - 1  ) dem4 = 1 ;
        for(int i = 0 ; i< 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                ss1[i][j] = ss2[i][j] % ( mod -3 ) ;
                ss2[i][j] = 0;
                ss3[i][j] = ss4[i][j] % ( mod1 -1) ;
                ss4[i][j] = 0;
            }
        }
    }
    int dema = 0 , demb = 0;
    while( a% 2 == 0  ){
        dema++;
        a = a /2 ;
    }
    while( b % 2 == 0  ){
        demb++;
        b = b /2 ;
    }
    if( dem3 == 1 ){
        xuli( demb , b , ss3[1][0] , ss1[1][0]  );
    }
    else{
        xuli2( demb , b , ss3[1][0] , ss1[1][0]  );
    }
    if( dem4 == 1 ){
        xuli( dema , a , ss3[1][1] ,ss1[1][1] );
    }
    else{
        xuli2( dema , a , ss3[1][1] ,ss1[1][1] );
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1;
    while(t--){
        solve();
    }
}
