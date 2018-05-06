#include<iostream>
using namespace std;
enum CPU_rank {P1 = 1, P2, P3, P4, P5, P6, P7};//ö�����ͣ���1��7
class CPU {
public:
	CPU(CPU_rank myrank, int myfre, double myvoltage);//���캯��
	~CPU();//��������
	CPU(CPU &c);//���ƹ��캯��
	CPU_rank getRank();//��ȡRank
	void Run();//Run!
	void Stop();//Stop!
	int getFre();//��ȡƵ��
	double getVol();//��ȡvoltage
private:
	CPU_rank rank;
	int frequency;
	double voltage;
};
CPU::CPU(CPU_rank myrank, int myfre, double myvoltage) {
	cout << "Constructor" << endl;
	rank  = myrank;
	frequency = myfre;
	voltage = myvoltage;
}
CPU::CPU(CPU &c) {
	cout << "Copy Constructor" << endl;
	rank = c.rank;
	frequency = c.frequency;
	voltage = c.voltage;
}
CPU::~CPU() {
	cout << "Destructor" << endl;
	cin.get();
}
CPU_rank CPU::getRank() {
	return   rank;
}
void CPU::Run() {
	cout << "CPU is Runing!" << endl;
};
void CPU::Stop() {
	cout << "CPU  stop!" << endl;
}
int CPU::getFre() {
	return frequency;
}
double CPU::getVol() {
	return voltage;
}
int main() {
	int my_rank;
	int my_fre;
	double my_vol;
	cout << "Please input the CPU data: rank,frequency,voltage " << endl;//����CPU��ֵ
	cin >> my_rank >> my_fre >> my_vol;
	if(my_rank > 0 && my_rank <= 7) {//�ж������Ƿ�Ϸ�
		CPU CPU1((CPU_rank)my_rank, my_fre, my_vol);
		CPU CPU2(CPU1);//����
		CPU2.Run();//RUN
		CPU2.Stop();//STOP
	} else {
		cout << "Please inter the right data!" << endl;
	}
	return 0;
}
