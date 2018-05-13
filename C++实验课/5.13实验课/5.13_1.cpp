#include<iostream>
using namespace std;
class Point {
public:
	Point(int myx,int myy);
	void ShowPoint();
	Point& operator ++();
	Point& operator --();
	Point operator ++(int);
	Point operator --(int);
private:
	int _x;
	int _y;

};
Point::Point(int myx,int myy) {
	_x=myx;
	_y=myy;
}
void Point::ShowPoint() {
	cout<<"("<<_x<<","<<_y<<")"<<endl;
}
Point& Point::operator ++() {
	_x++;
	_y++;
	return *this;
}
Point& Point::operator --() {
	_x--;
	_y--;
	return *this;
}
Point Point::operator ++(int) {
	Point temp = *this;
	_x++;
	_y++;
	return temp;
}
Point Point::operator --(int) {
	Point temp = *this;
	_x--;
	_y--;
	return temp;
}
int main() {
	Point a(1,2);
	a.ShowPoint();
	++a;
	a.ShowPoint();
	a++;
	a.ShowPoint();
	a--;
	a.ShowPoint();
	--a;
	a.ShowPoint();
	return 0;
}