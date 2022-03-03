#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int a[6][N];
string aa[N];
int b[N];
int c[N][3] ;
int main()
{
    int n ,m ;cin>>n>>m;
    if( n>=4 && m >=4 ){
        for(int i = 1 ; i<= n ; i++){
            cin>>aa[i];
        }
        cout<<-1;
        return 0;
    }
    if( n <= m ){
        for(int i = 1 ; i<= n ; i++){
            cin>>aa[i];
            for(int j =1,x ; j<= m ; j++){
                a[i][j] = aa[i][j-1] - 48 ;
            }
        }
    }
    else{
        for(int i = 1 ; i<= n ; i++){
            cin>>aa[i];
            for(int j =1,x ; j<= m ; j++){
                a[j][i] = aa[i][j-1] - 48 ;
            }
        }
        swap(n,m);
    }
    if( n==1 ){
        cout<<0;
        return 0;
    }
    if( n==2 ){
        int ans = 0;
        for(int i = 1 ; i<= m -1 ; i++){
            b[i] =( b[i] + a[1][i] + a[2][i] + a[1][i+1]+a[2][i + 1] )%2 ;
        }
      //  for(int i = 1 ; i<= m -1 ; i++){
       //     cout<<" i:"<<b[i]<<endl;
      //  }
        for(int i = 1 ; i<= m -1 ; i++){
            while(i<= m-1 &&  b[i] ==0 ) i++;
            int dem = 1;
            if( i==m ) dem =0;
            while( i+1<=m-1 && b[i+1] ==1 ) { dem++;i++; }
            if( dem%2 ==0) ans = ans+ dem/2 ;
            else ans = ans + (dem+1)/2;
        }
        cout<<ans;
    }
    if( n==3 ){
        int ans = 0 ;
        for(int i = 1 ; i<= m-1 ; i++){
            c[i][0] += ( a[1][i] + a[1][i+1] + a[2][i] + a[2][i+1])%2 ;
            c[i][1] += ( a[3][i] + a[3][i+1] + a[2][i] + a[2][i+1]) %2;
        }
        for(int i = 1 ; i<=m-1 ;i++ ){
            if( c[i][0] == 1 && c[i][1] == 1 ){
                continue;
            }
            if( i==m-1 ){
                if( c[i][0] == 1 && c[i][1] == 0 ){
                    ans++;
                }
                else ans++;
                break;
            }
            if( c[i][0] == 1 && c[i][1] == 0 ){
                ans++;
                c[i+1][1] = 1 - c[i+1][1];
            }
            else if( c[i][0] == 0 && c[i][1] == 1 ){
                ans++;
                c[i+1][0] = 1 - c[i+1][0];
            }
            else{
                if( i==m-1 ){
                    ans++;break;
                }
                else{
                    if( c[i+1][0] ==1 && c[i+1][1] ==1 ){
                        if( i+1 == m-1 ){
                            ans = ans+2 ;
                            break;
                        }
                        else{
                            if( c[i+2][0] ==1 && c[i+2][1] ==1 ){
                                ans = ans +2 ;
                                i = i +1;
                            }
                            else{
                                ans = ans +2 ;
                                i=i+1;
                                c[i+2][0] = 1 - c[i+2][0];
                                c[i+2][1] = 1 - c[i+2][1];
                            }
                        }
                    }
                    else{
                        ans++;
                        c[i+1][0] = 1 - c[i+1][0];
                        c[i+1][1] = 1 - c[i+1][1];
                    }
                }
            }
        }
       // for(int  i = 1 ; i<= m-1 ;i++){
       //     cout<<"i : "<<i<<"  "<<c[i][2]<<endl;
        //}
        cout<<ans;
    }
    return 0;
}
