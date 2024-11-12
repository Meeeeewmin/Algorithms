//
//  main.cpp
//  test01
//
//  Created by 민오 on 9/10/24.
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   
//    vector<int> flag;
//    string runner;
////    int k = 0;
//    
//    for(int i = 0; i<completion.size(); i++)
//        flag.push_back(0);
//    
//    for(int i = 0; i < participant.size(); i++){
////        cout << participant[i] << endl;
//        runner = participant[i];
//        
//        for(int j = 0; j<completion.size(); j++){
//            if(runner == completion[j]){
//                if(flag[j] == 0){
//                    flag[j] = 1;
//                    break;
//                }
//            }
//            
//            if(j+1 == completion.size())
//                return runner;
//        }
//    }
//    
//    
    string answer = "something wrong";
    
    unordered_map<string, int> strMap;
    for (auto x: completion){
        if(strMap.end() == strMap.find(x)) strMap.insert(make_pair(x,1));
        else strMap[x]++;
    }
    
    for (auto x: participant){
        if(strMap.end() == strMap.find(x)) return x;
        else{
            strMap[x]--;
            if(strMap[x] == 0) return x;
        }
    }
    
    return answer;
}


int mainm(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> participant;
    participant.push_back("mislav");
    participant.push_back("stanko");
    participant.push_back("mislav");
    participant.push_back("ana");
    
    vector<string> completion;
    completion.push_back("stanko");
    completion.push_back("ana");
    completion.push_back("mislav");
    clock_t time = clock();
    
    int arr[8] = {1,9,9,4,1,1,0,8};

    sort(arr,arr+8);

    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
    }

    
    std::cout << solution(participant, completion) << endl;
    
    printf("%s %0.4f s\n",__FUNCTION__,(float)(clock()-time)/CLOCKS_PER_SEC);
    return 0;
}


