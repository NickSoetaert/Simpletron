/* 
 * File:   JumpZero.h
 * Author: nick
 *
 * Created on November 15, 2017, 8:05 PM
 */

#ifndef JUMPZERO_H
#define JUMPZERO_H

#include "Instruction.h"

using namespace std;

//If accum == 0, alters instruction* to specified address
class JumpZero: public Instruction
{
public:
    JumpZero(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        if(accumulator == 0)
        {
            //here, we have the 2 digit int that describes the location we want
            int positionToJumpTo = this->getMemoryAddress();
            return positionToJumpTo;
        }
        else{//behave like a null
            return -1;
        }
    }
};

#endif /* JUMPZERO_H */

