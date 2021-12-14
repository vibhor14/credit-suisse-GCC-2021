using namespace std;
#include <string>
#include <iostream>

int solution(int &n){
    if(n%3==0){
        return 2*(n/3);
    }
    else{
        return 1+ (n/3)*2;
    }
}
/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}