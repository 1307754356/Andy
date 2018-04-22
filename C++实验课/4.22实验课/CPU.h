#include<iostream>
using namespace std;
enum CPU_rank {P1 = 1, P2, P3, P4, P5, P6, P7};
class CPU {
public:
    CPU(CPU_rank myrank, int myfre, double myvoltage);
    ~CPU();
    CPU(CPU &c);
    CPU_rank getRank();
    void Run();
    void Stop();
    int getFre();
    double getVol();
    void change_rank(CPU_rank chg_rank);
    void change_frequency(int chg_fre);
    void change_voltage(double chg_vol);
private:
    CPU_rank rank;
    int frequency;
    double voltage;
};

void CPU::change_rank(CPU_rank chg_rank)
{
    rank=chg_rank;
}
void CPU::change_frequency(int chg_fre){
    frequency = chg_fre;
}
void CPU::change_voltage(double chg_vol){
    voltage = chg_vol;

}
CPU::CPU(CPU_rank myrank, int myfre, double myvoltage) {
    cout << "CPU Constructor" << endl;
    rank  = myrank;
    frequency = myfre;
    voltage = myvoltage;
}
CPU::CPU(CPU &c) {
    cout << "CPU Copy Constructor" << endl;
    rank = c.rank;
    frequency = c.frequency;
    voltage = c.voltage;
}
CPU::~CPU() {
    cout << "CPU Destructor" << endl;
   // cin.get();
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



