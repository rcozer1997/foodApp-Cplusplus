#include "EmailInvalidoException.h"

namespace foodApp::Exceptions
{

	EmailInvalidoException::EmailInvalidoException(const std::wstring &mensagem) : Exception(mensagem)
	{
	}
}
