#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 2e5 +2 ;
const int mod = 998244353;
int n ;
int maxbt ;
int s1[N];
int s[N];
int a[N];
int kqbt ;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int cantren( int x ,int y  ){
    if( (y-x)%2 ==0 ) return y;
    else return y -1;
}
int mid( int x ,int y ){
    if( x%2 ==1 ){
        int z = ( x+y )/2;
        if( z%2==1 ) return z ;
        else return z +1;
    }
    else{
        int z = ( x+y ) /2 ;
        if( z%2 ==0 ) return z ;
        else return z +1 ;
    }
}
int xuli( int k , int bg , int ed , int x ,int y   ){
    if( k == -1  ){
        int h = x*a[0] + y*a[n-1] ;
        //cout<<"h: "<<h<<endl;
        if( h <= maxbt  ) return k;
        else return -1;
    }
    if( bg > ed ) return -1;
    int midbt = mid( bg , ed );
    int h = s[ midbt ] - s[k] + s1[k] - (1-x)*a[0] + y*a[n-1];
    //cout<<"h: "<<h<<endl;
    if( h <= maxbt ){
        return max( midbt , xuli( k , midbt +2 , ed , x , y  )  );
    }
    else{
        return xuli( k , bg , midbt -2 , x , y  );
    }
}
void solve(){
    kqbt =0;
    cin>>n ;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    if( n==1 ){
        cout<<1<<endl;
        return;
    }
    s1[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        s1[i] =s1[i-1] +a[i] ;
    }
    if( s1[n-1] % 2 ==0  ){
        maxbt = s1[n-1]/2 - 1;
    }
    else{
        maxbt = ( s1[n-1] -1 )/2;
    }
    //cout<<"maxbt : "<<maxbt<<endl;
    s[0] = a[0] ;
    s[1] = a[1] ;
    for(int i = 2 ; i <n ; i++){
        s[i] = s[i-2] + a[i];
    }
    for(int k = 1 ; k<= n -2 ; k++){
        int dem = 0;
        for(int i = 0 ; i <= 1 ;i++){
            for(int j = 0 ; j <= 1 ; j++){
                int h;
                if( k!= n-2) h = xuli(k , k , cantren( k ,  n -2 -j ) , i , j   );
                else h = xuli( n-2 , n -2 , n -2 , i , j );
                if( h == -1 ) continue;
                //cout<<k<<"  "<<h<<" : "<<kqbt<<" ; "<<i<<" "<<j<<endl;
                kqbt = ( kqbt + (h - k )/2 +1 ) % mod;
                dem++;
            }
        }
        if( dem==0 ) break;
    }
    int h ;
    h = xuli(0 , 0 , cantren( 0 ,  n -2 ) , 1 , 0   );
    //cout<<0<<"  "<<h<<" : "<<kqbt<<" ; "<<1<<" "<<0<<endl;
    if( h != -1 ) kqbt = ( kqbt + h/2 + 1 ) % mod;
    if( n !=2 ) h = xuli(0 , 0 , cantren( 0 ,  n -2 -1 ) , 1 , 1   );
    else h = xuli(0 , 0 , cantren( 0 ,  n -2 ) , 1 , 1   );
    //cout<<0<<"  "<<h<<" : "<<kqbt<<" ; "<<1<<" "<<1<<endl;
    if( h != -1 ) kqbt = ( kqbt + h/2 + 1 ) % mod;
    //h = xuli(0 , 0 , cantren( 0 ,  n -2 ) , 0 , 0   );
    //if( h == -1 ) kqbt = kqbt + h/2 + 1;
    int sum1 = 0;
    kqbt++;
    for(int i = n -1 ; i >= 2 ; i--){
        sum1 += a[i];
        if( sum1 <= maxbt ) kqbt++;
    }
    if( n==2 ){
        sum1 += a[1];
        if( sum1 <= maxbt ) kqbt++;
    }
    cout<<kqbt%mod<<endl;
    /*
    for(int i = 0 ;i < n -1 ; i++){
        s[i] = 0 ;
        s[i-1] = 0 ;
    }
    */
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
