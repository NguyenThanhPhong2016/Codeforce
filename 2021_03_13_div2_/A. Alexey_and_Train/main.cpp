#include <iostream>

using namespace std;
struct ss{
    int a , b, c ,d ;
};
int tinh(int a,int b){
    if( (b-a)%2 ==0 ){
        return (b-a)/2;
    }
    else return (b-a+1)/2;
}
int main()
{
    int t ;cin>>t ;
    while(t--){
        int n ; cin>>n ;
        ss x[n+1];
        int y[n+1];
        x[0].a = 0;
        x[0].b = 0;
        x[0].c = 0;
        x[0].d = 0;
        for(int i = 1 ; i <= n;i++){
            cin>>x[i].a>>x[i].b;
            x[i].c = tinh(x[i].a,x[i].b);
        }
        for(int i = 1 ; i<= n ;i++){
            cin>>y[i];
        }

        for(int i = 0; i<n;i++ ){
            x[i].d =  x[i+1].a - x[i].b;
        }
        for(int i=1;i<=n;i++){
            x[i].a = x[i-1].b + x[i-1].d + y[i];
            x[i].b = max(x[i].b , x[i].a + x[i].c)  ;
        }
        cout<<x[n].a<<endl;
    }
    return 0;
}
