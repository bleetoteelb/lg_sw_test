//<done>
#include <stdio.h>
#include <stack>
#include <string.h>


int main(){
    int N,ans=0;
    char trash[100001];
    std::stack<char> tmp;

    scanf("%d",&N);


    for(int i=0;i<N;i++){
        char t[100001];
        scanf("%s",&t);
        int length = strlen(t);

        for(int ii=0;ii<length;ii++){
            if(tmp.empty()) tmp.push(t[ii]);
            else if(tmp.top()==t[ii]){
                tmp.pop();
            }else{
                tmp.push(t[ii]);
            }
        }
        if(tmp.empty()) ans++;
        else{
            while(!tmp.empty()) tmp.pop();
        }
    }
    printf("%d",ans);
}