#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> //gives padding to cout

#include "Computer.h"

using namespace std;

int main()
{
    
    string filename;
    cout << "Please enter input file name." << endl;
    cout << "Choices are: " << endl <<
            "1) Fib.txt" << endl <<
//            "2) AddTwo.txt" << endl <<
//           "3) FindLargest.txt" << endl <<
            "2) Manually enter machine code (debug)" << endl;
    cin >> filename;
    
    if(filename == "1"){
            filename = "Fib.txt";
    } /*
    else if(filename == "2"){
            filename = "AddTwo.txt";
    }
    else if(filename == "3"){
            filename = "FindLargest.txt";
    } */
    else if(filename == "2"){
            filename = "Manual.txt";
            cout<< setfill('=') << setw(75)
                <<" Please enter your code one line at a time. " << endl
                <<" The interpreter will provide you with a line" << endl
                <<" number, and a question mark <?> as a prompt." << endl
                <<" Once you are finished, enter \"-9999\" to quit." << endl;
            
            int nextInt;
            int counter = 0;
            ofstream outFile;
            outFile.open("Manual.txt");
            while(nextInt != -9999){
                cout << counter << " ? ";
                cin >> nextInt;
                if(nextInt != -9999){
                    outFile << nextInt << endl;
                }
            }
    }
    
    
    
    Computer Simpletron = Computer(filename);
    
    int accumulator = Simpletron.getAccumulator();
    
    Instruction* nextInstruction = Simpletron.getMemoryLocation(0);
    Instruction* nextDisplayInstruction;

    while(Simpletron.hasProgramFinished() == false)
    {
        nextInstruction = 
                Simpletron.getMemoryLocation(
                Simpletron.getInstructionPointer());
        if(nextInstruction!=NULL){
            cout<< "***********************NEXT INSTRUCTION***********************" 
                << endl
                << "REGISTERS:" << endl
                << "Accumulator: " << Simpletron.getAccumulator() << endl
                << "Instruction Counter: " << Simpletron.getInstructionPointer() 
                    << endl
                << "Next Instruction: "
                << setfill('0') << setw(4) << nextInstruction->getWord()
                    << endl
                << "Operation Code: "
                << setfill('0') << setw(2) << nextInstruction->getOperation()
                    << endl     
                << "Memory Address: "
                << setfill('0') << setw(2) << nextInstruction->getMemoryAddress() 
                    << endl
                << "-------------------------" << endl;
        }
        
        cout << "MAIN MEMORY:" << endl << "     ";
        for(int i = 0; i < 10; i++){
            cout << setfill('_') << setw(6) << i;
        }
        cout << "__" << endl;

        for(int i = 0; i < ((Simpletron.getMemorySize()/10)+1); i++){
            cout<< setfill(' ') << setw(5) << i << "|";

            for(int j = 0; j < 10; j++){
                nextDisplayInstruction = Simpletron.viewNextInstruction();
                //check that we don't try to access a null index
                if(nextDisplayInstruction == NULL){
                    cout << "  " << "NULL";
                }
                else{     
                    cout<< "  "
                        << setfill('0') << setw(2) 
                            << nextDisplayInstruction->getOperation()
                        << setfill('0') << setw(2) 
                            << nextDisplayInstruction->getMemoryAddress(); 
                }
            }
        cout << "|" << endl;
        }
        
        
        cout << endl;  
        
        Simpletron.executeNextInstruction();
        Simpletron.resetViewInstructionPointer();
        accumulator = Simpletron.getAccumulator();
        
    } //end while(Simpletron.hasProgramFinished() == false)
return(0);    
}
