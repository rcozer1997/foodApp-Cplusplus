#pragma once

#include <string>
#include <stdexcept>

namespace foodApp::Exceptions
{

	class SenhaInvalidaException : public std::runtime_error
	{
	public:
		SenhaInvalidaException(const std::wstring &mensagem);
	};

}
