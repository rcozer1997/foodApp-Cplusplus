#ifndef SENHAINVALIDAEXCEPTION_H_
#define SENHAINVALIDAEXCEPTION_H_

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class SenhaInvalidaException
{
	string e;
public:
	SenhaInvalidaException();
	SenhaInvalidaException(const string& e);
};

#endif
