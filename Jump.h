/* 
 * File:   Jump.h
 * Author: nick
 *
 * Created on November 15, 2017, 7:57 PM
 */

#ifndef JUMP_H
#define JUMP_H

#include "Instruction.h"
#include "Computer.h"

using namespace std;


class Jump : public Instruction
{
public:
    Jump(int word) : Instruction(){
        _word = word;
    }
    
    int execute(int& accumulator, vector<Instruction*> &memory){
        //here, we have the 2 digit int that describes the location we want
        int positionToJumpTo = this->getMemoryAddress(); 
        return positionToJumpTo;
        
         //this->setMemoryAddress(this->getMemoryAddress()); //DOES NOT WORK. This line of code doesn't actually accomplish anything

        
//        Instruction* pointedToInstruction = memory[(this->getMemoryAddress())]; //here, we get the Instruction* to our DESIRED location
//        int currentInstructionMemory = pointedToInstruction->getMemoryAddress(); //here is the 2 digit mem address TAKEN FROM our destination
        
        //int x = std::distance(memory.begin(), it)
        
        //memory[pointedToInstruction];
        
        //this just sets the position we want to jump to to our current value
        //memory[currentInstructionMemory] = memory[positionToJumpTo];
        
        //memory[currPosition] = currIndex;
        
//        cout << "~~~Position: " << currPosition << endl
//                << "~~~Word at position: " << currIndex->getWord() << endl;
        //memory[(this->getMemoryAddress())] = this->getMemoryAddress();
        
        
        //What we want to do: change _instruction_pointer
        //set memory[current] to memory[this->getMemoryAddress()]
        //return memory[memAddress]->getMemoryAddress();
    }
};

#endif /* JUMP_H */

