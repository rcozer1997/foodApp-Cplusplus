#include "Administrador.h"

namespace foodApp::Usuarios
{
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using App = foodApp::App;
	using Sistema = foodApp::Sistema;

	Administrador::Administrador(Sistema *sistema) : Usuario(sistema)
	{
		this->ident = 1;
	}

	Administrador::Administrador(std::vector<std::wstring> &list) : Usuario(list)
	{
	}

	void Administrador::menu()
	{
		int opcao;
		do
		{
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"              MENU ADMIN                        " << std::endl;
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"1) Relatorio geral" << std::endl;
		std::wcout << L"2) Relatorio de vendas - nao funciona" << std::endl;
		std::wcout << L"3) Relatorio de desempenho - nao funciona" << std::endl;
		std::wcout << L"4) Remover cadastro" << std::endl;
		std::wcout << L"0) Sair" << std::endl;

		opcao = s->nextInt();
		switch (opcao)
		{
		case 1:
			relatorioGeral();
			break;
		case 4:
			removerCadastro(this->getEmail(), sistema->getListaUsuarios());
			App::main(std::vector<std::wstring>());
			break;
		case 0:
			break;
		default:
			if (opcao == 0)
			{
				std::wcout << L"" << std::endl;
			}
			else
			{
				std::wcout << L"Opcao invalida! Tente novamente." << std::endl;
			}
			break;
		}
		}while (opcao != 0);
	}

	void Administrador::relatorioGeral()
	{
		int totalClientes = retornaTotalClientes();
		std::wcout << L"Total de Clientes: " << totalClientes << std::endl;
		std::wcout << L"Total de lanchonetes: " << sistema->getTodasLanchonetes().size() << std::endl;
		std::wcout << L"Total de lanches: " << sistema->getTodosLanches().size() << std::endl;
		std::wcout << L"Total de pedidos: " << sistema->getTodosPedidos().size() << std::endl;
	}

	int Administrador::retornaTotalClientes()
	{
		int totalClientes = 0;
			for (auto c : *sistema->getListaUsuarios())
			{
				if (c->getIdent() == 3)
				{
					totalClientes++;
				}
			}
		return totalClientes;
	}
}
