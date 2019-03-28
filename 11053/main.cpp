//<done>
#include <iostream>

using namespace std;



int main(){
    int nums[1001]={0,};
    int cnt[1001]={0,};
    int N,tmp, largest=0;
    bool in=false;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        
        scanf("%d",&tmp);
        nums[i] = tmp;

        largest=0;
        for(int ii=tmp-1;ii>=0;ii--){
            if(largest<cnt[ii]){
                largest=cnt[ii];
            }
        }
        cnt[tmp]=largest+1;
    }

    largest=0;
    for(int i=0;i<1001;i++){
        largest<cnt[i]?largest=cnt[i]:largest;
    }

    printf("%d\n",largest);
}