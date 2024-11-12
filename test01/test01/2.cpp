//
//  2.cpp
//  test01
//
//  Created by 민오 on 9/18/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void user_solution2(int N, int K, int *arr){
    int MAX = arr[0];
    int i = 0;
    
    while(1){
        int sum = 0;
        for(int j=0;j<K;j++){
            sum += arr[i+j];
        }
        if(MAX < sum) MAX = sum;
        i++;
        if(i+K-1 == N) break;
        
    }
    printf("%d\n",MAX);
}

int solno(int N, int K, int *arr){
    int MAX = arr[0];
    int temp_index = 0;
    for(int i=1;i<N;i++){
        if(MAX < arr[i]){
            MAX = arr[i];
            temp_index = i;
        }
    }
    
    int temp_index2 = temp_index - K;
    int totalMAX=-999999;
    
    while(1){
        int sum = 0;
        temp_index2++;
        if(temp_index2 <0) continue;
        
        for(int i=0;i<K;i++){
            if(temp_index2 +i == N){
                return totalMAX;
            }
            sum += arr[temp_index2+i];
        }
        if(totalMAX < sum ) totalMAX = sum;
        
        if(temp_index2 == temp_index+K) break;
    }
    
    return totalMAX;
}

int main2(){
    int N, K;
    cin >> N >> K;
    int arr[N];
    
    for(int i=0;i<N;i++) cin >> arr[i];
    
    user_solution2(N,K, arr);
    printf("%d\n",solno(N,K,arr));
    
    return 0;
}
