#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

std::string *getValusOfLine(std::string line){
    const char *regex_pattern = "([0-9]{4}-[0-9]{2}-[0-9]{2}),(-?[0-9]+(\\.[0-9]+)?)";
    regex_t regex; // Structure regex
    regmatch_t matches[3];
    if (regcomp(&regex, regex_pattern, REG_EXTENDED) != 0) { // vérification du regex
        std::cerr << "Erreur de compilation de  regex" << std::endl;
        // ERROR
    }
    std::string *array = new std::string[2];
    if (regexec(&regex, line.c_str(), 3, matches, 0) == 0) { // Recherche de correspondance
        array[0] = std::string(line.c_str() + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so).c_str(); // le date
        array[1] = std::string(line.c_str() + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so).c_str(); // la value
        // std::cout << array[0] << "," << array[1] << std::endl;
    }
    else
        std::cout << "Aucune correspondance trouvée." << std::endl; //ERROR
    regfree(&regex); // Libérer la mémoire allouée du regex
    return (array);
}

std::map<std::string, double> getFileData(std::string path, std::map<std::string, double> &list){
    // Ouvrir le fichier en mode lecture
    std::ifstream fichier(path.c_str());
    
    // Vérifier si le fichier a été ouvert correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier : " << path << std::endl;
        // return; //ERROR
    }

    size_t nb_line = 0;
    std::string line;
    while (std::getline(fichier, line)) {
        std::string *valus = getValusOfLine(line);
        std::cout << valus[0] << std::endl;
        list[valus[0]]=atof(valus[1].c_str());
        // delete valus; // Delete !
        ++nb_line;
    }
    // Fermer le fichier
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


int searchValus(std::map<std::string, double> &BDD, std::string date){

    double value = searchDate(BDD, date);
    if (value){
        return (value);
    }
    return (-1);
}

int main() {
    std::map<std::string, double> BDD;
    getFileData("./data.csv", BDD);
    std::string date = "2009-02-19";
    std::cout << searchValus(BDD, date) << std::endl;

    return 0;
}