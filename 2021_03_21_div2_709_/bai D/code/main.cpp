#include <bits/stdc++.h>
using namespace std;
struct sss{
    int x ;
    int y ;
    int z ;
};
vector<int> kq;
void in(){
    cout<<kq.size()<<" ";
    for(int i = 0 ;i<kq.size();i++){
        cout<<kq[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    kq.clear();
    int n ;cin>>n;
    sss a[n];
    for(int i = 0; i < n;i++){
        cin>>a[i].x;
    }
    if( n==1 ){
        if( a[0].x ==1 ) cout<<"1 1"<<endl;
        else cout<<0<<endl;
        return;
    }
    for(int i =0;i<n-1;i++){
        a[i].y = i+1;
        a[i].z = min( __gcd(a[i].x ,a[ a[i].y ].x) ,2 );
    }
    a[n-1].y = 0;
    a[n-1].z = min( __gcd(a[n-1].x ,a[ a[n-1].y ].x) ,2 );
    int temp =0 ;
    int dem1 =0 , dem2 = 0 , nk = n ;
    int p[n];
    for(int i = 0;i<n;i++){
        p[i]=0;
    }
    vector<int> k ;
    for(int i = 0;i<n;i++){
        k.push_back(i);
    }
    while( true  ){
        for(int j = 0 ; j < k.size();j++){
            int i = k[j];
            if( p[i] != -1 ){
                if( a[i].z ==1 ){
                kq.push_back( a[i].y +1 );
                k[dem1]=i;
                p[ a[i].y ] = -1;
                a[i].y=(a[ a[i].y].y )%n;
                a[i].z= min( __gcd(a[i].x ,a[ a[i].y ].x) ,2 );
                if( i == a[i].y ){
                    if( a[i].x ==1){
                        kq.push_back( i +1 );
                        in();
                        return;
                    }
                    else{
                        in();
                        return;
                    }
                }
                dem1++;
                }
            }
        }
        if( dem1 == 0 ){
            in();
            return;
        }
        else{
            k.resize(dem1);
            dem1 =0;
        }
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
