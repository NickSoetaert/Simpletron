/* 
 * File:   Operation_t.h
 * Author: nick
 *
 * Created on November 16, 2017, 5:16 PM
 */

#ifndef OPERATION_T_H
#define OPERATION_T_H

enum Operation_t
    {
        null = 00,
        READ = 10,
        WRITE = 11,
        LOAD = 20,
        STORE = 21,
        ADD = 30,
        SUBTRACT = 31,
        DIVIDE = 32,
        MULTIPLY = 33,
        JUMP = 40,
        JUMPNEG = 41,
        JUMPZERO = 42,
        HALT = 43
    };

#endif /* OPERATION_T_H */

