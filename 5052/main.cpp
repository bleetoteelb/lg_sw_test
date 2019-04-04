#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>

char num[11];

struct number{
    bool isLeaf;
    number* num_book[11];
    number(bool b):isLeaf(b){
        int i=11;
        while(i--) num_book[i] = NULL;
        //memset(num_book,0,sizeof(number));
        //if(num_book[0]==NULL) printf("what??????????\n");
    }
};

bool num_find(number *first){
    printf("find start\n");
    number cur = first;

    for(int i=0;num[i]!='\0';i++){
        printf("num[i]: %d\n",num[i]-'0');
        if(cur.isLeaf) {
            printf("leaf true\n");
            return true;
        }
        else{
            //printf("not leaf\n");
            if(cur.num_book[num[i]-'0'] == NULL){
                printf("null true\n");
                return false;
            }
            cur = cur.num_book[num[i]-'0'];
        }

    }
    printf("end true\n");
    return true;

}

void num_insert(number *first){
    printf("insert start\n");
    number cur = first;

    for(int i=0;num[i]!='\0';i++){
        printf("num[i]: %d\n",num[i]-'0');
        if(cur.num_book[num[i]-'0'] == NULL){
            cur.num_book[num[i]-'0'] = new number(true);
            if(cur.num_book[num[i]-'0'] != NULL) printf("not null\n");
            cur.isLeaf = false;
        }
        printf("go next\n");
        cur = cur.num_book[num[i]-'0'];
    }

    return;
}

int main(){

    int t,n;
    int kkk;
    bool result;
    scanf("%d",&t);
    //std::cin >> t;
    //printf("start %d!\n",t);
    

    for(int i=0;i<t;i++){
        result = true;
        scanf("%d",&n);
        number* first = new number(false);
        //printf("start %d!\n",n);
            
        for(int ii=0;ii<n;ii++){
            scanf("%s",num);
            //printf("start2!\n");
            if(num_find(first)) { printf("NO\n"); result= false; break; }
            else { num_insert(first); }
            //for(int iii=0;num[iii]!='\0';iii++) printf("%d",num[iii]-'0');
            //printf("\n");
        }
        if(result) printf("YES\n");
    }
    
}