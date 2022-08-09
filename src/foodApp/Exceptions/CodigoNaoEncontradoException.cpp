#include "CodigoNaoEncontradoException.h"

namespace foodApp::Exceptions
{

	CodigoNaoEncontradoException::CodigoNaoEncontradoException(const std::wstring &mensagem) : Exception(mensagem)
	{
	}
}
