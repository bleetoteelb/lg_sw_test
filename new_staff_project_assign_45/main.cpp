// <done>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_PROJECT (15) 
typedef struct{
	int start_date; // 시작일
	int end_date; // 종료일
}DATA;

int     N; // 프로젝트 수
DATA    project_info[MAX_PROJECT]; // 프로젝트 정보
int pnum[301];

bool cmp(const DATA &a, const DATA &b){
	return a.end_date < b.end_date;
}

void Data_Input(void) {
	cin >> N; // 프로젝트 수 입력
	// 프로젝트 정보 입력
	for (int i = 0; i<N; i++) {
		cin >> project_info[i].start_date >> project_info[i].end_date;
		pnum[i] = 0;
	}
	sort(project_info,project_info+N,cmp);
}

int main(void) {
	int sol = 0;
	Data_Input(); // 입력 함수 실행 

	int pj_cnt=0, i=1;
	while(i <= 300){
		pnum[i] = max(pnum[i],pnum[i-1]);
		if(i==project_info[pj_cnt].end_date){
			pnum[i] = max(pnum[project_info[pj_cnt].start_date-1]+1,pnum[i]);
			pj_cnt++;
		}else i++;
		
		sol = max(sol,pnum[i]);
	}

	cout << sol << endl; // 결과 출력
	return 0;
}