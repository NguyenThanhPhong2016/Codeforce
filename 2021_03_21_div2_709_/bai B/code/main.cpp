#include <iostream>

using namespace std;
void xuli(){
    int n ;cin>>n;
    int a[n];
    for(int i = 0; i< n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<endl;return;
    }
    if(n==2){
        cout<<0<<endl;return;
    }
    if( a[0] == a[1] ){
        int temp = -1;
        for(int i = 2;i<n;i++){
            if( a[i] != a[i-1] ){
                cout<<-1<<endl;return;
            }
        }
        cout<<0<<endl;
        return;
    }
    for(int i = 1 ; i<n;i++){
        if( a[i] >= a[i-1] ){
            int c = a[i] - a[i-1];
            int m = -1;
            for(int j =1 ;j <n;j++){
                if( a[j] >= a[j-1] ){
                    if( a[j] - a[j-1] != c ){
                        cout<<-1<<endl;return;
                    }
                }
                else{
                    if( m == -1 ) m = a[j-1] + c - a[j];
                    if( m != a[j-1] + c - a[j] ){
                        cout<<-1<<endl;return;
                    }
                }
            }
            if( m == -1 ) {cout<<0<<endl;return; }
            else{
                for(int i =0 ; i< n ; i++){
                    if( a[i] >= m ) {cout<<-1<<endl;return;}
                }
                cout<<m<<" "<<c<<endl;return;
            }
        }
    }
    int d = a[0] - a[1];
    for(int i = 2 ; i<n;i++){
        if( a[i-1] - a[i] !=d ){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<0<<endl;
}
int main()
{
    int t ;cin>>t;
    while(t--){
        xuli();
    }
    return 0;
}
