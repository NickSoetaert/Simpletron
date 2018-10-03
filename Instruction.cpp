#include "Instruction.h"

///Constructor
//PURE VIRTUAL; CANNOT INITIATE
Instruction::Instruction()
{
    _word = 0;
}

//PURE VIRTUAL; CANNOT INITIATE
Instruction::Instruction(int givenWord)
{
    _word = givenWord;
}

///Destructor
Instruction::~Instruction(){
    cout << "Calling destructor" << endl;
}

//Static function
Operation_t Instruction::fromInt(int _word)
{
    Operation_t op_t = static_cast<Operation_t>(_word);
    return op_t;
}

///Getters

//Gets the 1st and 2nd digits of _word
Operation_t Instruction::getOperation() 
{
    int firstDigits = (_word / 100);  //Sometimes results in seg fault when called
    Operation_t enumeratedFirstDigits = fromInt(firstDigits);
    return enumeratedFirstDigits;
}

const int Instruction::getMemoryAddress() ///3rd and 4th digits of _word
{
    return (_word % 100); //only returns the 3rd and 4th digits. Clever, right?
    
}

const int Instruction::getWord()
{
    return _word;
}

//Setters. Note: no instruction setter, as we never change that.
void Instruction::setMemoryAddress(int value)  ///3rd and 4th digits
{
    _word = ((_word - (_word%100)) + value);
}

void Instruction::setWord(int word)
{
    _word = word;
}

//NOTE: WAS ALREADY DECLARED VIRTUAL IN HEADER.
int Instruction::execute(int& accumulator, vector<Instruction *> &memory){
    
}


