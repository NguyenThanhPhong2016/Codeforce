#include <iostream>

using namespace std;
int t;
void solve(){
    int n,m;cin>>n>>m;
    string a[n];
    for(int i = 0 ; i<n;i++){
        cin>>a[i];
    }
    if( n==1 ){
        for(int i = 0 ; i< m;i++){
            a[0][i] = 'X';
        }
        cout<<a[0]<<endl;
        return;
    }
    string b = "";
    for(int i = 0 ; i< m;i++){
        a[0][i] = 'X' ;
        b += '.';
    }

    for(int i = 1 ; i < n;i++){
        if( a[i] == b ){
            int h = 0 ;
            while( h < n ){
                if( a[i-1][h] == 'X' ){
                    a[i][h] = 'X';
                    break;
                }
                h++;
            }
            continue;
        }
        for(int j = 0 ; j<m;j++){
            if( a[i][j] == 'X' && a[i-1][j] != 'X' ){
                //cout<<"dang chay tai : "<<i<<" "<<j<<endl;
                if( j < m -1 && a[i-1][j+1] =='X' ){
                  //  cout<<"bien1 :"<<i<<" "<<j+1<<endl;
                    a[i][j+1] = 'X';
                    continue;
                }
                int st = 0 ;
                int h = j - 1 ;
                while( h >=0 ){
                    if( a[i-1][h] == 'X' ){
                        st = 1 ;
                        for(int k = h ; k < j ;k++){
                         //   cout<<"bien2 :"<<i<<" "<<k<<endl;
                            a[i][k] = 'X';
                        }
                        break;
                    }
                    h--;
                }
                h = j + 1 ;
                if(st == 0){
                    while( h < m ){
                        if( a[i-1][h] == 'X' ){
                            for(int k = j +1  ; k <= h ;k++){
                             //   cout<<"bien3 :"<<i<<" "<<k<<endl;
                                a[i][k] = 'X';
                            }
                            j = h;
                            break;
                        }
                        h++;
                    }
                }
            }
        }
    }
    for(int i = 0 ; i<n;i++){
        cout<<a[i]<<endl;
    }
}
void solve1( string a[] ){
    if( t == 4  ){
        a[0] = "X.X";
        a[1] = "XXX";
        a[2] = "X.X" ;
    }
    if( t==3 ){
        a[0] = "....";
        a[1] = ".XXX";
        a[2] = ".X.X";
        a[3] = ".X.X";
    }
    if(t==2){
        a[0] = "XXXXX";
        a[1] = "....X";
        a[2] = ".X..X" ;
        a[3] = "XXXXX";
        a[4] = "X.X.X";
    }
    if( t==1 ){
        a[0] = "XXXXXXXXXX" ;
    }
    if( t== 0 ){
        a[0] = "XX";
        a[1] = "X.";
    }
}
int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
