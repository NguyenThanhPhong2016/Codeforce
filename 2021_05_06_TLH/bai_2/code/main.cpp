#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());

const int N = 1e5 +10;
const int minbt = -2e9 - 10 ;
const int maxbt = 2e9 + 10  ;
int a[N];
ii s[N*8] ;
int cnt[N*8] ;
int n , t , k ;
void update(int u , int value ){
    int h = u ;
    while( h != 1 ){
        h = h/2;
        cnt[h]++;
        s[ h ].fi = min( value , s[h].fi ) ;
        s[ h ].se = max( value , s[h].se ) ;
    }
}
int search_( int value , int minbt1 ,int maxbt1 ){
    while( true ){
        if( cnt[value] == 0 ) return 0;
        int minbt2 = min( s[value].fi , minbt1 ) ;
        int maxbt2 = max( s[value].se , maxbt1 ) ;
        if(  maxbt2 - minbt2 <= t  ){
            int h = cnt[value] + search_( value +1 , minbt2 , maxbt2 );
            //cout<<" h : "<<h<<" : "<<value<<endl;
            return h ;
        }
        else{
            value = value*2 ;
            continue;
        }
    }
}
void update1(int u ){
    int h = u ;
    while( h != 1 ){
        h = h/2;
        cnt[h]--;
        s[ h ].fi = min( s[h*2+1].fi , s[h*2].fi ) ;
        s[ h ].se = max( s[h*2+1].se , s[h*2].se ) ;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(int i = 0; i < n ;i++){
        cin>>a[i];
    }
    k=1;
    while( k<n ) k=k*2;
    //cout<<" k : "<<k<<endl;
    for(int i = 1 ; i <  N*8;i++  ){
        s[i].fi = maxbt;
        s[i].se = minbt;
        cnt[i] = 0 ;
    }
    for(int i = 0 ; i < n ;i++){
        s[ k+i ].fi = a[i];
        s[ k+i ].se = a[i];
        cnt[ k+i] = 1;
        update( k + i , a[i] ) ;
    }
    int ans = 1 ;
    for( int i = 0 ; i < n -1 ; i++ ){
        int kq = search_( 1 , a[i] , a[i] );
        ans = max( ans , kq ) ;
        s[k + i].fi = maxbt;
        s[k + i].se = minbt;
        cnt[k + i] = 0 ;
        update1( k + i ) ;
        //cout<<" ans : "<<ans<<endl;
    }
    cout<<ans<<endl;
}
