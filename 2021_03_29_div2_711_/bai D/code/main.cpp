#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int const N = 1e5 ;
int n ,m;
int kq[N+10];
int ss[N+10][3] ;
int v[N+10];
int dem = 1;
vector<int> s1 ;
int cantren1( int x ){
    if( x%N ==0) return x/N;
    else return (x-x%N)/N + 1 ;
}
void xuli( int k ){
    int l = s1.size();
    if( l == m-dem +1 ){
        cout<<"l :"<<l<<endl;
        return;
    }
  //  cout<<"l : "<<l<<endl;
  //  cout<<"m:"<<m-dem+1<<endl;
    if( ss[k][0] ==1 ){
        for(int j = 0 ; j < l ; j++){
            int x = s1[j] ;
         //   cout<<"k1 : "<<k<<" s1 "<<j<<" : "<<s1[j]<<endl;
            for(int i = 0 ; i < ss[k][2] ; i++ ){
                x = x + ss[k][1] ;
                if( x > m || x==0 ) break;
                if(kq[ x ] == -1 ){
                    kq[ x ] = k ;
                    s1.push_back( x ) ;
                }
                else{
                    break;
                }
            }
        }
    }
    else{
        for(int j = 0 ; j < l ; j++){
            int x = s1[j];
         //   cout<<"k2 : "<<k<<" s1 "<<j<<" : "<<s1[j]<<endl;
            for(int i = 0 ; i < ss[k][2] ; i++ ){
                x = cantren1( x * ss[k][1] ) ;
                if( x > m || x ==0  ) break;
                if(kq[ x ] == -1 && x!= 0 ){
                    kq[ x ] = k ;
                    s1.push_back( x ) ;
                }
                else break;
            }
        }
    }
    if( k < n) xuli( k+1 );
}
void test(){
    n = 198 ;
    m =99 ;
    for(int i = 1 , t ; i<= n; i++){
        ss[i][0] = rand()%2 ;
        ss[i][1] = rand()%(100000*m-10000) + 1e5 ;
        if(ss[i][0] ==1 ) ss[i][1] = cantren1(ss[i][1]);
        ss[i][2] = rand()%(m);
      //  ss[i][1] = 2;
    }
    for(int i = 1; i < n; i++){
        if( ss[i][1] ==1 ){
            dem = 0;
            break;
        }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i = 1 , t ; i<= n; i++){
        cin>>ss[i][0]>>ss[i][1]>>ss[i][2];
        if(ss[i][0] ==1 ) ss[i][1] = cantren1(ss[i][1]);
    }
    for(int i = 1 ; i <= n;i++){
        if(ss[i][0] ==1 ){
            v[ ss[i][1] ] = 1 ;
        }
    }
    int k = 0 ;
    while( k+1 <= m && v[k+1] == 0 ){
        k++;
    }
    dem = k ;
  //  cout<<"k :"<<k<<endl;
    test() ;
    for(int i = 0 ; i <= m ;i++){
        kq[i] = -1 ;
    }
    s1.push_back(0);
    xuli( 1 ) ;
    for(int i = 1 ; i <= m ;i++){
        cout<<kq[i]<<" ";
    }
    return 0;
}
