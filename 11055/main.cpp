//<done>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int nums[1001]={0,};
    int sum[1001]={0,};
    int N,tmp, largest=0;
    bool in=false;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        
        scanf("%d",&tmp);
        nums[i] = tmp;

        largest=0;
        //printf("i: %d\n",i);
        for(int ii=i-1;ii>=0;ii--){
            //printf("ii:%d, nums[ii]:%d, nums[i]:%d, sum[ii]:%d, largest:%d\n",ii,nums[ii],nums[i],sum[ii],largest);
            if(nums[ii]<nums[i]){
                if(largest<sum[ii]){
                    largest=sum[ii];
                    //printf("%d ",ii);
                    //printf("%d\n",largest);
                }
            }
        }
        sum[i]=largest+nums[i];
    }

    largest=0;
    for(int i=0;i<N;i++){
        largest<sum[i]?largest=sum[i]:largest;
        //printf("%d ",sum[i]);
    }
   // printf("\n");
    printf("%d\n",largest);
}