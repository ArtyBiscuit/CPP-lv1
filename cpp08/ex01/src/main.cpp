# include "Span.hpp"

int main(){


    try{
		Span sp = Span(10);
		sp.addNumber(1);
		sp.addNumber(5);
		sp.addNumber(66);
		sp.addNumber(89);
		sp.addNumber(3);
		sp.addNumber(25);
		sp.addNumber(10);
		sp.addNumber(-20);
		sp.addNumber(31);
		sp.addNumber(8);

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

	try{
		Span sp = Span(10000);

		sp.randomGenerate();

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
		Span sp = Span(10);
		sp.addNumber(8);

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
		Span sp = Span(10);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);
		sp.addNumber(8);

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

	try{
		Span sp = Span(1000000);

		sp.randomGenerate();

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}