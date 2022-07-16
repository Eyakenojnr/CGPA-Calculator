#include "cgpaCalculator.h"
using namespace std;

/* Driver code */
int main(){
    University oau; // create object
    
    auto choice = 0;
    
    clrscr();
    cout<<"**************************************\n"
        <<"*         CGPA CALCULATOR            *\n"
        <<"*           ...by @Eyakenojnr        *\n"
        <<"**************************************"<<endl;
             
    while(true){
        char set_grade;
        
        cout<<"\nSet grade or use default? (y/n) ";
        cin>>set_grade;
        
        if(set_grade == 'y' || set_grade == 'Y'){
            oau.set_grade();
            break;
        } else if(set_grade == 'n' || set_grade == 'N'){
            cout<<"\tDefault grading used..."<<endl;
            break;
        } else{
            cerr<<"\tWrong Input!"<<endl;
            oau.clear_buffer();
            continue;
        }
    }
    while(true){
        cout<<"\n\n1. Calculate GPA."
            <<"\n2. Calculate CGPA."
            <<"\n3. Exit."
            <<"\nInput: ";
        cin>>choice;
        cout<<endl;
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
                case 3: cout<<"Exiting...\n";
                            exit(0);
                default: clrscr();
                        cerr<<">>>Invalid Input!<<<";
                }
            }
        }
        catch(...){
            cerr<<"\tError⚠ \nInvalid Character(s) Detected."<<endl;
            break;
        }
    }
    return 0;
}
