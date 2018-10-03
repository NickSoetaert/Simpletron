/* 
 * File:   JumpNeg.h
 * Author: nick
 *
 * Created on November 15, 2017, 8:02 PM
 */

#ifndef JUMPNEG_H
#define JUMPNEG_H

#include "Instruction.h"

using namespace std;

//Adds Instruction's value into accumulator
class JumpNeg : public Instruction
{
public:
    JumpNeg(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        if(accumulator < 0)
        {
            //here, we have the 2 digit int that describes the location we want
            int positionToJumpTo = this->getMemoryAddress(); 
            return positionToJumpTo;
        }
        else{ //behave like a null
            return -1;
        }
    }
};


#endif /* JUMPNEG_H */

