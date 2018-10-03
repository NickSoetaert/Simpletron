/* 
 * File:   Multiply.h
 * Author: nick
 *
 * Created on November 14, 2017, 10:22 PM
 */

#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Instruction.h"

using namespace std;

//Multiplies Instruction's value by the accumulator
class Multiply : public Instruction
{
public:
    Multiply(int word) : Instruction(){
        _word = word;
    }
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        accumulator *= memory[memAddress]->getWord();
        return -1;
    }
};

#endif /* MULTIPLY_H */