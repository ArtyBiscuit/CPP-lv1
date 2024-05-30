
// Développez un modèle de classe Array qui contient des éléments de type T et qui implémente les comportement et les fonctions suivants :
// - Construction sans paramètre : Crée un tableau vide.
// - Construction avec un int non signé n comme paramètre : Crée un tableau de n éléments initialisé par défaut.

// Astuce : Essayez de compiler int * a = new int() ; puis affichez *a.

// - Construction par copie et opérateur d'affectation. Dans les deux cas, la modification du tableau original ou de sa copie après la copie ne doit pas affecter l'autre tableau.
// - Vous DEVEZ utiliser l'opérateur new[] pour allouer de la mémoire. L'allocation préventive (allouer de la mémoire à l'avance) est interdite. Votre programme ne doit jamais accéder à de la mémoire non allouée.
// - Les éléments peuvent être accédés par l'opérateur d'indice : [ ].
// - Lors de l'accès à un élément avec l'opérateur [ ], si son index est hors limites, une std::exception est levée.
// - Une fonction membre size() qui renvoie le nombre d'éléments du tableau. Cette fonction membre ne prend aucun paramètre et ne doit pas modifier l'instance courante.

// Comme d'habitude, assurez-vous que tout fonctionne comme prévu et fournissez un fichier main.cpp contenant vos tests.

#include "Array.hpp"

int main(void){

	try{
		std::cout << "\tTest 1." << std::endl;
		Array<int> empty_array;
		std::cout << empty_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try{
		std::cout << "\tTest 2." << std::endl;
		Array<int> array(3);
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;
		std::cout << array[3] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try{
		std::cout << "\tTest 3." << std::endl;
		Array<int> array(3);
		array[0] = 26;
		array[1] = 51;
		array[2] = 42;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try{
		std::cout << "\tTest 3." << std::endl;
		Array<int> array(3);
		array[0] = 26;
		array[1] = 51;
		array[2] = 42;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

		Array<int> array_tmp;
		array_tmp = array;
		std::cout << array_tmp[0] << std::endl;
		std::cout << array_tmp[1] << std::endl;
		std::cout << array_tmp[2] << std::endl;
		array_tmp[1] = 186;
		std::cout << array_tmp[0] << std::endl;
		std::cout << array_tmp[1] << std::endl;
		std::cout << array_tmp[2] << std::endl;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return 0;
}