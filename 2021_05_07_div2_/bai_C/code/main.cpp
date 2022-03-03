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
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
const int N = 1e4 + 10;
int ans[N];
void solve11( int n , int k ){
    ans[k] = n ;
    for(int i = 1 ; i <= n ; i++){
        if( i==k  ) continue;
        cout<<"? "<<2<<" "<<i<<" "<<k<<" "<<1<<endl;
        fflush( stdout );
        cin>>ans[i];
    }
    cout<<"! ";
    for(int i = 1 ; i <= n ;i++){
        cout<<ans[i]<<" ";
        ans[i] = 0;
    }
    cout<<endl;
}
void solve1(int n ){
    int b[n+1];
    vector<int> v;
    for(int i = 1 ; i <= n ;i = i +2){
        cout<<"? "<<1<<" "<<i<<" "<<i+1<<" "<<n-1<<endl;
        fflush( stdout );
        cin>>b[i];
        if( b[i] ==n ){
            solve11( n , i + 1);
            return;
        }
        if( b[i] == n -1 ){
            v.pb( i );
        }
    }
    if( v.size() == 1 ){
        solve11( n , v[0] );
        return;
    }
    int h = 1 ;
    if( h== v[0] ) h++;
    if( h== v[1] ) h++;
    int k;
    cout<<"? "<<1<<" "<<h<<" "<<v[0]<<" "<<n-1<<endl;
    fflush( stdout );
    cin>>k;
    if( k==n ){
        solve11( n , v[0] );
        return;
    }
    else{
        solve11( n , v[1] );
        return;
    }
}
void solve2( int n ){
    int b[n+10];
    vector<int > v;
    for(int i = 1 ; i < n ;i = i +2){
        cout<<"? "<<1<<" "<<i<<" "<<i+1<<" "<<n-1<<endl;
        fflush( stdout );
        cin>>b[i];
        if( b[i] ==n ){
            solve11( n , i +1);
            return;
        }
        if( b[i] == n -1 ){
            v.pb( i );
        }
    }
    if(true ){
        cout<<"? "<<1<<" "<<n-1<<" "<<n<<" "<<n-1<<endl;
        fflush( stdout );
        cin>>b[n-1];
        if( b[n-1] == n ){
            solve11( n , n );
            return;
        }
        if( b[n-1] == n -1 ){
            v.pb( n-1 );
        }
    }
    if( v.size() == 1 ){
        solve11( n , v[0] );
        return;
    }
    int h = 1 ;
    for(int i = 0 ; i < v.size() ; i++ ){
        if( h== v[i] ) h++;
    }
    for(int i = 0 ; i < v.size() ; i++ ){
        int k ;
        cout<<"? "<<1<<" "<<h<<" "<<v[i]<<" "<<n-1<<endl;
        fflush( stdout );
        cin>>k;
        if( k==n ){
            solve11( n , v[i] );
            return;
        }
    }
    cout<<"! 0 0 0"<<endl;
}
void solve(){
    int n ;cin>>n;
    if( n==1 ){
        cout<<"! 1"<<endl;
        return;
    }
    if( n <= 2 ){
        int k ;
        cout<<"? "<<1<<" "<<1<<" "<<2<<" "<<1<<endl;
        fflush( stdout );
        cin>>k;
        if( k==2 ){
            cout<<"! 1 2"<<endl;
        }
        else{
            cout<<"! 2 1"<<endl;
        }
        return;
    }
    if( n%2 == 0 ){
        solve1(n);
    }
    else{
        solve2(n);
    }

}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
