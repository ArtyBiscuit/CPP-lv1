#include "PmergeMe.hpp"

static std::vector<int>::iterator binarySearchVector(std::vector<int> &A, int target) {
    int    mid;
    int    left = 0;
    int    right = (A.size() - 1);

    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] < target)
            left = mid + 1;
        else if (A[mid] > target)
            right = mid - 1;
        else
            return A.begin() + mid;
    }
    return A.begin() + left;
}

std::vector<int> mergeInsertVector(std::vector<int> array){
    if (array.size() <= 1) {
        return array;
    }
    std::vector<std::pair<int, int> > Y;
    std::vector<int> S;
    for(std::vector<int>::iterator it = array.begin(); it !=  array.end(); it += 2){
        if(it+1 == array.end())
            break;
        std::pair<int, int> pair;
        pair.first = (*it > *(it + 1)) ? *it : *(it + 1);
        pair.second = (*it < *(it + 1)) ? *it : *(it + 1);
        Y.push_back(pair);
        S.push_back(pair.first);
    }
    S = mergeInsertVector(S);
    for (std::vector<std::pair<int, int> >::iterator it = Y.begin(); it != Y.end(); ) {
        if (it->first == S.front()) {
            S.insert(S.begin(), it->second);
            it = Y.erase(it);
        }
        else
            ++it;
    }
    for (std::vector<std::pair<int, int> >::iterator it = Y.begin(); it != Y.end(); it++)
        S.insert(binarySearchVector(S, it->second), it->second);
    if (array.size() % 2)
        S.insert(binarySearchVector(S, array.back()), array.back());
    return (S);
}

void printVector(const std::vector<int> &vec, std::string flag) {
    std::cout << flag;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static std::deque<int>::iterator binarySearchDeque(std::deque<int> &A, int target) {
    int    mid;
    int    left = 0;
    int    right = (A.size() - 1);

    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] < target)
            left = mid + 1;
        else if (A[mid] > target)
            right = mid - 1;
        else
            return A.begin() + mid;
    }
    return A.begin() + left;
}

std::deque<int> mergeInsertDeque(std::deque<int> array){
    if (array.size() <= 1) {
        return array;
    }
    std::deque<std::pair<int, int> > Y;
    std::deque<int> S;
    for(std::deque<int>::iterator it = array.begin(); it !=  array.end(); it += 2){
        if(it+1 == array.end())
            break;
        std::pair<int, int> pair;
        pair.first = (*it > *(it + 1)) ? *it : *(it + 1);
        pair.second = (*it < *(it + 1)) ? *it : *(it + 1);
        Y.push_back(pair);
        S.push_back(pair.first);
    }
    S = mergeInsertDeque(S);
    for (std::deque<std::pair<int, int> >::iterator it = Y.begin(); it != Y.end(); ) {
        if (it->first == S.front()) {
            S.insert(S.begin(), it->second);
            it = Y.erase(it);
        }
        else
            ++it;
    }
    for (std::deque<std::pair<int, int> >::iterator it = Y.begin(); it != Y.end(); it++)
        S.insert(binarySearchDeque(S, it->second), it->second);
    if (array.size() % 2)
        S.insert(binarySearchDeque(S, array.back()), array.back());
    return (S);
}

void printDeque(const std::deque<int> &vec, std::string flag) {
    std::cout << flag;
    for (std::deque<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}