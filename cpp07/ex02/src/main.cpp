int main(void){
	Base	*MyClass = generate();

	identify(MyClass);
	identify(*MyClass);

	delete MyClass;
	return 0;
}