#include<stdio.h>
#include<math.h>
int main(){
    float a,b;
    scanf("%lf %lf",&a,&b);
    float result = sqrt(a*a+b*b);
    printf("%.2f",result);
    return 0;   
}
