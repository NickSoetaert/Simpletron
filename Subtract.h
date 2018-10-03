/* 
 * File:   Subtract.h
 * Author: nick
 *
 * Created on November 14, 2017, 10:13 PM
 */

#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "Instruction.h"

using namespace std;

//Subtracts Instruction's value from the accumulator
class Subtract : public Instruction
{
public:
    Subtract(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        accumulator -= memory[memAddress]->getWord();
        return -1;
    }
};

#endif /* SUBTRACT_H */

