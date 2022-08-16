#include "CodigoReplicadoException.h"

CodigoReplicadoException::CodigoReplicadoException()
{
}

CodigoReplicadoException::CodigoReplicadoException(const string& e)
{
	this->e = e;
}
