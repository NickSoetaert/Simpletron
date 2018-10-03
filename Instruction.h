#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Operation_t.h"

using namespace std;

//still need constructors for both Instruction and Computer classes
class Instruction
{
public:
    
    //Constructor
    Instruction(int word);
    Instruction();
    ///Destructor
    virtual ~Instruction();

    static Operation_t fromInt(int _word);

    //Getters
    const int getWord();
    Operation_t getOperation();
    const int getMemoryAddress();


    //Setters
    void setMemoryAddress(int value);
    void setWord(int word);

    //Note: memory is pass by reference and a vector, 
    //much like ProcessImage from SimpleImageEffect.
    
    virtual int execute(int& accumulator, vector<Instruction*> &memory) = 0;


protected: //Note: Adam has this as private
    int _word; //This is the 4 digit int that the programs we run will read.

};


#endif
