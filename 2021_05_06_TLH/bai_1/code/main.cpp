#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
const int N = 5e5 +10;
const int minbt = -2e9;
int a[N];
int s[N*2] ;
int n , t , k ;

int search_(int v ,  int a1 , int b1 , int l , int r  ){
    //cout<<"ab : "<<a1<<" "<<b1<<" "<<v<<endl;
    if( a1 > r || b1 < l  ) return minbt ;
    if( a1 >= l && b1 <= r ) return s[v] ;
    int mid = (a1 + b1  ) /2;
    return max( search_( v*2 , a1 , mid , l ,r  ) , search_( v*2 +1 , mid +1 , b1 , l ,r  )  ) ;
}
void solve(){
    int l , r ;
    cin>>l>>r;
    int h = search_( 1 , k , 2*k -1 , k+ l-1 ,k+ r-1 );
    cout<<h<<endl;
}
void update(int u , int value ){
    int h = u ;
    while( h != 1 ){
        h = h>>1;
        s[ h ] = max( value , s[h] ) ;
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
    while( k<n ) k=k<<1;
    //cout<<" k : "<<k<<endl;
    for(int i = 1 ; i <= k*2;i++  ){
        s[i] = minbt;
    }
    for(int i = 0 ; i < n ;i++){
        s[ k+i ] = a[i];
        update( k + i , a[i] ) ;
    }
    //for(int i = 1 ; i <= k*2;i++  ){
    //    cout<<i<<" "<<s[i]<<endl;
    //}
    while(t--){
        solve();
    }
}
