#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 3e5 + 6;
int mang[N];
int tren(int x , int y){
    if( (y - x )%2 ==0 ) return ( y - x )/2 ;
    else return ( y - x +1) /2;
}
void solve(){
    int n , q ;cin>>n>>q;
    int a[n+1];
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    for(int i = 0 , x,y ; i < q; i++){
        cin>>x>>y;
        int m = tren( x , y+1 ) ;
        //cout<<"m:"<<m<<endl;
        for(int j =  x; j <= y ; j++){
            mang[ a[j] ]++;
        }
        int dem = 0;
        for(int j = 1 ; j < N;j++){
            //if(  j<6) cout<<j<<" : "<<mang[j]<<endl;
            if( mang[j] > m  ){
                dem =1 ;
                int u = y +1 -x - mang[j];
                if( u *2 >= mang[j] ) cout<<mang[j] - 1 - u * 2<<endl;
                else{
                    cout<<mang[j] - u<<endl;
                }
                break;
            }
        }
        if( dem ==0 )cout<<1<<endl;
        for(int j =1 ; j<N;j++){
            mang[j] = 0;
        }
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t = 1;
    while(t--){
        solve();
    }
}
