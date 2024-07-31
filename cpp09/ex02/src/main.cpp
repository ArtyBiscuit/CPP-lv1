#include "PmergeMe.hpp"

static bool    checkNumbers(char **argv) {
    for (int i = 1; argv[i]; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!isdigit(argv[i][j]))
                return (false);
        }
        if (std::atoi(argv[i]) < 0)
            return (false);
    }
    return (true);
}

int main(int argc, char **argv) {
    if (argc < 2)
        throw BadInput();
    try {
        std::deque<int>        deque;
        std::vector<int>    vector;
        double                vectorTime, dequeTime;
        clock_t                mainStart, vectorEnd, dequeEnd;

        if (!checkNumbers(argv))
            throw BadInput();
        for (int i = 1; argv[i]; i++)
            vector.push_back(std::atoi(argv[i]));
        for (int i = 1; argv[i]; i++)
            deque.push_back(std::atoi(argv[i]));
        printVector(vector, "Before:\t");
        mainStart = clock();
        vector = mergeInsertVector(vector);
        vectorEnd = clock();
        deque = mergeInsertDeque(deque);
        dequeEnd = clock();
        printVector(vector, "After:\t");
        vectorTime = (vectorEnd - mainStart) / (double) CLOCKS_PER_SEC * 1000000.0;
        dequeTime = (dequeEnd - vectorEnd) / (double) CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << std::flush;
        std::cout << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << std::flush;
        std::cout << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
    }
    catch(std::exception &exep) {
        std::cerr << exep.what() << std::endl;
    }
    return (0);
}

/*
    | 28 21 83 18 43 20 60 86 69 56 52 23 32 49 | <-

    
    | 28 | 83 | 43 | 60 | 69 | 52 | 32 |
    | 21 | 18 | 20 | 86 | 56 | 23 | 49 |

    | 21 | 18 | 20 | 60 | 56 | 23 | 32 | <-
    | 28 | 83 | 48 | 86 | 69 | 52 | 49 |

    | 60 | 56 | 32 | 23 | 21 | 20 | 18 |
    | 86 | 69 | 49 | 52 | 28 | 48 | 83 | <-

    | 86 83 69 60 56 52 49 48 32 28 23 21 20 1 8 |
*/