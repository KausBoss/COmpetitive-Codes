#include <bits/stdc++.h>

using namespace std;

#define ll long long

string simplifyPath(string path) {
    char s[path.length()+1];
    deque<string> clean;
    for(int i=0; i<path.length(); i++){
    	s[i]=path[i];
    }
    s[path.length()]='\0';

    char *ptr= strtok(s, "/");
    while(ptr!=NULL){
    	string temp= "";
    	while(*ptr!='\0'){
    		temp += *ptr++;
    	}
    	if(temp==".."){if(!clean.empty()){clean.pop_back();}}
	    else if(temp!="" && temp!="."){clean.push_back(temp);}
    	ptr = strtok(NULL, "/");
    }
    string ret="/";
    while(!clean.empty()){
    	ret += clean.front();
    	clean.pop_front();
    	if(!clean.empty()){ret += '/';}
    }
    return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s="/a//b////c/d//././/..";
	cout<<simplifyPath(s);
}