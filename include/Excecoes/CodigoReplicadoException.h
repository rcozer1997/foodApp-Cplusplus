#ifndef CODIGOREPLICADOEXCEPTION_H_
#define CODIGOREPLICADOEXCEPTION_H_

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class CodigoReplicadoException
{
	string e;
public:
	CodigoReplicadoException();
	CodigoReplicadoException(const string& e);
};

#endif
