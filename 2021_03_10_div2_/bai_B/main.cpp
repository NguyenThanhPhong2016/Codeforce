#include <iostream>

using namespace std;
int b[100010];
int main()
{
    int t ;cin>>t;
    while(t--){
        int n ,k ;
        cin>>n>>k;
        int a[n];
        int maxbt = 0;
        int mexbt = 0 ;
        for(int i = 0; i<n;i++){
            cin>>a[i];
            maxbt = max(a[i],maxbt) ;
            b[(int)min(a[i],100002)]++;
        }
        if( k ==0 ){
            cout<<n<<endl;
            for(int i =0 ;i<100008;i++){
                b[i] = 0;
            }
            continue;
        }
        for(int i= 0; i<=100001;i++){
            if( b[i] ==0 ){
                mexbt = i ;
                break;
            }
        }
        if( mexbt > maxbt ){
            cout<<n+k<<endl;
            for(int i =0 ;i<100008;i++){
                b[i] = 0;
            }
            continue;
        }
        else{
            int dem = 1;int h ;
            if( (mexbt + maxbt) %2 ==0 ) h = (mexbt + maxbt) /2 ;
            else h = (mexbt + maxbt +1)/2;

            for(int i = 0; i< n;i++){
                if( a[i] == h ) dem =0;
            }
            cout<<n+dem<<endl;
        }
        for(int i =0 ;i<100008;i++){
            b[i] = 0;
        }
    }
    return 0;
}
