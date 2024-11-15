#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Q;
int pid, salary, C, J, P;
int flag, X;

struct Developer{
    int pid, salary, C, J, P, sum;
};

vector<Developer> dev;

void regist(){
    cin >> pid >> salary >> C >> J >> P;
    dev.push_back({pid, salary, C, J, P, C+J+P});
}
void cancel(){
    cin >> pid;
    for(auto i = dev.begin(); i!=dev.end();++i){
        if((*i).pid == pid){
            dev.erase(i);
            return;
        }
    }
}
void update(){
    cin >> pid >> flag >> X;
    for(auto i = dev.begin(); i!=dev.end();++i){
        if((*i).pid == pid){
            if(flag == 0) (*i).C = X;
            if(flag == 1) (*i).J = X;
            if(flag == 2) (*i).P = X;
            i->sum = i->C + i->J + i->P;
            return;
        }
    }
}
struct Comp{
    bool operator()(const Developer& a, const Developer& b) const{
        if(a.sum != b.sum) return a.sum > b.sum;
        return a.pid > b.pid;
    }
};

void hire_min(){
    auto itr = dev.begin();
    int min = itr->salary;
    for(auto it = dev.begin()+1; it != dev.end(); it++){
        if(it->salary ==  min){
            if(itr->pid > it->pid)
                itr = it;
        }
        if(it->salary < min){
            min = it->salary;
            itr = it;
        }
    }
    
//    sort(dev.begin(),dev.end(),CompSal());
    cout << itr->pid << '\n';
    
    dev.erase(itr);
}

void hire_max(){
    partial_sort(dev.begin(), dev.begin()+3, dev.end(), Comp());
    for(int i=0;i<3;i++)
        cout << dev[i].pid << ' ';
    dev.erase(dev.begin(), dev.begin()+3);
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    
    string s;
    while(Q--){
        cin >> s;
        if(s[0]=='r') regist();
        if(s[0]=='c') cancel();
        if(s[0]=='u') update();
        if(s=="hire_min") hire_min();
        if(s=="hire_max") hire_max();
    }
    return 0;
}
