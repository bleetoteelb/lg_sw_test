#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct reg{
    deque<int> dq;
    reg(){ for(int i=0;i<32;i++) dq.push_back(-1); }
    void cmd1(int m){
        if(m<16){
                for(int s=0;s<m;s++){
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }else{
                for(int s=0;s<32-m;s++){
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
    }
};

int xor_cal(reg &a, reg &b, int result){
    int twobit[32] = {0,};
    int squre[32] = {0,};
    int result_ = result;
	for(int i=0;i<32;i++){
        if(result_==0) break;
        twobit[31-i] = result_%2;

        result_/=2;
    }

    squre[31] = 1;
    for(int i=1;i<32;i++) {
        squre[31-i] = squre[32-i]*2;
    }
}

int main(){

    int N,E;
    vector<reg> dqs;
    int cmd, K, ML;
    scanf("%d %d",&N,&E);
    for(int i=0;i<E;i++){
        for(int i=0;i<N;i++) dqs.push_back(reg());
        scanf("%d %d %d",&cmd,&K,&ML);
        if(cmd==1){
            dqs[K].cmd1(ML);
        }else{
            
        }
    }

}