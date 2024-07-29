#include <stack>
#include <iostream>
#include <stdlib.h>
#include <cstring>

int RPN(std::string *input, unsigned int input_size){
    std::stack<int> stack_values;

    for(unsigned int i = 0; i < input_size ; i++){
        std::string tmp = input[i];
        if (isdigit(tmp[0]) || (tmp[0] == '-' && isdigit(tmp[1])))
            stack_values.push(std::atof(tmp.c_str()));
        else{
            int result;
            int values[2];
            values[0] = stack_values.top();
            stack_values.pop();
            values[1] = stack_values.top();
            stack_values.pop();

            if(std::strcmp(tmp.c_str(), "+"))
                result = values[0] + values[1];
            else if(std::strcmp(tmp.c_str(), "-"))
                result = values[0] - values[1];
            else if(std::strcmp(tmp.c_str(), "/"))
                result = values[0] / values[1];
            else if(std::strcmp(tmp.c_str(), "*"))
                result = values[0] * values[1];
            else
                std::cout << "Error" << std::endl;
            stack_values.push(result);
        }
    }
    return stack_values.top();
}

int main(void) {
    std::string input[] = {"41", "53", "12", "-", "-26", "+", "-", "-"};
    unsigned int input_size = 7;
    std::cout << RPN(input, input_size) << std::endl;
    return 0;
}

