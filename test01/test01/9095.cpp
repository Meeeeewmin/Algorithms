//
//  9095.cpp
//  test01
//
//  Created by 민오 on 10/16/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int sum(int n){
    if(n == 1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    
    return sum(n-1)+sum(n-2)+sum(n-3);
}

int main9095(){
    int T;
    cin >> T;
    
    while(T--){
        int temp;
        cin >> temp;
        
        cout << sum(temp) << endl;
    }
    return 0;
}
