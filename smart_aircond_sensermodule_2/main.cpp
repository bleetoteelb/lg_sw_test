#include <iostream>
using namespace std;

int N; //명령의 갯수
int exit_flag = 0; // Power OFF 대기 상태를 알려주는 변수 1이 Power OFF 대기상태임

// 들어온 명령을 리턴해 주는 함수
int Get_Command(void)
{
	int data;
	cin >> data;
	return data;
}

int main(void)
{
	int data, i;
	
	cin >> N;
	
	for(i=0; i<N; i++)
	{
		data = Get_Command();
		if(data !=6 )exit_flag = 0;
		switch(data)
		{
			case 1:
				cout << "Power ON" << endl;
				break;
			case 2:	
				cout << "Sensing Mode Init" << endl;
				cout << "Air Sensing Mode ON" << endl;
				break;
			case 3:	
				cout << "Sensing Mode Init" << endl;
				cout << "Humidity Sensing Mode ON" << endl;
				cout << "Air Sensing Mode ON" << endl;
				break;
			case 4:	
				cout << "Sensing Mode Init" << endl;
				cout << "Temp. Sensing Mode ON" << endl;
				cout << "Humidity Sensing Mode ON" << endl;
				cout << "Air Sensing Mode ON" << endl;
				break;		
			case 5:
				cout << "Wait Power OFF" << endl;
				exit_flag = 1;
				break;
			case 6:
				if(exit_flag ==1)
				{
					cout << "Power OFF" << endl;
					cout << "Finish" << endl;
					return 0;
				}
				else
				{
					cout << "No Operation" << endl;
					break;
				}
			case 9:
				cout << "Error Code " << data << endl;
				break;
			default:
				cout << "Unknown Error" << endl;
				cout << "Error Code " << data << endl;
				break;
			
				
		}
	}
	
	cout << "Finish" << endl;
	return 0;
}
