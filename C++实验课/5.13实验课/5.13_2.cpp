#include<iostream>
using namespace std;
class vehiele {
public:
	virtual void Run();
	virtual void Stop();
};
void vehiele::Run() {
	cout<<"vehiele Run!"<<endl;
}
void vehiele::Stop() {
	cout<<"vehiele Stop!"<<endl;
}

class bicycle : virtual public vehiele {
public:
	virtual void Run();
	virtual void Stop();
};
void bicycle::Run() {
	cout<<"bicycle Run!"<<endl;
}
void bicycle::Stop() {
	cout<<"bicycle Stop!"<<endl;
}

class motocar : virtual public vehiele {
public:
	virtual void Run();
	virtual void Stop();
};
void motocar::Run() {
	cout<<"motocar Run!"<<endl;
}
void motocar::Stop() {
	cout<<"motocar Stop!"<<endl;
}

class motorcycle : virtual public bicycle , virtual public motocar {
public:
	virtual void Run();
	virtual void Stop();
};
void motorcycle::Run() {
	cout<<"motorcycle Run!"<<endl;
}
void motorcycle::Stop() {
	cout<<"motorcycle Stop!"<<endl;
}
int main() {
	vehiele a;
	bicycle b;
	motocar c;
	motorcycle d;

	vehiele * p = &a;
	p->Run();
	p = &b;
	p->Run();
	p = &c;
	p->Run();
	p = &d;
	p->Run();
	return 0;
}


