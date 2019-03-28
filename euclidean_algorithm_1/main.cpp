//<done>
#include <iostream>

using namespace std;

int GCD(int m, int n);

// 작성해야 할 함수
int GCD(int m, int n)
{
    if(m%n==0) return n;
    else {
        int tmp=0;
        tmp = m%n;
        m = n;
        n = tmp;
        return GCD(m,n);
    }
}

int main(void)
{
	int m, n, r;
	
	// 입력 받는 부분
	cin >> m >> n;
	
    if(n==0) {
        cout << m;
        return 0;
    }
	// 큰수를 변수 m에 대입
	if (m < n)
	{
		r = m; m = n; n = r;
	}

	r = GCD(m,n);

	cout << r;
    return 0;
}