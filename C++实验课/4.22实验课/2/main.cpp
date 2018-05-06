#include"CPU.h"
using namespace std;


//RAM
class RAM {
public:
    RAM(int mySize);
    ~RAM();
    RAM(RAM &r);
private:
    int Size;       //内存大小

};
RAM::RAM(int mySize) {        //构造函数
    cout << "RAM Constructor" << endl;
    Size = mySize;
}
RAM::~RAM() {                 //析构函数
    cout << "RAM Destructor" << endl;
}
RAM::RAM(RAM &r) {            //复制构造函数
    cout << "RAM Copy Constructor" << endl;
    Size = r.Size;
}

//CDROM
class CDROM {
public:
    CDROM(int my_size);  //构造函数
    ~CDROM();            //析构函数
    CDROM(CDROM & c);    //复制构造函数
private:
    int Size;            //光驱大小

};

CDROM::CDROM(int my_size) {
    cout << "CDROM Constructor" << endl;
    Size = my_size;
}
CDROM::CDROM(CDROM &c ) {
    cout << "CDROM Copy Constructor" << endl;
    Size = c.Size;

}
CDROM::~CDROM() {
    cout << "CDROM Destructor" << endl;

}




//Computer
class   Computer {
public:
    Computer(CPU_rank cpu_rank, int cpu_fre, double cpu_vol, int ram_size, int cd_size);
    Computer(Computer & c);
    ~Computer();
    void Run();            //公有成员函数RUN
    void Stop();           //公有成员函数STOP
private:
    CPU cpu;               //CPU
    RAM ram;               //RAM
    CDROM cdrom;           //CDROM
};

//构造函数，接受五个参数，前三个赋值CPU,后三个给RAM和CDROM
Computer::Computer(CPU_rank cpu_rank, int cpu_fre, double cpu_vol, int ram_size, int cd_size): cpu(cpu_rank, cpu_fre, cpu_vol), ram(ram_size), cdrom(cd_size) {
    cout << "Computer Constructor" << endl;
}
//复制构造
Computer::Computer(Computer &c): cpu(c.cpu), ram(c.ram), cdrom(c.cdrom) {
    cout << "Computer Copy Constructor" << endl;
}
//析构
Computer::~Computer() {
    cout << "Computer Destructor" << endl;
}
void Computer::Run() {

    cout << "Computer Run!" << endl;

}
void Computer::Stop() {
    cout << "Computer Stop!" << endl;
}
int main() {
    cout<<"Please enter the argument"<<endl;
    int m_cpu_rank, m_cpu_fre, m_cpu_vol, m_ram_size, m_cd_size;
    cin >> m_cpu_rank >> m_cpu_fre >> m_cpu_vol >> m_ram_size >> m_cd_size;
    Computer c1((CPU_rank)m_cpu_rank, m_cpu_fre, m_cpu_vol, m_ram_size, m_cd_size);
    Computer c2(c1);
    c1.Run();
    c1.Stop();
    return 0;
}
