#pragma once

#include <string>
#include <stdexcept>

namespace foodApp::Exceptions
{

	class CodigoReplicadoException : public std::runtime_error
	{
	public:
		CodigoReplicadoException(const std::wstring &mensagem);
	};

}
