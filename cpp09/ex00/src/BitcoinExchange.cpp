#include "BitcoinExchange.hpp"

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
    else{
        delete[] array;
        regfree(&regex);
        throw BadLine();
    }
    regfree(&regex);
    return (array);
}

std::map<std::string, double> getFileData(std::string path, std::map<std::string, double> &list, std::string rFlag, std::string header){
    std::ifstream fichier(path.c_str());
    
    if (!fichier.is_open())
        throw BadFile();

    size_t nb_line = 0;
    std::string line;
    std::getline(fichier, line);
    if (std::strcmp(line.c_str(), header.c_str())){
        fichier.close();
        throw BadHeader();
    }
    while (std::getline(fichier, line)) {
        std::string *valus = getData(line, rFlag);
        list[valus[0]]=atof(valus[1].c_str());
        delete[] valus;
        ++nb_line;
    }
    fichier.close();
    return (list);
}

std::map<std::string, std::list<double> > getFileInput(std::string path, std::map<std::string, std::list<double> > &list, std::string rFlag, std::string header){
    std::ifstream fichier(path.c_str());
    
    if (!fichier.is_open())
        throw BadFile();

    size_t nb_line = 0;
    std::string line;
    std::getline(fichier, line);
    if (std::strcmp(line.c_str(), header.c_str())){
        fichier.close();
        throw BadHeader();
    }
    while (std::getline(fichier, line)) {
        std::string *valus = getData(line, rFlag);
        list[valus[0]].push_back(atof(valus[1].c_str()));
        delete[] valus;
        ++nb_line;
    }
    fichier.close();
    return (list);
}

bool checkDate(std::string date){
    const char *regex_pattern = "([0-9]{4})-([0-9]{2})-([0-9]{2})";
    regex_t regex;
    regmatch_t matches[3];
    if (regcomp(&regex, regex_pattern, REG_EXTENDED) != 0) {
        std::cerr << "Erreur de compilation de  regex" << std::endl;
        // ERROR
    }
    std::string array[3];
    if (regexec(&regex, date.c_str(), 4, matches, 0) == 0) {
        array[0] = std::string(date.c_str() + matches[1].rm_so, matches[1].rm_eo - matches[0].rm_so).c_str();
        array[1] = std::string(date.c_str() + matches[2].rm_so, matches[2].rm_eo - matches[1].rm_so).c_str();
        array[2] = std::string(date.c_str() + matches[3].rm_so, matches[3].rm_eo - matches[2].rm_so).c_str();
    }
    else{
        regfree(&regex);
        throw BadLine();
    }
    regfree(&regex);
    int year = atof(array[0].c_str());
    int month = atof(array[1].c_str());
	int day = atof(array[2].c_str());
    int	bis = 0;
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 == 0)
			bis = 1;
		if (year % 100 != 0)
			bis = 1;
    }
    if (month < 1 || month > 12)
		return (1);
	if (day < 1 || day > 31)
		return (1);
	if (day == 31) {
		if (month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12)
			return (1);
	}
	if (day == 29 && month == 2) {
		if (bis != 1)
			return (1);
	}
    return (0);
}


double searchDate(std::map<std::string, double> &current_date, std::string date){
    std::map<std::string, double>::iterator it = current_date.find(date);
    if (checkDate(date))
        throw invalidDate();
    if(it != current_date.end())
        return (it->second);
    it = current_date.lower_bound(date);
    if(it != current_date.end())
        return (it->second);
    return (-1);
}

void bitcoinExchange(int argv, char **argc){
    if (argv < 2 || argv > 2)
        throw BadInput();
    std::string input_path = argc[1];
    std::map<std::string, double> BDD;
    std::map<std::string, std::list<double> > Input;
    getFileData("./data.csv", BDD, "^([0-9]{4}-[0-9]{2}-[0-9]{2}),(-?[0-9]+(\\.[0-9]+)?)$", "date,exchange_rate");
    getFileInput(input_path, Input, "^([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| (-?[0-9]+(\\.[0-9]+)?)$", "date | value");
    
    for(std::map<std::string, std::list<double> >::iterator it = Input.begin(); it != Input.end(); it++){
        double btc_value = searchDate(BDD, it->first);
        std::list<double> &values = Input[it->first];
        long unsigned int values_size = values.size();
        for(long unsigned int i = 0; i < values_size; i++){
            double wallet = values.front();
            values.pop_front();

            if(wallet < 0 || wallet > 1000)
                throw badWallet();
            std::cout << it->first << " | " << "Wallet value: " << wallet << " | BTC value: " << btc_value << " = " << wallet * btc_value << std::endl;
        }
    }
}