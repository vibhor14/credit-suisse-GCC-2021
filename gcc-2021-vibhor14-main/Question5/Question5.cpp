using namespace std;
#include <string>
#include <iostream>
#include<bits/stdc++.h>

string solution(string &s){
    int count =0;
    unordered_map<int, int> ev;
    unordered_map<int, int> od;
    int maxeven=0,maxodd=0,countEven=0,countOdd=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            if(count!=0 && count%2==0){
                maxeven = max(maxeven,count);
                ev[count]++;
                countEven++;
            }
            if(count!=0 && count%2!=0){
                maxodd= max(maxodd,count);
                od[count]++;
                countOdd++;
            }
            count =0;
        }
        else if(s[i]=='0'){
            count++;
        }
    }
    if(count!=0&&count%2==0){
        maxeven = max(maxeven,count);
        ev[count]++;
        countEven++;
    }
    if(count!=0&&count%2!=0){
        maxodd= max(maxodd,count);
        od[count]++;
        countOdd++;
    }
    if(countOdd==0&&countEven==0){
        return "B";
    }
    if(countOdd==0){
            return "B";
    }
    if(countEven==0){
        if(countOdd==1){
            return "A";
        }
        else if(countOdd>1){
            int abanks = maxodd/2+1;
            od[maxodd]--;
            for(auto x: od){
                if(x.first>=abanks &&x.second>0){
                    return "B";
                }
            }
            return "A";
        }
    }
    else{
        int abanks = maxodd/2+1;
        od[maxodd]--;
        for(auto x: od){
            if(x.first>=abanks &&x.second>0){
                return "B";
            }
        }
        for(auto y: ev){
            if(y.first>=abanks){
                return "B";
            }
        }
        return "A";
    }
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
