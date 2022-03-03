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
const int N = 2e5 +5 ;
const int maxbt = 2e5 + 5 ;
const int minbt = -1;
int n ,k;
int s[N];
vector<int> v;
int search_(  int x , int y   ){
    if( x > y || y >= n +1  ) return maxbt;

    int mid = ( x + y )>>1;
    int kq ;
    if( s[mid] == -1){
        cout<<"? "<<1<<" "<<mid<<endl;
        v.pb( mid );
        fflush( stdout );
        cin>>kq;
        s[mid] = kq;
    }
    else{
        kq = s[mid];
    }
    int so0 = mid - kq ;
    if( so0 > k ){
        return search_( x , mid -1 );
    }
    else if( so0 ==k ){
        return min( search_( x , mid -1 ) , mid );
    }
    else{
        return search_( mid +1 , y ) ;
    }
}
void solve(){
    //cout<<"K:"<<endl;
    cin>>k;
    int h = search_( 1 , n  ) ;
    cout<<"! "<<h<<endl;
    for( auto x : v ){
        if( x >= h ) s[x]++;
    }
}
signed main(){
    for(int i = 0 ; i< N ; i++){
        s[i] = -1;
    }
    int t ; cin>>n>>t;
    while(t--){
        solve();
    }
}
