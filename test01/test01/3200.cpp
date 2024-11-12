//
//  3200.cpp
//  test01
//
//  Created by 민오 on 9/17/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int user_solution(int N, int *arr){
    
    int sum;
    int fa,fb;
    int fsum = NULL;
    
    int i=0;
    int j=N-1;
    
    while(i<j){
        sum = arr[i] + arr[j];
        
        if(sum == 0){
            printf("%d %d\n",arr[i],arr[j]);
            break;
        }
        
        if(!fsum || fsum > abs(sum)){
            fsum = abs(sum);
            fa = arr[i];
            fb = arr[j];
        }
        
        if(sum <0) i++;
        else j--;
    }
    
    printf("%d %d\n",fa,fb);
    
    return 0;
}

struct AbsComp{
    bool operator()(const int&a, const int&b) const{
        return abs(a) < abs(b);
    }
};

void process(int N, int *arr){
    sort(arr,arr+N,AbsComp());
    
    int sum = arr[0]+arr[1];
    int ans = abs(sum);
    int ra = arr[0];
    int rb = arr[1];
    for(int i=2;i<N;i++){
        sum = arr[i-1]+arr[i];
        if(abs(sum)< ans){
            ans = abs(sum);
            ra = arr[i-1];
            rb = arr[i];
        }
        
        if(sum == 0) break;
    }
    if(ra>rb)
        swap(ra,rb);
    
    printf("%d %d\n",ra,rb);
}

int main3200(){
    int N;
    cin >> N;
    
    int arr[N];
    for(int i=0;i<N;i++)    cin >> arr[i];
    
//    user_solution(N,arr);
    process(N,arr);
    
    return 0;
}
