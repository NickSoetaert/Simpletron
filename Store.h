/* 
 * File:   Store.h
 * Author: nick
 *
 * Created on November 14, 2017, 6:58 PM
 */

#ifndef STORE_H
#define STORE_H

#include "Instruction.h"


using namespace std;

//loads accumulator into given Instruction
class Store : public Instruction
{
public:
    Store(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        memory[memAddress]->setWord(accumulator);
        return -1;
    }
    
};

#endif /* STORE_H */

