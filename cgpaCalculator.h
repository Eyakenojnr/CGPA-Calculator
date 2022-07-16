#ifndef CGPACALCULATOR_H
#define CGPACALCULATOR_H

#include <string>
#include <conio.h>
#include <iostream>
#define MAX_VAL 9

class University{
    private:
        int A_grade, B_grade, C_grade, D_grade, E_grade;
        double total_unit{};
        double total_MGpoint{};
        double gpa{};
        double cgpa{};
        int unit[MAX_VAL]{};
        int score[MAX_VAL]{};
        int MGpoint[MAX_VAL]{};
    public:
        University(){
            A_grade = 70;
            B_grade = 60;
            C_grade = 50;
            D_grade = 45;
            E_grade = 40;
        }
        void set_grade();
        void GPA();
        void clear_buffer();
        void CGPA();
        void getdata();
        int grade(int p[]);
        int nCourses{};
};

#endif
