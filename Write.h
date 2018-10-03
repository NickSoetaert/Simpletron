/* 
 * File:   Write.h
 * Author: nick
 *
 * Created on November 14, 2017, 6:06 PM
 */

#ifndef WRITE_H
#define WRITE_H

#include "Instruction.h"

//Writes given instruction to screen
using namespace std;

class Write : public Instruction
{
public:
    Write(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        
        //memAddress is the address of the word. For example,
        //if memory[index] = 0315, memAddress will be 15
        int memAddress = this->getMemoryAddress();
        
        cout<< "~~~~~~ Written to screen: " 
            << memory[memAddress]->getWord()
            << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            << endl;
        //exit(0); //making the assumption that I want to exit after I print
        return -1;

    }
};

#endif /* WRITE_H */