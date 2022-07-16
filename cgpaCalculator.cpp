#include "cgpaCalculator.h"
#include <iomanip>
using namespace std;

void University::set_grade(){
    cout<<"A grade: ";
    cin>>A_grade;
    cout<<"B grade: ";
    cin>>B_grade;
    cout<<"C grade: ";
    cin>>C_grade;
    cout<<"D grade: ";
    cin>>D_grade;
    cout<<"E grade: ";
    cin>>E_grade;
}

void University::getdata(){
/* GET DATA FROM USER */
    string cCode[MAX_VAL];
    
    while(true){
        cout<<"\nNumber of Courses registered ("<<MAX_VAL<<" max):";
        cin>>nCourses;
        
        #undef MAX_VAL
        #define MAX_VAL nCourses
        
        if ((!cin) || (nCourses > MAX_VAL) || (nCourses < 1)){
            cin.clear();
            clear_buffer();
            clrscr();
            cerr<<"\tError⚠ \nInvalid Input!"<<endl;
        } else{
            cout<<"...Fill In Your Data..."<<endl;
            for(int q=0; q<nCourses; q++){
                cout<<"Course Code: ";
                cin>>cCode[q];
                cout<<"    Unit:";
                cin>>unit[q];
                cout<<"    Score:";
                cin>>score[q];
            }
            break;
        }
    }
}

int University::grade(int p[]){
/* CONVERT SCORE TO ITS EQUIVALENT POINT */
    for(int m=0; m<nCourses; m++){
        if(p[m]<E_grade){
            p[m]=0;
        } else if((p[m]<D_grade) && (p[m]>=E_grade)){
            p[m]=1;
        } else if((p[m]<C_grade) && (p[m]>=D_grade)){
            p[m]=2;
        } else if((p[m]<B_grade) && (p[m]>=C_grade)){
            p[m]=3;
        } else if((p[m]<A_grade) && (p[m]>=B_grade)){
            p[m]=4;
        } else if(p[m]>=A_grade){
            p[m]=5;
        }
    }
    return p[nCourses];
}

void University::GPA(){
/* CALCULATE GPA */
    grade(score);    // Converting scores to equivalent point
    
    /* Calculating grade point */
    for(int t=0; t<nCourses; t++){
        MGpoint[t] = unit[t]*score[t];
    }
    
    /* Summing total units & mgpoint */
    for(int r=0; r<nCourses; r++){
        total_unit += unit[r];
        total_MGpoint += MGpoint[r];
    }
    clrscr();
    gpa = total_MGpoint/total_unit;
    cout<<"Present GPA: "
        <<fixed<<setprecision(1)<<gpa<<endl;
}

void University::CGPA(){
/* CALCULATE CGPA */
    double semesters{}, count{};
    
    /* Get number of semesters for cgpa calculation */
    while(true){
        cout<<"Number Of Semesters (10 max):";
        cin>>semesters;
        if (!cin || semesters < 1 || semesters > 10){
            cin.clear();
            clear_buffer();
            clrscr();
            cerr<<"\tError⚠ \nInvalid Input!"<<endl;
        } else{
            for(int u=1; u<=semesters; u++){
                cout<<"  SEMESTER "<<u<<":"<<endl;
                getdata();
                GPA();
                count += gpa;
            }
            cgpa = count/semesters;
            cout<<"*******************************"
                <<"\nCGPA:"
                <<fixed<<setprecision(1)<<cgpa
                <<"*******************************"
                <<endl;
            break;
        }
    }
}

void University::clear_buffer(){
/* Clear buffer */
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
