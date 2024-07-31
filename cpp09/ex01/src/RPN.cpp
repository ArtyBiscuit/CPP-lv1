#include <RPN.hpp>

long long int RPN(std::string *input, unsigned int input_size){
    std::stack<int> stack_values;

    for(unsigned int i = 0; i < input_size ; i++){
        std::string tmp = input[i];
        if (isdigit(tmp[0]) || (tmp[0] == '-' && isdigit(tmp[1])))
            stack_values.push(std::atof(tmp.c_str()));
        else if (stack_values.size() >= 2){
            long long int result = 0;
            int values[2];
            values[0] = stack_values.top();
            stack_values.pop();
            values[1] = stack_values.top();
            stack_values.pop();
            if(!std::strcmp(tmp.c_str(), "+"))
                result = values[1] + values[0];
            else if(!std::strcmp(tmp.c_str(), "-"))
                result = values[1] - values[0];
            else if(!std::strcmp(tmp.c_str(), "/")){
                if(values[0] == 0){
                    delete[] input;
                    throw divisByZero();
                }
                result = values[1] / values[0];
            }
            else if(!std::strcmp(tmp.c_str(), "*"))
                result = values[1] * values[0];
            else
                std::cout << "Error" << std::endl;
            stack_values.push(result);
        }
        else{
            delete[] input;
            throw Error();
        }
    }
    if (stack_values.size() >= 2){
        delete[] input;
        throw Error();
    }
    delete[] input;
    return stack_values.top();
}

int getSize(std::string input){
    int size = 1;
    for(int i = 0; input[i]; i++){
        if (input[i] == ' ')
            size++;
    }
    return (size);
}

std::string *split(std::string input, int &index){
    int rpnSize = getSize(input);
    std::string *array = new std::string[rpnSize];

    for(int i = 0; input[i]; i++){
        if(input[i] == ' ')
            continue;
        if (input[i] >= '0' && input[i] <= '9' && (input[i+1] == ' ' || input[i+1] == '\0')){
            array[index] = input[i];
            index++;
            continue;
        }
        if(input[i] == '+' && (input[i+1] == ' ' || input[i+1] == '\0')){
            array[index] = input[i];
            index++;
            continue;
        }
        if(input[i] == '-' && (input[i+1] == ' ' || input[i+1] == '\0')){
            array[index] = input[i];
            index++;           
            continue;
        }
        if(input[i] == '*' && (input[i+1] == ' ' || input[i+1] == '\0')){
            array[index] = input[i];
            index++;
            continue;
        }
        if(input[i] == '/' && (input[i+1] == ' ' || input[i+1] == '\0')){
            array[index] = input[i];
            index++;
            continue;
        }
        else{
            delete[] array;
            throw Error();
        }
    }
    return (array); 
}

void start(int argv, char **argc){
    if (argv < 2 || argv > 2)
        throw Error();
    std::string input = argc[1];
    int size = 0;
    std::string *array = split(input, size);
    std::cout << RPN(array, (unsigned int)size) << std::endl;
}