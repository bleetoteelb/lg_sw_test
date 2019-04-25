// <done>
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int N;//지도 크기
char _map[110][110];//지도 정보
int map[110][110];
int low_cost[110][110];
#define INF 10000000

struct map_info{
	int cost,x,y;
	map_info(int a,int b,int c):x(a),y(b),cost(c){}
};

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> _map[i];
		for(int ii=0;ii<N;ii++) {
			map[i][ii] = _map[i][ii]-'0';
			low_cost[i][ii] = INF;
		}
	}
}
struct compare{
	bool operator()(map_info a,map_info b){
		return a.cost > b.cost;
	}
};

int bfs(){
	priority_queue<map_info,vector<map_info>,compare> pq;
	map_info mi(0,0,0);
	int a,b,cost;
	pq.push(mi);
	while(1){
		a = pq.top().x;
		b = pq.top().y;
		cost = pq.top().cost;
		pq.pop();
		if(a==N-1 && b==N-1){
			return cost;
		}
		// right
		if(b < N-1 && cost+map[a][b+1] < low_cost[a][b+1]){
			low_cost[a][b+1] = cost+map[a][b+1];
			pq.push(map_info(a,b+1,cost+map[a][b+1]));
		}
		// down
		if(a < N-1 && cost+map[a+1][b] < low_cost[a+1][b]){
			low_cost[a+1][b] = cost+map[a+1][b];
			pq.push(map_info(a+1,b,cost+map[a+1][b]));
		}
		// left
		if(b > 0 && cost+map[a][b-1] < low_cost[a][b-1]){
			low_cost[a][b-1] = cost+map[a][b-1];
			pq.push(map_info(a,b-1,cost+map[a][b-1]));
		}
		// up
		if(a > 0 && cost+map[a-1][b] < low_cost[a-1][b]){
			low_cost[a-1][b] = cost+map[a-1][b];
			pq.push(map_info(a-1,b,cost+map[a-1][b]));
		}
	}
}

int main(){
	Input_Data();		//	입력 함수
	int ans = -1;
	//	코드를 작성하세요

	low_cost[0][0] = 0;
	ans = bfs();

	cout << ans << endl;	//	정답 출력
	return 0;
}
