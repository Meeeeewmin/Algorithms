#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int Q;
unordered_map<string, pair<int,int>> word;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    

    
    cin >> Q;
    string s; int score;
    int id =1;
    while(Q--){
        cin >> s >> score;
        
        for(int i=0; s[i];i++)
            s[i] = tolower(s[i]);
        
        if(!word.count(s))
            word.insert({s,{score,id++}});
        else{
            if(word[s].first < score)
                word[s].first = score;
        }
        cout << word[s].second << ' ' << word[s].first << '\n';
    }
        
    return 0;
}
