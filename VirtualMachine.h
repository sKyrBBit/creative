//
// Created by mirro on 2019/09/13.
//

#ifndef UNTITLED7_VIRTUALMACHINE_H
#define UNTITLED7_VIRTUALMACHINE_H

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

#include "Object_.h"
#include "Frame.h"
#include "Structures/instruction.h"

using namespace std;

class VirtualMachine {
private:
    vector<uint8_t> input;
    uint32_t position;
    instruction* instructions;
    Object_** constant_pool;
    uint32_t counter; // program counter
    Object_** registers;
    uint32_t* functions;
    stack<Frame*> runtime_stack;
public:
    VirtualMachine(const vector<uint8_t> input) {
        this->input = input;
        this->position = 0;
        this->counter = 0;
    }
    uint32_t analyze();
    void execute(int entry_point);
private:
    uint8_t* read(int32_t length);
    uint32_t* read_int();
};


#endif //UNTITLED7_VIRTUALMACHINE_H
