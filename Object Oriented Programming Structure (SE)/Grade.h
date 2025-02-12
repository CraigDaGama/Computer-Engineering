//header file Grade.h
using namespace std;
namespace Grade.h

namespace prog {
    float percentage(int sub1, int sub2, int sub3, int sub4, int sub5, int sub6) {
        int sum = sub1 + sub2 + sub3 + sub4 + sub5 + sub6;
        return sum / 6.0;  
    }

    std::string grade(float percentage) { 
        if (percentage >= 85)
            return "O";
        else if (percentage >= 75)
            return "A+";
        else if (percentage >= 65)
            return "A";
        else if (percentage >= 55)
            return "B+";
        else if (percentage >= 50) 
            return "B";
        else if (percentage >= 40)
            return "C";
        else
            return "F";
    }
}

#endif
