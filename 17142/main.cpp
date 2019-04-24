// <done>
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
_sg sg[10];
_sg selected_sg[10];
int N,M,wall=0, sg_cnt=0;
int shortest = 10000;

void dfs(){
	queue<_sg_q> sg_q;
	int load[51][51];
	int cnt = 0, large = 0;
	int x, y, step;

	for(int i=0;i<N;i++){
		for(int ii=0;ii<N;ii++){
			load[i][ii] = 10000;
		}
	}

	for(int i=0;i<M;i++){
		sg_q.push(_sg_q(selected_sg[i].x,selected_sg[i].y,0));
		load[selected_sg[i].x][selected_sg[i].y] = 0;
	}
	while(1){
		if(sg_q.empty()){
			if(cnt+M==N*N-wall) shortest = large < shortest ? large : shortest;
			break;
		}

		x = sg_q.front().x;
		y = sg_q.front().y;
		step = sg_q.front().step;

		if(lab[x][y] != 2) large = step > large ? step : large;
		
		
		// up
		if(x>0 && lab[x-1][y] != 1 && load[x-1][y] > step+1) {
			sg_q.push(_sg_q(x-1,y,step+1));
			load[x-1][y] = step+1;
			cnt++;
		}
		// down
		if(x<N-1 && lab[x+1][y] != 1 && load[x+1][y] > step+1) {
			sg_q.push(_sg_q(x+1,y,step+1));
			load[x+1][y] = step+1;
			cnt++;
		}

		// left
		if(y>0 && lab[x][y-1] != 1 && load[x][y-1] > step+1){
			sg_q.push(_sg_q(x,y-1,step+1));
			load[x][y-1] = step+1;
			cnt++;
		}
		// right
		if(y<N-1 && lab[x][y+1] != 1 && load[x][y+1] > step+1){
			sg_q.push(_sg_q(x,y+1,step+1));
			load[x][y+1] = step+1;
			cnt++;
		}

		sg_q.pop();
	}
}
void get_sg(int depth,int idx){
	if(depth<M){
		for(int i=idx+1;i<sg_cnt;i++){
			selected_sg[depth].setting(sg[i].x,sg[i].y);
			get_sg(depth+1,i);
		}
	}else{
		dfs();
	}
}

int main(){
    scanf("%d %d",&N,&M);
	int tmp;
    for(int i=0;i<N;i++){
        for(int ii=0;ii<N;ii++){
			scanf("%d",&tmp);
			lab[i][ii] = tmp;
			if(lab[i][ii]==2) sg[sg_cnt++].setting(i,ii);
			else if(lab[i][ii]==1) wall++;
		}
    }
	get_sg(0,-1);
	printf("%d\n",shortest==10000?-1:shortest);
}
