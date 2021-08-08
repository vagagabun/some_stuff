#include <iostream>
#include "Hash.h"
using std::cin;
using std::cout;
using std::endl;


int main()
{
	ControlQuestion C("a","b");
	Hash h("Ivan","qwerty123", C);
	h.enter("Ivan","qwerty123");
	h.show();
	ControlQuestion Ca("b","a");
	h.recover("newpass",Ca);
	//h.recover("newpass",C);
	h.show();


	//system("pause");
	return 0;
}
