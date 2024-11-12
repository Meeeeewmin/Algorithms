//
//  Keylogger.cpp
//  Lecture_Day2
//
//  Created by 민오 on 11/12/24.
//

#include <cstdio>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int T;
list<char> pwd;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    string s;
    
    while(T--){
        cin >> s;
        pwd.clear();
        auto it = pwd.begin();
        
        for(int i=0;s[i];i++){
            if(s[i] == '<'){
                if(it == pwd.begin())
                    continue;
                else
                    it = prev(it);
            }else if(s[i] == '>'){
                if(it == pwd.end())
                    continue;
                else
                    it = next(it);
            }else if(s[i]== '-'){
                if(it == pwd.begin())
                    continue;
                pwd.erase(prev(it));
            }else{
                //it = next(it);
                pwd.insert(it, s[i]);
            }
        }
        
        for(char c : pwd) cout << c ;
        cout << '\n';
    }
    
    return 0;
}
