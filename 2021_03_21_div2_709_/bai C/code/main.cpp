#include <bits/stdc++.h>

using namespace std;
void start(){
    int n ,m;cin>>n>>m;
    int m1;
    if( m%2==0 ) m1 = m/2;
    else m1 = (m+1)/2;
    vector< int > ss[m];
    int pp[n+1];
    for(int i = 0 ; i<= n;i++){
        pp[i]=0;
    }
    for(int i = 0 ; i < m ; i++){
        int k;cin>>k;
        for(int j = 0,x ; j < k ;j++){
            cin>>x;
            ss[i].push_back(x);
        }
    }
    int kq[m];
    for(int i = 0 ; i< m;i++){
        kq[i]= -2;
    }
    for(int i = 0 ; i<m;i++){
            if( ss[i].size() == 1 ){
                kq[i]=ss[i][0] ;
                pp[ kq[i] ] ++;
            }
    }
    for( int i = 1; i<= n;i++ ){
        if( pp[i] > m1 ){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i = 0; i< m;i++){
        if( kq[i] != -2) continue;
        for(int j = 0;j<ss[i].size();j++){
            if( pp[ss[i][j] ] < m1  ){
                pp[ss[i][j] ]++;
                kq[i]=ss[i][j];
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i= 0 ; i<m;i++){
        cout<<kq[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--){
        start();
    }
    return 0;
}
