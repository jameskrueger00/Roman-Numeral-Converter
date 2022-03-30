//Jamie Krueger 03/29/2022

#pragma once

//Macro values for readability
#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1
#define UNDEFINED 1001

#include <string>
#include <sstream>
#include <iostream>
#include <utility>


using namespace std;
class RomanNumeral
{
private:
    string value;
    unsigned int intValue;

public:

    explicit RomanNumeral(string value) : value(std::move(value)) { //roman value constructor
        intValue = 0;
    }

    explicit RomanNumeral(const unsigned int &intValue) : intValue(intValue){ //decimal value constructor
        value = "";
    }

    string toString(bool flag){ //1 == -rtd, 0 == -dtr
        stringstream out;
        if(flag)
            out << value << " in decimal is " << toDecimal() << endl;
        else out << intValue << " in roman numerals is " << toRoman() << endl;
        return out.str();
    }

    //checks for valid roman numeral, returns true if valid
    bool isValidRomanNumeral(){
        int curr = UNDEFINED;
        int prev = UNDEFINED;
        int next = UNDEFINED;
        int duplicate = 1; //counts multiples of the same char in a row

        for(unsigned int i = 0; i < value.size(); i++){ //loop through the chars

            if(i > 0){
                prev = charToInt(value.at(i-1));
            }
            curr = charToInt(value.at(i));
            if(i < value.size() - 1){
                next = charToInt(value.at(i+1));
            } else {
                next = 0;
            }

            if (curr == prev){ //check for no more than 3 of any char in a row + only a single 1 L, D, or V
                if(curr == D || curr == L || curr == V)
                    return false;

                duplicate++;

                if (duplicate > 3){
                    return false;
                }
            } else duplicate = 1;

            switch(curr){ //check for proper order of chars
                case M:
                    if((prev != C && prev < M) || (prev == C && next >= M)){
                        return false;
                    }
                    break;
                case D:
                    if((prev != C && prev < D) || (prev == C && next >= D)){
                        return false;
                    }
                    break;
                case C:
                    if((prev != X && prev < C) || (prev == C && next > C) || (prev == X && next >= C) ){
                        return false;
                    }
                    break;
                case L:
                    if((prev != X && prev < L) || (prev == X && next >= L)){
                        return false;
                    }
                    break;
                case X:
                    if((prev != I && prev < X) || (prev == X && next > X) || (prev == I && next >= X)){
                        return false;
                    }
                    break;
                case V:
                    if((prev != I && prev < V) || (prev == I && next >= V)){
                        return false;
                    }
                    break;
                case I:
                    if(prev == I && next > I){ //subtractive notation only ever involves two symbols
                        return false;
                    }
                    break;
                default:
                    return false;
            }



        }

        return true;
    }

    unsigned int toDecimal(){
        unsigned int result = 0;
        int curr = UNDEFINED;
        int prev = UNDEFINED;
        int next = UNDEFINED;

        for(unsigned int i = 0; i < value.size(); i++){ //loop through the chars
            if(i > 0){
                prev = charToInt(value.at(i-1));
            }
            curr = charToInt(value.at(i));
            if(i < value.size() - 1){
                next = charToInt(value.at(i+1));
            } else {
                next = 0;
            }

            if(curr <= prev && curr >= next){ //Arithmetic
                result += curr;
            } else { //subtractive notation
                result += (next-curr);
                i++;
            }


        }


        return result;
    }

    string toRoman(){
        stringstream out;

        unsigned int placeValues[4];
        for(unsigned int& i :placeValues){ //calculate place values
            i = intValue % 10;
            intValue = (intValue - i) / 10;
        }

        for(unsigned int i = 0; i < placeValues[3]; i++){ //convert thousands place
            out << 'M';
        }

        switch(placeValues[2] * 100){ //convert hundreds place
            case M - C:
                out << "CM";
                break;
            case D + (C*3):
                out << "DCCC";
                break;
            case D + (C*2):
                out << "DCC";
                break;
            case D + C:
                out << "DC";
                break;
            case D:
                out << "D";
                break;
            case D - C:
                out << "CD";
                break;
            case (C*3):
                out << "CCC";
                break;
            case (C*2):
                out << "CC";
                break;
            case C:
                out << "C";
                break;
            default:
                break;
        }

        switch(placeValues[1] * 10){ //convert tens place
            case C - X:
                out << "XC";
                break;
            case L + (X*3):
                out << "LXXX";
                break;
            case L + (X*2):
                out << "LXX";
                break;
            case L + X:
                out << "LX";
                break;
            case L:
                out << "L";
                break;
            case L - X:
                out << "XL";
                break;
            case (X*3):
                out << "XXX";
                break;
            case (X*2):
                out << "XX";
                break;
            case X:
                out << "X";
                break;
            default:
                break;
        }

        switch(placeValues[0]){ //convert ones place
            case X - I:
                out << "IX";
                break;
            case V + (I*3):
                out << "VIII";
                break;
            case V + (I*2):
                out << "VII";
                break;
            case V + I:
                out << "VI";
                break;
            case V:
                out << "V";
                break;
            case V - I:
                out << "IV";
                break;
            case (I*3):
                out << "III";
                break;
            case (I*2):
                out << "II";
                break;
            case X:
                out << "I";
                break;
            default:
                break;
        }
        return out.str();
    }

    static int charToInt(char c){
        switch(c){
            case 'M':
                return M;
            case 'D':
                return D;
            case 'C':
                return C;
            case 'L':
                return L;
            case 'X':
                return X;
            case 'V':
                return V;
            case 'I':
                return I;
            default:
                return UNDEFINED;
        }
    }
};