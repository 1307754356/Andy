#include <iostream>
using namespace std;
int n[3][3];
void dao(int a[][3]);
int main() {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			cin >> n[i][j];
		}
	dao(n);
	cout<<"ת�ú�"<<endl;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << n[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
void dao(int a[][3]) {

	for(int i = 0; i < 3; i++)
		for(int j = i; j < 3; j++) {
			int temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}

}

/*
1 2 3
4 5 6
7 8 9


*/
