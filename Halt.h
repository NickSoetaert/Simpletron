/* 
 * File:   Halt.h
 * Author: nick
 *
 * Created on November 15, 2017, 7:45 PM
 */

#ifndef HALT_H
#define HALT_H

#include "Instruction.h"
#include "Computer.h" //for hasProgramFinished()

using namespace std;

//Sets _has_halted to true
class Halt : public Instruction
{
public:
    Halt(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){

        cout << "~~~~~~~~~~~END OF PROGRAM~~~~~~~~~~~" << endl;
        return -9999;
    }
};

#endif /* HALT_H */

