/* 
 * File:   Divide.h
 * Author: nick
 *
 * Created on November 14, 2017, 10:16 PM
 */

#ifndef DIVIDE_H
#define DIVIDE_H

#include "Instruction.h"

using namespace std;

//Divides Instruction's value by the accumulator
class Divide : public Instruction
{
public:
    Divide(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        accumulator /= memory[memAddress]->getWord();
        return -1;
    }
};

#endif /* DIVIDE_H */

