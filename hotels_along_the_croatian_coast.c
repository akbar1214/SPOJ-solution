#include <stdio.h>

long max(long a,long b){
    return a < b ? b : a;
}

int main() {

    int n,m;
    scanf("%d %d",&n,&m);
    long arr[n+1];
    scanf("%ld",&arr[0]);

    for(int i=1;i<n;i++){
        scanf("%ld",&arr[i]);
        arr[i] += arr[i-1];
    }
    arr[n] = arr[n-1];
    long ans = -1;
    for(int i=0,j=1;i<n;){

        while(j < n && arr[j]-arr[i] <= m){
            ans = max(ans,arr[j]-arr[i]);
            ++j;
        }
        i++;
    }
    printf("%ld",ans);

}
