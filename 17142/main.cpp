#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct _sg{
	int x, y;
	_sg():x(-1),y(-1){}
	void setting(int a,int b){x=a;y=b;}
};
struct _sg_q{
	int x, y, step;
	_sg_q(int a,int b, int c):x(a),y(b),step(c){}
};
int lab[51][51];
int load[51][51];
_sg sg[10];
_sg selected_sg[10];
int N,M,wall=0;
int shortest = -1;
void dfs(){
	queue<_sg_q> sg_q;
	int sg_cnt=0;
	for(int i=0;i<M;i++){
		sg_q.push(selected_sg[i].x,selected_sg[i].y,0);
	}
	while(1){
		if(sg_q.empty()){
			if(sg_cnt==N*N-wall) 
		}
	}
}
void get_sg(int depth,int idx){
	if(depth<M){
		for(int i=idx+1;i<M;i++){
			selected_sg[depth].setting(sg[i].x,sg[i].y);
			get_sg(depth+1,i);
		}
	}else{
		get_load();
	}
}

int main(){
    scanf("%d %d",&N,&M);
	int sg_cnt=0;
    for(int i=0;i<N;i++){
        for(int ii=0;ii<N;ii++){
			scanf("%d",lab[i][ii]);
			if(lab[i][ii]==2) sg[sg_cnt].setting(i,ii);
			else if(lab[i][ii]==1) wall++;
		}
    }
	get_sg(0,-1);
}
