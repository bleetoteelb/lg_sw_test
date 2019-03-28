//<done>
#include <iostream>
#include <queue>

using namespace std;

struct qu{
    int pri;
    bool wanted;
    qu(int a, bool b) : pri(a), wanted(b){};
};

int main(){

    int cases,N,M;
    int tmp;
    
    cin >> cases;

    
    for(int i=0;i<cases;i++){
        cin >> M >> N;
        queue<qu> q;
        int priority[10]={0,}, largest=0, order=1;
        for(int ii=0;ii<M;ii++){
            cin >> tmp;
            priority[tmp]++;
            if(largest<tmp) largest=tmp;
            if(ii==N) q.push(qu(tmp,true));
            else q.push(qu(tmp,false));
        }

        while(!q.empty()){
            if(q.front().pri<largest) {
                q.push(q.front());
                q.pop();
            } else {
                priority[q.front().pri]--;
                if(priority[q.front().pri]==0){
                    for(int i=largest;i>0;i--){
                        if(priority[i]!=0) {
                            largest=i;
                            break;
                        }
                    }
                }
                if(q.front().wanted) {
                    printf("%d\n",order);
                    break;
                }
                q.pop();
                order++;
            }
        }
        
    }

}