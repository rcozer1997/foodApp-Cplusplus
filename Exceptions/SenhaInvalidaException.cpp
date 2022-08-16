#include "SenhaInvalidaException.h"

SenhaInvalidaException::SenhaInvalidaException()
{
}

SenhaInvalidaException::SenhaInvalidaException(const string& e)
{
	this->e = e;
}
