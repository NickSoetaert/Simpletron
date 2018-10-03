/* 
 * File:   Null.h
 * Author: nick
 *
 * Created on November 17, 2017, 6:25 PM
 *
 */

#ifndef NULL_H
#define NULL_H
#include "Instruction.h"

//Does nothing, but still helps increment to the next instruction
class Null : public Instruction
{
public:
    Null(int word) : Instruction(){
        //this->setWord(word);
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        return -1;
    }
};

#endif /* NULL_H */

