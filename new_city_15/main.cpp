#include <iostream>
using namespace std;

struct _info{
	bool dir[4];
	bool visit;
	_info(){
		dir[0]=false;dir[1]=false;dir[2]=false;dir[3]=false;
		visit=false;
	}
};
int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int zero_cnt;
_info map[20][20];//지도 정보

void set_dir(int a,string c){
	for(int b=0;b<N;b++){
		switch(c[b]){
		case '0':
			zero_cnt++;
			break;
		case '1':
			map[a][b].dir[1]=true;
			map[a][b].dir[3]=true;
			break;
		case '2':
			map[a][b].dir[0]=true;
			map[a][b].dir[2]=true;
			break;
		case '3':
			map[a][b].dir[1]=true;
			map[a][b].dir[2]=true;
			break;
		case '4':
			map[a][b].dir[2]=true;
			map[a][b].dir[3]=true;
			break;
		case '5':
			map[a][b].dir[0]=true;
			map[a][b].dir[3]=true;
			break;
		case '6':
			map[a][b].dir[0]=true;
			map[a][b].dir[1]=true;
			break;
		case '7':
			map[a][b].dir[0]=true;
			map[a][b].dir[1]=true;
			map[a][b].dir[2]=true;
			break;
		case '8':
			map[a][b].dir[1]=true;
			map[a][b].dir[2]=true;
			map[a][b].dir[3]=true;
			break;
		case '9':
			map[a][b].dir[0]=true;
			map[a][b].dir[2]=true;
			map[a][b].dir[3]=true;
			break;
		case 'A':
			map[a][b].dir[0]=true;
			map[a][b].dir[1]=true;
			map[a][b].dir[3]=true;
			break;
		case 'B': 
			map[a][b].dir[0]=true;
			map[a][b].dir[1]=true;
			map[a][b].dir[2]=true;
			map[a][b].dir[3]=true;
			break;
		}
	}
}
void Input_Data(void){
	char str[20];
	zero_cnt = 0;
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		set_dir(i,str);
	}
}

// up = 0
// right = 1
// down = 2
// left = 3
void dfs(int a,int b){
	//printf("here is %d,%d-----------------------------------------\n",a,b);
	map[a][b].visit = true;
	if(!map[a][b].dir[0] && !map[a][b].dir[1] && !map[a][b].dir[2] && !map[a][b].dir[3]) map[a][b].visit = false;
	//printf("up:%d, right:%d, down:%d, left:%d\n",map[a][b].dir[0],map[a][b].dir[1],map[a][b].dir[2],map[a][b].dir[3]);
	// up
	if(a>0 && map[a][b].dir[0] && map[a-1][b].dir[2] && !map[a-1][b].visit){
		//printf("up from %d,%d\n",a,b);
		dfs(a-1,b); 
	}
	// right
	if(b<N-1 && map[a][b].dir[1] && map[a][b+1].dir[3] && !map[a][b+1].visit){
		//printf("right from %d,%d\n",a,b);
		dfs(a,b+1);
	}
	// down
	if(a<N-1 && map[a][b].dir[2] && map[a+1][b].dir[0] && !map[a+1][b].visit){
		//printf("down from %d,%d\n",a,b);
		dfs(a+1,b);
	}
	// left
	if(b>0 && map[a][b].dir[3] && map[a][b-1].dir[1] && !map[a][b-1].visit){
		//printf("left from %d,%d\n",a,b);
		dfs(a,b-1);
	}
	//printf("\n");
}

int main(){
	int ans = 0;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	dfs(X,Y);
	
	for(int i=0;i<N;i++){
		for(int ii=0;ii<N;ii++){
			if(map[i][ii].visit) ans++;
		}
	}
	
	cout << (N*N-ans-zero_cnt) << endl;	//	정답 출력
	return 0;
}
