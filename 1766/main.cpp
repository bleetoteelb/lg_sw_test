
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct qu{
    int pro_num, pri;
    bool done;
    vector<int> before_this, after_this;
    qu(int a):pro_num(a),pri(0),done(false){};
};

vector<qu> problems;

void add_pri(int c,int e){
    int size = problems[c].after_this.size();
    if (size!=0) printf("this is %d, after this is %d\n",c,problems[c].after_this[0]);
    else printf("this is %d\n",c);
    for(int i=0;i<size;i++){
        problems[problems[c].after_this[i]].pri = e+1;
        add_pri(problems[c].after_this[i],e+1);
    }
}

void make_pri(int A,int B){
    problems[A].after_this.push_back(B);
    problems[B].before_this.push_back(A);
    problems[B].pri++;
    add_pri(B,problems[B].pri);
}

void sub_pri(int c){
    int size = problems[c].after_this.size();
    for(int i=0;i<size;i++){
        problems[problems[c].after_this[i]].pri--;
        sub_pri(problems[c].after_this[i]);
    }
}

int main(){

    int N,M, finish;
    int A,B; // a is first b is after;
    
    
    scanf("%d %d",&N,&M);
    finish = N;
    problems.push_back(qu(0));
    problems[0].done=true;
    
    for(int i=1;i<N+1;i++){
        problems.push_back(qu(i));
    }
    
    for(int i=0;i<M;i++){
        scanf("%d %d",&A,&B);
        make_pri(A,B);
        for(int i=1;i<N+1;i++){
            printf("num: %d, pri: %d\n",problems[i].pro_num,problems[i].pri);
        }
        printf("\n");
    }

    for(int i=1;i<N+1;i++){
        printf("num: %d, pri: %d\n",problems[i].pro_num,problems[i].pri);
    }
/*
    while(finish!=0){
        for(int i=0;i<N;i++){
            if(!problems[i].done && problems[i].pri==0){
                finish--;
                printf("%d ",problems[i].pro_num);
                problems[i].done=true;
                if(problems[i].after_this.empty()) continue;
                else sub_pri(i);
            }
        }
    }
*/
}