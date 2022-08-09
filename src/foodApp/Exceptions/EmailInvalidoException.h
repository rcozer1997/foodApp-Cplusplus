#pragma once

#include <string>
#include <stdexcept>

namespace foodApp::Exceptions
{

	class EmailInvalidoException : public std::runtime_error
	{

	public:
		EmailInvalidoException(const std::wstring &mensagem);
	};

}
