//header file payslip.h
#include<string>
using namespace std;
namespace payslip
{
    class employee
    {
        int pay;
        string name;
        public:
        void setpay(int r) {pay=r;}
        void setname(string s) {name=s;}
        string getname() {return name;}
        int getpay() {return pay;}
    };
}
