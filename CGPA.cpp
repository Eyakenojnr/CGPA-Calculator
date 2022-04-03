#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

class University{
    private:
        double total_unit = 0;
        double total_MGpoint = 0;
        double gpa = 0;
        double cgpa = 0;
        int unit[3] = {0, 0, 0};
        int score[3] = {0, 0, 0};
        int MGpoint[3] = {0, 0, 0};
        string Ccode[3];
    public:
        int nCourses = 0; 
        void GPA();
        void CGPA();
        void getdata();
        int grade(int p[]);
};

void University::getdata(){
// METHOD TO GET DATA FROM USER
    cout<<"Number of Courses registered:";
    cin>>nCourses;
    cout<<"...Fill In Your Data..."<<endl;
    for(int q=0; q<nCourses; q++){
        cout<<"Course Code: ";
        cin>>Ccode[q];
        cout<<"    Unit:";
        cin>>unit[q];
        cout<<"    Score:";
        cin>>score[q];
    }
}
int University::grade(int p[]){
// METHOD WHICH CONVERTS SCORE TO ITS EQUIVALENT POINT
    for(int m=0; m<nCourses; m++){
        if(p[m]<40){
            p[m]=0;
        } else if((p[m]<45) && (p[m]>=40)){
            p[m]=1;
        } else if((p[m]<50) && (p[m]>=45)){
            p[m]=2;
        } else if((p[m]<60) && (p[m]>=50)){
            p[m]=3;
        } else if((p[m]<70) && (p[m]>=60)){
            p[m]=4;
        } else if(p[m]>=70){
            p[m]=5;
        }
    }
    return p[nCourses];
}
void University::GPA(){
// METHOD TO CALCULATE GPA
    // Converting scores to equivalent point
    grade(score);
    // Calculating grade point
    for(int t=0; t<nCourses; t++){
        MGpoint[t] = unit[t]*score[t];
    }
    // Summing total units & mgpoint
    for(int r=0; r<nCourses; r++){
        total_unit += unit[r];
        total_MGpoint += MGpoint[r];
    }
    gpa = total_MGpoint/total_unit;
    cout<<"Your GPA for the semester is "
            <<fixed<<setprecision(1)<<gpa<<" Boss😅"<<endl;
}
void University::CGPA(){
// METHOD TO CALCULATE CGPA
    double semesters = 0;
    double count = 0;
    cout<<"Number Of Semesters:";
    cin>>semesters;
    for(int u=1; u<=semesters; u++){
        cout<<"  SEMESTER "<<u<<":"<<endl;
        getdata();
        GPA();
        count += gpa;
    }
    cgpa = count/semesters;
    cout<<"*******************************"
            <<"\nYour CGPA is "
            <<fixed<<setprecision(1)<<cgpa<<" Boss🌚"
            <<"*******************************"
            <<endl;
}

int main(){
// MAIN
    University oau;
    auto choice = 0;
    cout<<"**************************************\n"
             <<"*         CGPA CALCULATOR            *\n"
             <<"*           ...by @eyakenoJNR        *\n"
             <<"**************************************"<<endl;
    while(true){
        cout<<"\n\n1. Calculate GPA (Single Semester)."
                <<"\n2. Calculate CGPA (Multiple Semesters)."
                <<"\n3. Exit."
                <<"\nInput>>";
        cin>>choice;
        cout<<endl;
        // Exception block to catch invalid inputs
        try{
            if(choice == 0){
                throw 505;
            } else{
                switch(choice){
                case 1: oau.getdata();
                              oau.GPA();
                              break;
                case 2: oau.CGPA();
                              break;
                case 3: cout<<"Exiting...";
                            exit(0);
                default: cout<<"Invalid Input!🚫";
                }
            }
        }
        catch(...){
            cout<<"\tError⚠ \nInvalid Character(s) Detected."<<endl;
            break;
        }
    }
    return 0;
}
