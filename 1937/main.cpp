// <done>
#include <stdio.h>

struct _forest{
    int val,l;
    bool visit;
    _forest():val(1),l(1),visit(false){}
} forest[501][501];

int n;

void get_input(){
    int tmp=0;
    for(int i=0;i<n;i++){
        for(int ii=0;ii<n;ii++){
            scanf("%d",&tmp);
            forest[i][ii].val=tmp;
        }
    }
}

int find_l(int a, int b){
    int longest=1, result=0 ;
    if(a>0) {
        if(forest[a-1][b].val < forest[a][b].val){
            if(!forest[a-1][b].visit){
                result = find_l(a-1,b)+1;
                longest < result ? longest=result : longest;
            }else longest < forest[a-1][b].l+1 ? longest=forest[a-1][b].l+1 : longest;
        }
    }
    
    if(a<n-1) {
        if(forest[a+1][b].val < forest[a][b].val){
            if(!forest[a+1][b].visit){
                result = find_l(a+1,b)+1;
                longest < result ? longest=result : longest;
            }else longest < forest[a+1][b].l+1 ? longest=forest[a+1][b].l+1 : longest;
        }
    }
    
    if(b>0) {
        if(forest[a][b-1].val < forest[a][b].val){
            if(!forest[a][b-1].visit){
                result = find_l(a,b-1)+1;
                longest < result ? longest=result : longest;
            }else longest < forest[a][b-1].l+1 ? longest=forest[a][b-1].l+1 : longest;
        }
    }
    
    if(b<n-1) {
        if(forest[a][b+1].val < forest[a][b].val){
            if(!forest[a][b+1].visit){
                result = find_l(a,b+1)+1;
                longest < result ? longest=result : longest;
            }else longest < forest[a][b+1].l+1 ? longest=forest[a][b+1].l+1 : longest;
        }
    }

    forest[a][b].visit = true;
    forest[a][b].l = longest;
    return longest;
   
}

int main(){

    int k=0;
        
    scanf("%d",&n);
    get_input();

    for(int i=0;i<n;i++){
        for(int ii=0;ii<n;ii++){
            find_l(i,ii);
        }
    }

    for(int i=0;i<n;i++){
        for(int ii=0;ii<n;ii++){
            k=k<forest[i][ii].l?forest[i][ii].l:k;
        }
    }

    printf("%d\n",k);
    

}