#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* pre_node,*next_node;
    Node(){ value=1; pre_node=NULL,next_node=NULL; }
};

Node* A_after_B(Node* a, Node* b,Node* s){
    if(a->pre_node==NULL){
        a->next_node->pre_node = NULL;
        s = a->next_node;
    }else if(a->next_node==NULL){
        a->pre_node->next_node = NULL;
    }else{
        a->next_node->pre_node = a->pre_node;
        a->pre_node->next_node = a->next_node;
    }

    if(b->next_node==NULL){
        b->next_node = a;
        a->pre_node = b;
    }else{
        b->next_node->pre_node = a;
        a->next_node = b->next_node;
        b->next_node = a;
        a->pre_node = b;
    }

    return s;
}

Node* A_before_B(Node* a, Node* b,Node* s){
    if(a->pre_node==NULL){
        a->next_node->pre_node = NULL;
        s = a->next_node;
    }else if(a->next_node==NULL){
        a->pre_node->next_node = NULL;
    }else{
        a->next_node->pre_node = a->pre_node;
        a->pre_node->next_node = a->next_node;
    }

    a->pre_node = NULL;
    a->next_node = NULL;

    if(b->pre_node==NULL){
        b->pre_node = a;
        a->next_node = b;
    }else{
        b->pre_node->next_node = a;
        a->pre_node = b->pre_node;
        b->pre_node = a;
        a->next_node = b;
    }
    return s;
}

int main(){

    int node_cnt,cmd_cnt;
    int a, b;
    char input_c;

    cin >> node_cnt >> cmd_cnt;

    Node* first_node;
    Node* cur = first_node;
    for(int i=1;i<node_cnt;i++){
        Node* tmp;
        tmp->value = i+1;
        cur->next_node = tmp;
        tmp->pre_node = cur;
        cur = tmp;
    }



    for(int i=0;i<cmd_cnt;i++){
        cin >> input_c >> a >> b;
        Node* A, *B;
        cur = first_node;
        int stop_cnt=2;
        while(stop_cnt!=0 && cur->next_node!=NULL){
            if(cur->value==a) {
                A=cur;
                stop_cnt--;
            }else if(cur->value==b){
                B=cur;
                stop_cnt--;
            }
            cur = cur->next_node;
        }
        if(input_c=='A'){
            first_node = A_before_B(A,B,first_node);
        }else{
            first_node =A_after_B(A,B,first_node);
        }
    }

    cur = first_node;
    for(int i=0;i<node_cnt-1;i++){
        //if(cur->v)
    }
}