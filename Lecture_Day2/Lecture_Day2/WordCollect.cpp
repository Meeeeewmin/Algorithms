//
//  WordCollect.cpp
//  Lecture_Day2
//
//  Created by 민오 on 11/13/24.
//

/*
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector<string> word;

int mainwordcollect(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    getline(cin, s);

    while(s != "END"){
        s += ' ';
        int start = 0;
        while(start < s.size()){
            int idx = s.find(' ',start);
            string st = s.substr(start, idx);
            
            word.push_back(st);
            start = idx +1;

        }
    }
    
    for(string sr:word) cout << sr << ' ';
    return 0;
}
*/
