#include <bits/stdc++.h>
using namespace std;
struct sz_values{
        int count=0;
        int d1=0;
        int d2=0;
        int d3=0;
};
unordered_map<string,string> parent;
unordered_map<string,sz_values> sz;

void make_set(string a,int dept){
    parent[a] = a;
    sz[a].count = 1;
    sz[a].d1 = 0; sz[a].d2 = 0; sz[a].d3 = 0;
    if(dept==1){
        sz[a].d1+=1;
    }
    if(dept==2){
        sz[a].d2+=1;
    }
    if (dept==3){
        sz[a].d3+=1;
    }
}
string find_set(string a){
    if(parent[a]==a)
        return a;
    return parent[a] = find_set(parent[a]);
}
void union_set(string a, string b){
    a = find_set(a);
    b= find_set(b);
    if(a==b){
        return;
    }
    if(a!=b){
        if(sz[a].count < sz[b].count){
            string temp = a;
            a=b;
            b=temp; 
        }
        parent[b] = a;
        sz[a].count+=sz[b].count;
        sz[a].d1+=sz[b].d1;
        sz[a].d2+=sz[b].d2;
        sz[a].d3+=sz[b].d3;
    }
}
vector<string> split_string(string);

void theHackathon(int &n, int &m, int &a, int &b, int &f, int &s, int &t) {
    if(a>b||n<a){
        cout<<"no groups"<<endl;
        return;
    }
    unordered_map<string,int> employees;
    string name; int dept;
    for(int i=0;i<n;i++){
        cin>>name;
        cin>>dept;
        employees[name] = dept;
        make_set(name,dept);
    }
    string x,y;
    int max_size=0;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x = find_set(x);
        y = find_set(y);
        if(sz[x].count+sz[y].count<=b && sz[x].d1+sz[y].d1<=f && sz[x].d2+sz[y].d2<=s && sz[x].d3+sz[y].d3<=t){
            union_set(x,y);
        }
    }
    for(auto it:parent){
    	parent[it.first]=find_set(it.first);
    }
    map<string,vector<string>> groups;
	for(auto it:parent){
		groups[it.second].push_back(it.first);
	}
	vector<string> ans;
	for(auto it:groups){
		if(it.second.size()>=a && it.second.size()<=b 
			&& it.second.size()>ans.size()){
			ans=it.second;
		}
	}
	sort(ans.begin(),ans.end());
	if(ans.size()==0){
	    cout<<"no groups"<<endl;
        return;
	}
	for(auto it:ans){
		cout<<it<<endl;
	}
    //--------------------------------------------------
    /*string check;
    for(auto blah: sz){
        if(blah.second.count>max_size){ 
            max_size = max(max_size,blah.second.count);
            check = blah.first;
        }
    }
    
    if(max_size<a){
        cout<<"no groups"<<endl;
        return;
    }
    vector<string> largestGroups;
    for(auto i:sz){
        if(i.second.count==max_size){
            largestGroups.push_back(i.first);
        }
    }
    vector<vector<string>> ans;
    int ind =0;
    for(int i=0;i<largestGroups.size();i++){
        vector<string> temp;
    for(auto h: employees){
        if(find_set(h.first)==largestGroups[i]){
            temp.push_back(h.first);
        }
    }
    ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    for(auto v:ans){
        sort(v.begin(),v.end());
        for(auto xx: v){
            cout<<xx<<endl;
        }
    }
    */
    
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}