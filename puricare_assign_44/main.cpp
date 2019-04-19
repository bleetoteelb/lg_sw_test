// <done>
#include <iostream>
#include <vector>
using namespace std;

int H;		// 세로 크기
int W;		// 가로 크기


struct ANS{
	int count;	// room 개수
	int area;		// 가장 넓은 room 넓이
};

struct _info{
	int val;
	bool visit;
	_info():val(0),visit(false){}
};

_info map_info[50][50];

void InputData(){
	int i, j;
	cin >> H;
	cin >> W;
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			cin >> map_info[i][j].val;
		}
	}
}
int scan(int r, int c){
	int sum=1;
	map_info[r][c].visit = true;

	// west
	if(c>0 && (map_info[r][c].val & 1)==0 && !map_info[r][c-1].visit) sum+= scan(r,c-1); 
	// east
	if(c<W-1 && (map_info[r][c].val & 4)==0 && !map_info[r][c+1].visit) sum+= scan(r,c+1);
	// north
	if(r>0 && (map_info[r][c].val & 2)==0 && !map_info[r-1][c].visit) sum+= scan(r-1,c);
	// south
	if(r<H-1 && (map_info[r][c].val & 8)==0 && !map_info[r+1][c].visit) sum+= scan(r+1,c);
	return sum;
}

int main(){
	ANS ans = {0, 0};

	InputData();			//	입력 함수
	vector<int> cnt;
	//	코드를 작성하세요
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(!map_info[i][j].visit){
				cnt.push_back(scan(i,j));
			}
		}
	}

	int size=cnt.size();
	for(int i=0;i<size;i++) ans.area = ans.area < cnt[i] ? cnt[i] : ans.area;
	ans.count = cnt.size();
	
	cout << ans.count << endl;	//	정답 출력
	cout << ans.area << endl;		//	정답 출력
	return 0;
}
