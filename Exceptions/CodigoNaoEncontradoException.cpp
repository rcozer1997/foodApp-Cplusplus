#include "CodigoNaoEncontradoException.h"

CodigoNaoEncontradoException::CodigoNaoEncontradoException()
{
}

CodigoNaoEncontradoException::CodigoNaoEncontradoException(const string& e)
{
	this->e = e;
}
