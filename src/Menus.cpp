#include "../include/Menus.h"

using namespace std;

Menus::~Menus()
{
}

void Menus::MenuPrincipal()
{
	wcout << "------------------------------------------------" << endl;
	wcout << "              MENU PRINCIPAL                    " << endl;
	wcout << "------------------------------------------------" << endl;
	wcout << "O que deseja fazer?" << endl;
	wcout << "1 - Cadastro" << endl;
	wcout << "2 - Login" << endl;
	wcout << "0 - Sair" << endl;
}

void Menus::printaPerfisUsuarios()
{
	wcout << "1 - Administrador" << endl;
	wcout << "2 - Proprietario" << endl;
	wcout << "3 - Cliente" << endl;
	wcout << "0 - Voltar" << endl;
}
