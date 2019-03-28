#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct bug{
	int x,y;
	bug(int a,int b):x(a),y(b){};
};

struct cmp{
	bool operator()(bug a, bug b){
		if(a.x>b.x){
			return true;
		}else return false;
	}
};

int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답
priority_queue< bug, vector<bug>, cmp> bug_pq;
vector<bug> bug_v;

// 작은게 먼저


void Input(void){
	int x,y;
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++)		{
		cin >> x >> y;
		bug_pq.push(bug(x,y));
	}
}

int main(void){
	
	Input();

	//	코드를 작성하세요
	int size = bug_pq.size();
	
	for(int i=0;i<size;i++){
		//printf("x:%d y:%d\n",bug_pq.top().x,bug_pq.top().y);
		bug_v.push_back(bug_pq.top());
		bug_pq.pop();
	}


	int width,height;
	int largest=0, bug_cnt=0;
	//printf("L: %d\n",L);
	for(int i=1;i<L/2;i++){
		width=i;
		height=L/2-i;
		//printf("width:%d, height:%d\n",width,height);
		for(int ii=1;ii<=N-width;ii++){
			for(int iii=1;iii<=N-height;iii++){
				bug_cnt=0;
				for(int iiii=0;iiii<size;iiii++){
					if(bug_v[iiii].x < ii) continue;
					else if(bug_v[iiii].x >ii+width) break; 
					if(bug_v[iiii].x >=ii && bug_v[iiii].x<=ii+width && bug_v[iiii].y>=iii && bug_v[iiii].y<=iii+height) {
						bug_cnt++;
						//printf("ii:%d, ii+width:%d, iii:%d, iii+height:%d, x:%d, y:%d\n",ii,ii+width,iii,iii+height,bug_v[iiii].x,bug_v[iiii].y);
					}
				}
				largest<bug_cnt?largest=bug_cnt:largest;
			}
		}
		
	}
	//	정답출력
	printf("%d", largest);

	return 0;
}