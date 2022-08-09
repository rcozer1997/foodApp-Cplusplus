#include "SenhaInvalidaException.h"

namespace foodApp::Exceptions
{

	SenhaInvalidaException::SenhaInvalidaException(const std::wstring &mensagem) : Exception(mensagem)
	{
	}
}
