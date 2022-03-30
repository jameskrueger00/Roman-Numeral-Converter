//OIT Coding Challenge Completed by Jamie Krueger
//03/29/2022
//Start: 7:30pm
//Finish: 11:30pm


#include <iostream>
#include <cstring>
#include "RomanNumeral.h"

using namespace std;

void badArguments(){
    cout << "-----------------------------------" << endl;
    cout << "Usage: convert [-dtr/-rtd] <value>" << endl;
    cout << "-----------------------------------" << endl;
    cout << "-dtr: decimal to roman" << endl;
    cout << "-rtd: roman to decimal" << endl;
    cout << "<value>: valid roman numeral/integer (0 < value < 4000)" << endl;
    cout << "-----------------------------------" << endl;
    exit(1); //failure
}

int main(int argc, char *argv[]){
    //Parse the command line
    if (argc != 3 || (strcmp(argv[1], "-rtd") != 0 && strcmp(argv[1], "-dtr") != 0) ) { //check number of args + conversion flag
        badArguments();
    }
    if (argc == 3 && strcmp(argv[1], "-rtd") == 0) { //roman to decimal conversion
        RomanNumeral value = RomanNumeral(argv[2]);

        if(value.RomanNumeral::isValidRomanNumeral()){ //check for valid roman numeral input
            cout << value.toString(true);
        } else{
            cout << "-----------------------------------" << endl;
            cout << "INVALID ROMAN NUMERAL" << endl;
            badArguments();
        }


    } else {
        char* endptr;
        long converted = strtol(argv[2], &endptr, 10); //convert input to integer - stdlib

        if (*endptr || converted < 1 || converted > 3999) { //check for valid decimal input
            cout << "-----------------------------------" << endl;
            cout << "INVALID INTEGER" << endl;
            badArguments(); // conversion failed because the input wasn't a number, or was negative
        }
        else {
            RomanNumeral value = RomanNumeral(stoi(argv[2]));
            cout << value.toString(false);
        }

    }


    return 0;
}


