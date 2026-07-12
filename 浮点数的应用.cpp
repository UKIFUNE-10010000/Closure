#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0){
        printf("0\n");
        return 0;
    }
    int re=0;
    int w=1;
    while(n!=0){
        int d=n%10;
        re+=(d%2)*w;
        n=n/10;
        w*=10;
    }
    return 0;
}

