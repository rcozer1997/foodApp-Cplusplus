#include "EmailInvalidoException.h"

EmailInvalidoException::EmailInvalidoException()
{
}

EmailInvalidoException::EmailInvalidoException(const string& e)
{
	this->e = e;
}
