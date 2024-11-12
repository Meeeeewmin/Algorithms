//
//  4523.cpp
//  test01
//
//  Created by 민오 on 9/16/24.
//

#include "4523.hpp"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main4523(){
    int N,s,e;
    cin >> N;
    
    int arr[N];
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    cin >> s;
    cin >> e;
    
     
//    int arr[8] = {1,9,9,4,1,1,0,8};

    sort(arr+s,arr+e+1);
    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    sort(arr,arr+8);

    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
