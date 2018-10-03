#include "Computer.h"
#include "Operation_t.h"

#include "Null.h"
#include "Read.h"
#include "Write.h"
#include "Load.h"
#include "Store.h"
#include "Add.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
#include "Jump.h"
#include "JumpNeg.h"
#include "JumpZero.h"
#include "Halt.h"

//Constructor. 
Computer::Computer(){
    _has_halted = false;
    _instruction_pointer = 0;
    _accumulator = 0;
}

Computer::Computer(string filename){
    int nextInt;

    ifstream input_stream;
    input_stream.open(filename.c_str());
    
    if(input_stream.fail()){
        cout << "~~~~ File failed to open. Exiting program. ~~~~" << endl;
        exit(1);
    }
    else{
        cout<< "~~~~ Successfully Opened File : " 
            << filename << " ~~~~" << endl;
    }
    
    while(input_stream >> nextInt){
        this->loadInstruction(nextInt); //sets _memory
    }
    
    _has_halted = false;
    _instruction_pointer = 0;
    _view_instruction_pointer = 0;
    _accumulator = 0;
    
}

const int Computer::getMemorySize()
{
    return _memory.size();
}

bool Computer::hasProgramFinished()
{
    return _has_halted; //basically just a getter for _has_halted (?)

}

//unused function
void Computer::setHasHalted(bool boolVal)
{
    _has_halted = boolVal;
}

const int Computer::getAccumulator()
{
    return _accumulator;
}

void Computer::setAccumulator(int value)
{
    _accumulator = value;
}

//gets an index number to access _memory with
const int Computer::getInstructionPointer()
{
    return _instruction_pointer;
    //returns instruction NUMBER [0-99], not a real c++ pointer
}

//returns an indexed Instruction* from _memory
Instruction* Computer::getMemoryLocation(int index)
{
    return _memory[index];
}

//resets _view_instruction_pointer to 0
void Computer::resetViewInstructionPointer()
{
    _view_instruction_pointer = 0;
}

//returns next Instruction*, but WILL NOT CHANGE _instruction_pointer
Instruction* Computer::viewNextInstruction()
{
    _view_instruction_pointer++; //cannot go after return
    return _memory[_view_instruction_pointer - 1]; 
    //-1 so we don't miss first value
}


Instruction* Computer::getNextInstruction()
{
    _instruction_pointer++; //cannot go after return statement
    return _memory[_instruction_pointer-1]; //-1 so we don't miss first value
}

//executes the instruction AND increments _instruction_pointer
void Computer::executeNextInstruction()
{
    ///Executes the next instruction from _memory.
    _accumulator = getAccumulator();
    int x = (_memory[_instruction_pointer]->execute(_accumulator, _memory));
    
    if(x == -9999){ //halt
        _has_halted = true;
    }
    else if(x == -1){ //normal statement
        _instruction_pointer++;
    }
    else{ //jump
        cout << "We just jumped from " << _instruction_pointer << " to ";
        _instruction_pointer = x;
        cout << _instruction_pointer << endl;
    }
}

//Builds _memory (creates a vector of specific type instructions.)
void Computer::loadInstruction(int word)
{
    int operation = (word / 100);
    
    //I know this is god awful ugly.
    //Possible way to replace switch: Google "Factory problem"
    switch(operation){
        case null:{
            Null* specificInstruction = new Null(word); //Why isn't this setting the word?
            _memory.push_back(specificInstruction);
            break;
        }
        case READ:{
            Read* specificInstruction = new Read(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case WRITE:{
            Write* specificInstruction = new Write(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case LOAD:{
            Load* specificInstruction = new Load(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case STORE:{
            Store* specificInstruction = new Store(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case ADD:{
            Add* specificInstruction = new Add(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case SUBTRACT:{
            Subtract* specificInstruction = new Subtract(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case DIVIDE:{
            Divide* specificInstruction = new Divide(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case MULTIPLY:{
            Multiply* specificInstruction = new Multiply(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case JUMP:{
            Jump* specificInstruction = new Jump(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case JUMPNEG:{
            JumpNeg* specificInstruction = new JumpNeg(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case JUMPZERO:{
            JumpZero* specificInstruction = new JumpZero(word);
            _memory.push_back(specificInstruction);
            break;
        }
        case HALT:{
            Halt* specificInstruction = new Halt(word);
            _memory.push_back(specificInstruction);
            break;
        }    
    }
}

//why do I need this overload?
void Computer::loadInstruction(Instruction* Instruction)
{
    
}

/*  ---vars declared in header---
    vector<Instruction*> _memory; //A vector containing instructions to execute
    bool _has_halted;
    int _instruction_pointer; //instruction NUMBER (like, 0-50, not a *)
    int _accumulator;
 */
