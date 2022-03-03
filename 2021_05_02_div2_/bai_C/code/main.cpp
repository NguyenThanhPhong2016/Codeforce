#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
struct node{
    int mind ;
    int maxd ;
    int nb  ;
};
const int N = 2* (1048576 +10) ;
int maxbt = N -10 ;
node s[N];
//  sort(v.begin(), v.end(), greater<int>());
//
void update( int k , int value  ){
    int h = k ;
    while( h != 0 ){
        s[h].mind = min( value , s[h].mind );
        s[h].maxd = max( value , s[h].maxd );
        s[h].nb++;
        h = h /2 ;
    }
}
void update1( int k , int value  ){
    int h = k ;
    while( h != 0 ){
        //s[h].mind = min( value , s[h].mind );
        //s[h].maxd = max( value , s[h].maxd );
        s[h].nb--;
        h = h /2 ;
    }
}
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int searchnode(int k ,   int l , int r ){
    if( l>r || r < s[k].mind || l > s[k].maxd  ) return 0 ;
    if( l<= s[k].mind && r>= s[k].maxd  ) return s[k].nb ;
    return searchnode( k*2 ,  l , r ) + searchnode( k*2 +1 , l ,r);
}
void searchnode1(int k ,   int l , int r ,int t){
    if( l>r || r < s[k].mind || l > s[k].maxd  ) return 0 ;
    if( l<= s[k].mind && r>= s[k].maxd  ) return s[k].nb ;
    searchnode( k*2 ,  l , r ) + searchnode( k*2 +1 , l ,r);
}
void solve(){
    int n , q ;cin>>n>>q;
    for(int i = 0 ;i < N ; i++){
        s[i].mind = N ;
        s[i].maxd = -1 ;
        s[i].nb = 0;
    }
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        update( a[i] , a[i] );
    }
    for(int o = 0 , x,l,r,t ;o < q;o++){
        cin>>x;
        if( x == 4 ){
            cin>>l>>r;
            cout<<searchnode( 1 , l , r  )<<endl;
        }
        if( x == 1 ){
            cin>>l>>r>>t;

        }
    }

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
