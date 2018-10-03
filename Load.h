/* 
 * File:   Load.h
 * Author: nick
 *
 * Created on November 14, 2017, 6:24 PM
 */

#ifndef LOAD_H
#define LOAD_H

#include "Instruction.h"

using namespace std;

//loads given Instruction into accumulator
class Load : public Instruction
{
public:
    Load(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        accumulator = memory[memAddress]->getWord();
        return -1;
    }
    
};

#endif /* LOAD_H */
