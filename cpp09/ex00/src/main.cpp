#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

std::string *getData(std::string line, std::string rFlag){
    const char *regex_pattern = rFlag.c_str();
    regex_t regex;
    regmatch_t matches[3];
    if (regcomp(&regex, regex_pattern, REG_EXTENDED) != 0) {
        std::cerr << "Erreur de compilation de  regex" << std::endl;
        // ERROR
    }
    std::string *array = new std::string[2];
    if (regexec(&regex, line.c_str(), 3, matches, 0) == 0) {
        array[0] = std::string(line.c_str() + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so).c_str();
        array[1] = std::string(line.c_str() + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so).c_str();
    }
    else
        std::cout << "Aucune correspondance trouvée." << std::endl; //ERROR
    regfree(&regex);
    return (array);
}

std::map<std::string, double> getFileData(std::string path, std::map<std::string, double> &list, std::string rFlag){
    std::ifstream fichier(path.c_str());
    
    if (!fichier.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier : " << path << std::endl;
        // return; //ERROR
    }

    size_t nb_line = 0;
    std::string line;
    while (std::getline(fichier, line)) {
        std::string *valus = getData(line, rFlag);
        // std::cout << valus[0] << std::endl;
        list[valus[0]]=atof(valus[1].c_str());
        // delete valus; // Delete !
        ++nb_line;
    }
    fichier.close();
    return (list);
}

double searchDate(std::map<std::string, double> &current_date, std::string date){
    std::map<std::string, double>::iterator it = current_date.find(date);
    if(it != current_date.end())
        return (it->second);
    it = current_date.lower_bound(date);
    if(it != current_date.end())
        return (it->second);
    return (-1);
}

int main() {
    std::map<std::string, double> BDD;
    std::map<std::string, double> Input;
    getFileData("./data.csv", BDD, "([0-9]{4}-[0-9]{2}-[0-9]{2}),(-?[0-9]+(\\.[0-9]+)?)");
    getFileData("./input.txt", Input, "([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| (-?[0-9]+(\\.[0-9]+)?)");
    std::string date = "2015-11-28";
    
    for(std::map<std::string, double>::iterator it = Input.begin(); it != Input.end(); it++){
        std::cout << searchDate(BDD, it->first) << std::endl;
    }

    return 0;
}