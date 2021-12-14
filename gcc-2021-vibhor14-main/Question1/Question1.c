#include<stdio.h>


int solution(int &n)
{
    //code here
    if(n%3==0){
        return 2*(n/3);
    }
    else{
        return 1+ (n/3)*2;
    }
}

/* Do not edit below code */
int main(void) {
    int n;
    scanf("%d",&n);
    int answer=solution(n);
    printf("%d",answer);
    return 0;
}