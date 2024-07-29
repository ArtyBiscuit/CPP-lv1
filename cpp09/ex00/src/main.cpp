#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string *getValusOfLine(std::string line){
    const char *regex_pattern = "([0-9]{4})-([0-9]{2})-([0-9]{2}) \\| (-?[0-9]+(\\.[0-9]+)?)";
    regex_t regex; // Structure regex
    regmatch_t matches[6];
    if (regcomp(&regex, regex_pattern, REG_EXTENDED) != 0) { // Compilation et vérification de regex
        std::cerr << "Erreur de compilation de  regex" << std::endl;
        return; //ERROR
    }
    std::string array[4];
    if (regexec(&regex, line.c_str(), 6, matches, 0) == 0) { // Recherche de correspondance
        array[0] = (line.c_str() + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so); // l'année
        array[1] = (line.c_str() + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so); // le mois
        array[2] = (line.c_str() + matches[3].rm_so, matches[3].rm_eo - matches[3].rm_so); // le jour
        array[3] = (line.c_str() + matches[4].rm_so, matches[4].rm_eo - matches[4].rm_so); // la valeur
    }
    else
        std::cout << "Aucune correspondance trouvée." << std::endl; //ERROR
    regfree(&regex); // Libérer la mémoire allouée de regex
    return (array);
}

std::string **getFileData(std::string path){
    // Ouvrir le fichier en mode lecture
    std::ifstream fichier(path);
    
    // Vérifier si le fichier a été ouvert correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier : " << path << std::endl;
        return; //ERROR
    }

    std::string ligne;
    size_t nb_line = 0;
    while (std::getline(fichier, ligne)) {
        ++nb_line;
    }

    // Revenir au début du fichier pour lire les lignes
    fichier.clear();  // Clear the EOF flag
    fichier.seekg(0, std::ios::beg);

    // Allouer de la mémoire pour les lignes
    std::string **lignes = new std::string*[nb_line];

    // Lire les lignes et les stocker dans le tableau dynamique
    size_t index = 0;
    while (std::getline(fichier, ligne)) {
        lignes[index] = new std::string(ligne);
        ++index;
    }
    // Fermer le fichier
    fichier.close();
    return (lignes);
}

int main() {

    return 0;
}