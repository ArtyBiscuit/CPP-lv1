#include <vector>
#include <iostream>

void insert(std::vector<int> &sorted_list, int value) {
    std::vector<int>::iterator it = sorted_list.begin();
    while (it != sorted_list.end() && *it < value) {
        ++it;
    }
    sorted_list.insert(it, value);
}

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right) {
    std::vector<int> result;
    std::vector<int>::const_iterator it_left = left.begin();
    std::vector<int>::const_iterator it_right = right.begin();
    
    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }
    
    while (it_left != left.end()) {
        result.push_back(*it_left);
        ++it_left;
    }
    
    while (it_right != right.end()) {
        result.push_back(*it_right);
        ++it_right;
    }
    
    return result;
}

std::vector<int> mergeInsert(std::vector<int> array){
    if (array.size() <= 1) {
        return array;
    }

    std::vector<int> left(array.begin(), array.begin() + array.size() / 2);
    std::vector<int> right(array.begin() + array.size() / 2, array.end());
    left = mergeInsert(left);
    right = mergeInsert(right);

    std::vector<int> sorted_array = merge(left, right);
    return (sorted_array);
}

void printVector(const std::vector<int> &vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    int arr[] = {1, 5, 3, 4, 55, 4, 789, 11, 12, 20, 58};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> sorted_arr = mergeInsert(vec);

    std::cout << "Tableau\t\t: ";
    printVector(vec);

    std::cout << "Tableau trie\t: ";
    printVector(sorted_arr);

    return 0;
}

/*
0. User Input
    | 28 21 83 18 43 20 60 86 69 56 52 23 32 49 | <-

1. Regrouper les éléments de X[n/2] paires d'éléments, en laissant un élément non apparié s'il y a un nombre impair d'éléments.
    
    | 28 | 83 | 43 | 60 | 69 | 52 | 32 |
    | 21 | 18 | 20 | 86 | 56 | 23 | 49 |

2. Effectuer [n/2] des comparaisons, une par paire, pour déterminer le plus grand des deux éléments dans chaque paire.

    | 21 | 18 | 20 | 60 | 56 | 23 | 32 | <-
    | 28 | 83 | 48 | 86 | 69 | 52 | 49 |

3. Trier de façon récursive les [n/2] plus grands éléments de chaque paire, en créant une séquence triée S des [n/2] éléments d'entrée, dans l'ordre croissant.

    | 60 | 56 | 32 | 23 | 21 | 20 | 18 |
    | 86 | 69 | 49 | 52 | 28 | 48 | 83 | <-

Utiliser la recherche binaire dans les sous-séquences de 'S' pour déterminer la position à laquelle chaque élément doit être inséré.

    | 86 83 69 60 56 52 49 48 32 28 23 21 20 1 8 |

Penser à swap toute la liste à la fin.
*/