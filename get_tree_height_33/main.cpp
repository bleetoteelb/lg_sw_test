// <done>
#include <iostream>
#include <stdio.h>

using namespace std;

bool p2c[1001];
int c2p[1001];

int V, E; // 점의 갯수, 선의 갯수

void Input_Data(){
	int parent, child;
	cin >> V >> E;
	for(int i=0;i<1001;i++) {
		c2p[i] = -1;
		p2c[i] = false;
	}

	for(int i=0;i<E;i++){
		scanf("%d %d",&parent,&child);
		c2p[child] = parent;
		if(!p2c[parent]) p2c[parent] = true;
	}

}

int main() {
	int biggest = -1, smallest = 10000;
	int height = 0, child, parent;
	Input_Data();

	for(int i=0;i<V;i++){
		height = 0;
		if(p2c[i]) continue;
		
		child = c2p[i];
		while(1){
			if(child!=-1){
				height++;
				child = c2p[child];
			}else{
				break;
			}
		}
		height > biggest ? biggest = height : biggest;
		height < smallest ? smallest = height : smallest;
	}
	printf("%d",biggest-smallest);
	return 0;
}
