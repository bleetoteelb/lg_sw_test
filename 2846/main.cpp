//<done>
#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int start = 0, before = 0, largest = 0;
    int input;

    cin >> start;
    before = start;
    for(int i=1;i<N;i++){
        cin >> input;
        if(input<=before){
            largest < before-start ? largest = before-start : largest;
            start = before = input;
        }else {
            before = input;
        }
    }
    largest < before-start ? largest = before-start : largest;

    cout << largest;
}