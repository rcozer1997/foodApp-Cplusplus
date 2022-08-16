#include "../include/Administrador.h"

using namespace std;

Administrador::Administrador(Sistema *sistema) : Usuario(sistema)
{
	this->ident;
}

Administrador::Administrador(vector<string> &list) : Usuario(list)
{
}

void Administrador::menu()
{
	int opcao;
	do
	{
		wcout << "------------------------------------------------" << endl;
		wcout << "              MENU ADMIN                        " << endl;
		wcout << "------------------------------------------------" << endl;
		wcout << "1) Relatorio geral" << endl;
		wcout << "2) Relatorio de vendas - nao funciona" << endl;
		wcout << "3) Relatorio de desempenho - nao funciona" << endl;
		wcout << "4) Remover cadastro" << endl;
		wcout << "0) Sair" << endl;

		//opcao = s->nextInt();
		cin >> opcao;
		switch (opcao)
		{
		case 1:
			relatorioGeral();
			break;
		case 4:
			removerCadastro(this->getEmail(), sistema->listaUsuarios);
			break;
		case 0:
			break;
		default:
			if (opcao == 0)
			{
				wcout << "" << endl;
			}
			else
			{
				wcout << "Opcao invalida! Tente novamente." << endl;
			}
			break;
		}
	}while (opcao != 0);
}

void Administrador::relatorioGeral()
{
	int totalClientes = retornaTotalClientes();
	wcout << "Total de Clientes: " << totalClientes << endl;
	wcout << "Total de lanchonetes: " << sistema->getTodasLanchonetes().size() << endl;
	wcout << "Total de lanches: " << sistema->getTodosLanches().size() << endl;
	wcout << "Total de pedidos: " << sistema->getTodosPedidos().size() << endl;
}

int Administrador::retornaTotalClientes()
{
	int totalClientes = 0;
		for (auto c : sistema->getListaUsuarios())
		{
			if (c->getIdent() == 3)
			{
				totalClientes++;
			}
		}
	return totalClientes;
}
