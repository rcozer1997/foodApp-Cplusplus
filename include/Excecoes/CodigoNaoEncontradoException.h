#ifndef CODIGONAOENCONTRADOEXCEPTION_H_
#define CODIGONAOENCONTRADOEXCEPTION_H_

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*class CodigoNaoEncontradoException : public runtime_error
{
public:
	//CodigoNaoEncontradoException();
	//virtual ~CodigoNaoEncontradoException();
	CodigoNaoEncontradoException(const string &mensagem);
};*/

class CodigoNaoEncontradoException
{
	string e;
public:
	CodigoNaoEncontradoException();
	CodigoNaoEncontradoException(const string& e);
};

#endif
