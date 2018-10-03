#ifndef ADD_H
#define ADD_H

#include "Instruction.h"

using namespace std;

//Adds Instruction's value into accumulator
class Add : public Instruction
{
public:
    Add(int word) : Instruction(){
        //this->setWord(word);
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        int memAddress = this->getMemoryAddress();
        accumulator += memory[memAddress]->getWord();

        return -1;
        //if (instruction_ptr == -1)
        //{just increment instruction pointer by 1}
        //else (in case of a jump)
        //{set instruction_pointer to this value}
    }
};

#endif /* ADD_H */

