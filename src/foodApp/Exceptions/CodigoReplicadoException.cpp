#include "CodigoReplicadoException.h"

namespace foodApp::Exceptions
{

	CodigoReplicadoException::CodigoReplicadoException(const std::wstring &mensagem) : Exception(mensagem)
	{
	}
}
