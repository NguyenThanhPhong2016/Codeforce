#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
int n ;
int h[(int) 2e5 + 10];
vector<int> a;
void solve(){
    cin>>n;
    int sum = 0 ;
    for(int i = 0 , x ; i < n ; i++){
        cin>>x;
        a.push_back(x);
        sum += a[i];
    }
    if( sum %2 == 1 ){
        cout<<0<<endl;
        return ;
    }
    int sum1 = sum/2;
    h[0] =1 ;
    for(int i = 0 ; i < n ;i++){
        for(int j = sum1 ; j >= a[i] ; j--){
            if( h[j]== 0 && h[j - a[i] ]== 1 ) h[j] =1;
        }
    }
    //for(int i = 0 ; i <= sum1 ; i++){
    //    cout<<i<<" : "<<h[i]<<endl;
    //}
    if( h[sum1] == 0 ){
        cout<<0<<endl;
        return ;
    }
    else{
        //int dem = 0;
        while(  true  ){
            //cout<<11<<endl;
            for(int i = 0 ; i< n ;i++){
                if( a[i]%2 ==1 ){
                    cout<<1<<endl;cout<<i+1<<endl;
                    return;
                }
            }
            for(int i = 0 ; i<n;i++){
                a[i] = a[i]/2;
            }
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
