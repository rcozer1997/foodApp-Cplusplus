#pragma once

#include "../App.h"
#include "../Sistema.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>

namespace foodApp::Usuarios
{

	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;

	using Sistema = foodApp::Sistema;

	class Administrador : public Usuario
	{
	public:
		Scanner *s = new Scanner(System::in);

		virtual ~Administrador()
		{
			delete s;
		}

		Administrador(Sistema *sistema);

		Administrador(std::vector<std::wstring> &list);

		void menu() override;

		virtual void relatorioGeral();

		virtual int retornaTotalClientes();
	};

}
