#pragma once

#include <string>
#include <stdexcept>

namespace foodApp::Exceptions
{

	class CodigoNaoEncontradoException : public std::runtime_error
	{
	public:
		CodigoNaoEncontradoException(const std::wstring &mensagem);
	};

}
