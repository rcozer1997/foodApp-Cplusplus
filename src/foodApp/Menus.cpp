#include "Menus.h"

namespace foodApp
{

	void Menus::menuPrincipal()
	{
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"              MENU PRINCIPAL                    " << std::endl;
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"O que deseja fazer?" << std::endl;
		std::wcout << L"1 - Cadastro" << std::endl;
		std::wcout << L"2 - Login" << std::endl;
		std::wcout << L"0 - Sair" << std::endl;
	}

	void Menus::printaPerfisUsuarios()
	{
		std::wcout << L"1 - Administrador" << std::endl;
		std::wcout << L"2 - Proprietario" << std::endl;
		std::wcout << L"3 - Cliente" << std::endl;
		std::wcout << L"0 - Voltar" << std::endl;
	}
}
