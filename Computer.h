#ifndef COMPUTER_H
#define COMPUTER_H

#include "Instruction.h"
#include "Add.h"
#include "Operation_t.h"
//#include "CreateInstructionVector.h"  //CAUSES ERROR TO INCLUDE


using namespace std;

class Computer
{
public:   
    ///Constructor
    //Simpletron();
    Computer();
    Computer(string filename);
    
    ///Helper
    bool hasProgramFinished();
    
    ///Getters
    const int getMemorySize();
    const int getInstructionPointer();
    const int getAccumulator();
    Instruction* getMemoryLocation(int index);
    Instruction* getNextInstruction();
    Instruction* viewNextInstruction();

    ///Setters
    void resetViewInstructionPointer();
    void setAccumulator(int value);
    void setMemory(vector<Instruction> memory);
    void setHasHalted(bool boolVal); //making static doesn't seem to fix problem
    
    ///Logic
    void executeNextInstruction();
    void loadInstruction(int word);
    void loadInstruction(Instruction* Instruction); //overloading?
    void createInstructionVector(string filename);

private:
    vector<Instruction*> _memory; ///A vector containing instructions to execute
    bool _has_halted;
    int _instruction_pointer;
    int _view_instruction_pointer;//helps with viewNextInstruction()
    int _accumulator;
};

#endif // COMPUTER_H
