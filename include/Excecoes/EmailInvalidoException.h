#ifndef EMAILINVALIDOEXCEPTION_H_
#define EMAILINVALIDOEXCEPTION_H_

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class EmailInvalidoException
{
	string e;
public:
	EmailInvalidoException();
	EmailInvalidoException(const string& e);
};

#endif
