#include <iostream>
using namespace std;

void dao(int **a);
int main() {
    int **n = new int*[3];
    for(int i = 0; i < 3; i++)
        n[i] = new int[3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            cin >> n[i][j];
        }
    dao(n);
    cout << "×ªÖÃºó" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
	for(int i=0;i<3;++i)
	delete [] n[i];
    return 0;
}
void dao(int **a) {

    for(int i = 0; i < 3; i++)
        for(int j = i; j < 3; j++) {
            int temp = *(*(a+i)+j);
            *(*(a+i)+j)=*(*(a+j)+i);
            *(*(a+j)+i) = temp;
        }
}

/*
1 2 3
4 5 6
7 8 9


*/
