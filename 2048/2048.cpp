#include<iostream>
#include<cstdio>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<conio.h>
#include<time.h>
#include<Windows.h>
using namespace std;
class pic {
public:
	pic();
	void pic_print();
	void pic_setnum(int,int,int);
	void pic_product();
	bool flag_get();
	void flag_check();
	void pic_move();
	int  number_max_get();
	void move_left();
	void move_right();
	void move_up();
	void move_down();
private:
	int number[4][4];
	bool flag;
	int num_max;
};
bool book[5];
/*
2 2 2 2
0 0 0 0
0 0 0 0
0 0 0 0

*/
int main() {

	 pic m;
	while(m.flag_get()) {
		m.pic_product();
		m.pic_print();
		m.pic_move();
		m.flag_check();
	}
	if(m.number_max_get()==2048) {
		m.pic_print();
		cout<<"You Win!"<<endl;
	} else
		cout<<"Game over"<<endl;
	return 0;
}




//构造函数
pic::pic() {
	memset(number,0,16*sizeof(int ));
	flag = 1;
	num_max = 2;
}
void pic::pic_product() {
	int ran_cnt=0;
	int ranx,rany;
	int ran_flag=0;
	int ran_over=1;
	srand((unsigned)time(NULL));
	do {
		ranx=rand()%4;
		rany=rand()%4;
		ran_cnt++;
		if(ran_cnt>64 && ran_flag==0) {
			for(int i=0; i<4; i++) {
				for(int j=0; j<4; j++) {
					if(number[i][j]==0) {
						ran_flag=1;
						break;
					}
				}
			}
			if(ran_flag)
				continue;
			else
			{
				ran_over=0;
				break;
			}
		}
	} while(number[ranx][rany]!=0);
	if(ran_over==0)
		flag=0;
	else {
		int ran_number=rand()%3;
		if(ran_number%2)
			ran_number=4;
		else
			ran_number=2;
		pic_setnum(ranx,rany,ran_number);
	}
}
void pic::flag_check() {
	if(num_max >= 2048)
		flag = 0;
}
bool pic::flag_get() {
	return flag;
}
//移动函数（核心）
void pic::pic_move() {
	char ch;
	ch=getch();
	switch(ch) {
	case 'W':
	case 'w':
		move_up();
		break;

	case 'A':
	case 'a':
		move_left();
		break;

	case 'S':
	case 's':
		move_down();
		break;

	case 'D':
	case 'd':
		move_right();
		break;
	case 'Q':
	case 'q':
		flag=0;
		break;
	}

}
int  pic::number_max_get() {
	return num_max;
}
//打印函数
void pic::pic_print() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			cout<<'|';
			cout<<setfill(' ')<<setw(5);
			if(number[i][j])
				cout<<number[i][j];
			else
				cout<<' ';
		}
		cout<<'|'<<endl;
		cout << "-------------------------" << endl;
	}

}
//操作字符函数
void pic::pic_setnum(int x,int y,int num) {
	if(x<0||x>=4||y<0||y>=4) {
		cout<<"ERROR!!!"<<endl;
		return ;
	}
	number[x][y]=num;
}

//左移
// 0 1 2 3
void pic::move_left() {
	for(int i=0; i<4; i++) {
		memset(book,0,5*sizeof(bool));
		int cnt=0;
		for(int j=0; j<4; j++) {
			if(number[i][j]) {
				number[i][cnt]=number[i][j];
				cnt++;
			}
		}
		while(cnt<4) {
			number[i][cnt]=0;
			cnt++;
		}
		for(int j=0; j<3; j++) {
			if(!book[j] && number[i][j] == number[i][j+1]) {
				number[i][j] += number[i][j+1];
				number[i][j+1] = 0;
				book[j]=1;
				book[j+1]=1;
				if(number[i][j]>num_max)
					num_max=number[i][j];
			}
		}
		cnt=0;
		for(int j=0; j<4; j++) {
			if(number[i][j]) {
				number[i][cnt]=number[i][j];
				cnt++;
			}
		}
		while(cnt<4) {
			number[i][cnt]=0;
			cnt++;
		}
	}
}
//右移
void pic::move_right() {
	for(int i=0; i<4; i++) {
		int cnt=3;
		for(int j=3; j>=0; j--) {
			if(number[i][j]) {
				number[i][cnt]=number[i][j];
				cnt--;
			}
		}
		while(cnt>=0) {
			number[i][cnt]=0;
			cnt--;
		}
		memset(book,0,5*sizeof(bool));
		for(int j=3; j>0; j--) {
			if(!book[j] && number[i][j] == number[i][j-1]) {
				number[i][j] += number[i][j-1];
				number[i][j-1] = 0;
				book[j]=1;
				book[j-1]=1;
				if(number[i][j]>num_max)
					num_max=number[i][j];

			}
		}
		cnt=3;
		for(int j=3; j>=0; j--) {
			if(number[i][j]) {
				number[i][cnt]=number[i][j];
				cnt--;
			}
		}
		while(cnt>=0) {
			number[i][cnt]=0;
			cnt--;
		}
	}
}
//上移
void pic::move_up() {
	for(int j=0; j<4; j++) {
		int cnt=0;
		for(int i=0; i<4; i++) {
			if(number[i][j]) {
				number[cnt][j]=number[i][j];
				cnt++;
			}
		}
		while(cnt<4) {
			number[cnt][j]=0;
			cnt++;
		}
		memset(book,0,5*sizeof(bool));
		for(int i=0; i<3; i++) {
			if(!book[i] && number[i][j] == number[i+1][j]) {
				number[i][j] += number[i+1][j];
				number[i+1][j] = 0;
				book[i]=1;
				book[i+1]=1;
				if(number[i][j]>num_max)
					num_max=number[i][j];
			}
		}
		cnt=0;
		for(int i=0; i<4; i++) {
			if(number[i][j]) {
				number[cnt][j]=number[i][j];
				cnt++;
			}
		}
		while(cnt<4) {
			number[cnt][j]=0;
			cnt++;
		}
	}
}
//下移
void pic::move_down() {
	for(int j=0; j<4; j++) {
		int cnt=3;
		for(int i=3; i>=0; i--) {
			if(number[i][j]) {
				number[cnt][j]=number[i][j];
				cnt--;
			}
		}
		while(cnt>=0) {
			number[cnt][j]=0;
			cnt--;
		}

		memset(book,0,5*sizeof(bool));
		for(int i=3; i>0; i--) {
			if(!book[i] && number[i][j] == number[i-1][j]) {
				number[i][j] += number[i-1][j];
				number[i-1][j] = 0;
				book[i]=1;
				book[i-1]=1;
				if(number[i][j]>num_max)
					num_max=number[i][j];
			}
		}
		cnt=3;
		for(int i=3; i>=0; i--) {
			if(number[i][j]) {
				number[cnt][j]=number[i][j];
				cnt--;
			}
		}
		while(cnt>=0) {
			number[cnt][j]=0;
			cnt--;
		}
	}
}