/* 
 * File:   Read.h
 * Author: nick
 *
 * Created on November 14, 2017, 5:55 PM
 */

#ifndef READ_H
#define READ_H

#include <iostream>
#include "Instruction.h"

using namespace std;

class Read : public Instruction
{
public:
    Read(int word) : Instruction(){
        _word = word;
    }
    //Read a word from the command line into a specific location in memory.
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        int inputNum;
        cout << "Enter Input: " << endl;
        cin >> inputNum;
        memory[memAddress]->setWord(inputNum);
        return -1;
    }
};
#endif /* READ_H */

