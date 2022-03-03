#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int n , l , r ,s , h ;
void in( int a[] ){
    int b[n+1];
    for(int i = 1 ;i <= n ; i++){
        b[i] = 0 ;
    }
    for(int i = 1; i <= h ; i++ ){
        b[ a[i] ] = 1 ;
    }
    int dem = 1;
    for(int i = 1 ; i < l ; i++){
        while(dem<= n && b[dem] == 1 ) dem++;
        cout<<dem<<" ";
        dem++;
    }
    for(int i = 1; i <= h ; i++ ){
        cout<<a[i]<<" ";
    }
    for(int i = r+1 ; i <= n ; i++){
        while(dem <= n && b[dem] == 1 ) dem++;
        cout<<dem<<" ";
        dem++;
    }
    cout<<endl;
    return;
}
void solve(){
    cin>>n>>l>>r>>s;
    h = r - l +1 ;
    int sum1 = 0 ;
    int sum2 = 0 ;
    for(int i = 1 ; i <= h; i++){
        sum1 += i;
        sum2 += ( n+1 - i  );
    }
    if( s < sum1 || s > sum2   ){
        cout<<-1<<endl;
        return;
    }
    int a[h+1];
    for(int i =  1; i <= h ; i++){
        a[i] = i ;
    }
    int sum3 = s - sum1 ;
    for(int i =  h; i >=1 ; i--){
        if( sum3 > n - h ){
            sum3 -= (n-h);
            a[i] = (  n - ( h - i )  ) ;
       //     cout<<"a1:"<<a[i]<<endl;
            continue;
        }
        for( int j = i ; j <= n - ( h - i ) ; j++ ){
            if( j == sum3 + i ){
                a[i] += sum3 ;
                in( a );
                return;
            }
        }
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
