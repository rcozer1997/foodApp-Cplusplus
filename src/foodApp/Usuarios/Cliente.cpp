#include "Cliente.h"

namespace foodApp::Usuarios
{
	using ArrayList = java::util::ArrayList;
	using Collections = java::util::Collections;
	using Scanner = java::util::Scanner;
	using App = foodApp::App;
	using Sistema = foodApp::Sistema;
	using CodigoNaoEncontradoException = foodApp::Exceptions::CodigoNaoEncontradoException;
	using ComparaLanchonetePontos = foodApp::Lanchonetes::ComparaLanchonetePontos;
	using ComparaLanchonetePrecoMedio = foodApp::Lanchonetes::ComparaLanchonetePrecoMedio;
	using ComparaLanchoneteVendas = foodApp::Lanchonetes::ComparaLanchoneteVendas;
	using Lanche = foodApp::Lanchonetes::Lanche;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;

	Cliente::Cliente(Sistema *sistema) : Usuario(sistema)
	{
		this->ident = 3;
	}

	Cliente::Cliente(std::vector<std::wstring> &list) : Usuario(list)
	{
	}

	void Cliente::menu()
	{
		int opcao;

		do
		{
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"              MENU CLIENTE                      " << std::endl;
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"1) Listar todas as lanchonetes por pontuação" << std::endl;
		std::wcout << L"2) Listar lanchonetes de uma categoriapor pontuação" << std::endl;
		std::wcout << L"3) Listar lanchonetes por preco" << std::endl;
		std::wcout << L"4) Listar lanchonetes pelo numero de vendas" << std::endl;
		std::wcout << L"5) Ver lanches de uma lanchonete" << std::endl;
		std::wcout << L"6) Buscar lanche" << std::endl;
		std::wcout << L"7) Fazer pedido" << std::endl;
		std::wcout << L"8) Remover cadastro" << std::endl;
		std::wcout << L"9) Avaliar Lanchonete" << std::endl;
		std::wcout << L"0) Sair" << std::endl;

		opcao = s->nextInt();
		switch (opcao)
		{
		case 1:
			listarLanchonetesPontuacao();
			break;
		case 2:
			listarPontuacaoCategoria();
			break;
		case 3:
			listarLanchonetesPrecoMedio();
			break;
		case 4:
			listarLanchonetesVendas();
			break;
		case 5:
			try
			{
			verLanchesLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
			break;
		case 6:
			buscarLanche();
			break;
		case 7:
			try
			{
			fazerPedidoLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
			arq->salvaPedidosArq(sistema->getTodosPedidos());
			break;
		case 8:
			removerCadastro(this->getEmail(), sistema->getListaUsuarios());
			App::main(std::vector<std::wstring>());
			break;
		case 9:
			try
			{
			avaliaLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
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

	void Cliente::exibirLanchonetes()
	{
		std::wcout << L"-------------------------------------------------------------------------------------------------------" << std::endl;
		printf(L"%15s%20s%15s%15s%15s", L"CODIGO", L"NOME", L"ENDERECO", L"CATEGORIA", L"PONTOS");
		std::wcout << std::endl;
		std::wcout << L"-------------------------------------------------------------------------------------------------------" << std::endl;
		for (auto l : *sistema->getTodasLanchonetes())
		{
			std::wcout << L"---------------------------------------------------------------------------------------------------" << std::endl;
			System::out::format(L"%15s%20s%15s%15s%15s",l->codigo, l->nome, l->endereco, l->categoria, l->pontos);
			std::wcout << std::endl;
			std::wcout << L"---------------------------------------------------------------------------------------------------" << std::endl;
		}

	}

	Lanchonete *Cliente::buscarLanchonete(int codigo)
	{
		for (auto l : *sistema->getTodasLanchonetes())
		{
			if (l->codigo == codigo)
			{
				return l;
			}
		}
		return nullptr;
	}

	void Cliente::verLanchesLanchonete()
	{
		exibirLanchonetes();
		std::wcout << L"Qual lanchonete gostaria de visualizar?" << std::endl;
		int codigo = s->nextInt();
		Lanchonete *l = buscarLanchonete(codigo);
		if (l == nullptr)
		{
			throw CodigoNaoEncontradoException(L"Codigo invalido!");
		}
		else {
			l.listarLanches();
		}
	}
	}
	
void <missing_class_definition>::listarLanchonetesPontuacao()
{
	ComparaLanchonetePontos *c = new ComparaLanchonetePontos();
	Collections::sort(sistema::getTodasLanchonetes(), c);
	exibirLanchonetes();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
}

void Cliente::listarPontuacaoCategoria()
{
	Scanner *s = new Scanner(System::in);
	std::wcout << L"Categoria das lanchonetes a serem exibidas:";
	std::wstring categoria = s->nextLine();
	std::vector<Lanchonete*> *lanchonetes = std::vector<Lanchonete*>();
	for (Lanchonete *l : sistema::getTodasLanchonetes())
	{
		if (l->categoria.equals(categoria))
		{
			lanchonetes->add(l);
		}
	}
	ComparaLanchonetePontos *c = new ComparaLanchonetePontos();
	Collections::sort(lanchonetes, c);
	std::wcout << L"---------------------------------------------------------" << std::endl;
	printf(L"%15s%20s%15s%15s%15s", L"CODIGO", L"NOME", L"ENDERECO", L"CATEGORIA", L"PONTOS");
	std::wcout << std::endl;
	std::wcout << L"---------------------------------------------------------" << std::endl;
	for (auto l : *lanchonetes)
	{
		std::wcout << L"---------------------------------------------------------" << std::endl;
		System::out::format(L"%15s%20s%15s%15s%15s",l->codigo, l->nome, l->endereco, l->categoria, l->pontos);
		std::wcout << std::endl;
		std::wcout << L"---------------------------------------------------------" << std::endl;
	}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete lanchonetes' statement was not added since lanchonetes was passed to a method or constructor. Handle memory management manually.
	delete s;
}

void Cliente::listarLanchonetesPrecoMedio()
{
	ComparaLanchonetePrecoMedio *c = new ComparaLanchonetePrecoMedio();
	Collections::sort(sistema::getTodasLanchonetes(), c);
	exibirLanchonetes();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
}

void Cliente::listarLanchonetesVendas()
{
	ComparaLanchoneteVendas *c = new ComparaLanchoneteVendas();
	Collections::sort(sistema::getTodasLanchonetes(), c);
	exibirLanchonetes();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
}

void Cliente::buscarLanche()
{
	Scanner *s = new Scanner(System::in);
	std::wcout << L"Digite o lanche que deseja buscar: " << std::endl;
	std::wstring lancheBuscado = s->nextLine();
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	printf(L"%20s%20s%20s%15s", L"NOME", L"LANCHONETE", L"COD. LANCHONETE", L"COD. PRODUTO");
	std::wcout << std::endl;
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	for (Lanchonete *l : sistema::getTodasLanchonetes())
	{
		for (Lanche *lanche : *l->getListaLanches())
		{
			if (lanche->getNome()->contains(lancheBuscado))
			{
				std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
				System::out::format(L"%20s%20s%15s%15s",lanche->getNome(), lanche->getNomeLanchonete(), l->getCodigo(), lanche->getCodigo());
				std::wcout << std::endl;
				std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
			}
		}
	}

	delete s;
}

void Cliente::fazerPedidoLanchonete()
{
	exibirLanchonetes();
	std::wcout << L"Codigo da lanchonete a se fazer pedido: " << std::endl;
	int codigo = s::nextInt();
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		throw CodigoNaoEncontradoException("Codigo invalido!");
	}
	else
	{
		l->fazerPedido(this->getNome());
	}
}

void Cliente::avaliaLanchonete()
{
	exibirLanchonetes();
	std::wcout << L"Qual lanchonete deseja avaliar?" << std::endl;
	int codigo = s::nextInt();
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		throw CodigoNaoEncontradoException("Codigo invalido!");
	}
	else
	{
		std::wcout << L"Insira uma nota de 0 a 5: " << std::endl;
		float nota = s::nextFloat();
		if (nota < 0 || nota > 5)
		{
			std::wcout << L"Nota avaliativa invalida! Insira uma nota de 0 a 5!" << std::endl;
		}
		else
		{
			l->atualizaPontos(nota);
			arq::salvaLanchoneteArq(sistema::getTodasLanchonetes());
		}

	}
}
