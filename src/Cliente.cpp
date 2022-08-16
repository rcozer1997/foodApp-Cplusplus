#include "../include/Cliente.h"
#include <string.h>

using namespace std;

Cliente::Cliente(Sistema *sistema) : Usuario(sistema)
{
	this->ident = 3;
}

Cliente::Cliente(vector<string> &list) : Usuario(list)
{
}

void Cliente::menu()
{
	int opcao;
	do
	{
		wcout << "------------------------------------------------" << endl;
		wcout << "              MENU CLIENTE                      " << endl;
		wcout << "------------------------------------------------" << endl;
		wcout << "1) Listar todas as lanchonetes por pontuação" << endl;
		wcout << "2) Listar lanchonetes de uma categoriapor pontuação" << endl;
		wcout << "3) Listar lanchonetes por preco" << endl;
		wcout << "4) Listar lanchonetes pelo numero de vendas" << endl;
		wcout << "5) Ver lanches de uma lanchonete" << endl;
		wcout << "6) Buscar lanche" << endl;
		wcout << "7) Fazer pedido" << endl;
		wcout << "8) Remover cadastro" << endl;
		wcout << "9) Avaliar Lanchonete" << endl;
		wcout << "0) Sair" << endl;

		cin >> opcao;

		switch(opcao)
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
				wcout << "Exceptions occurred" << endl;
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
			catch(const CodigoNaoEncontradoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
			arq->salvaPedidosArq(sistema->todosPedidos);
			break;
		case 8:
			removerCadastro(this->getEmail(), sistema->listaUsuarios);
			//App::main(vector<string>());
			break;
		case 9:
			try
			{
				avaliaLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
			break;
		default:
			if(opcao == 0)
			{
				wcout << "" << endl;
			}
			else
			{
				wcout << "Opcao invalida! Tente novamente." << endl;
			}
			break;
		}

	}while(opcao != 0);
}

void Cliente::exibirLanchonetes()
{
	wcout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "CODIGO " << "NOME " << "ENDERECO " << "CATEGORIA " << "PONTOS" << endl;
	wcout << endl;
	wcout << "-------------------------------------------------------------------------------------------------------" << endl;
	for(auto l : sistema->getTodasLanchonetes())
	{
		wcout << "---------------------------------------------------------------------------------------------------" << endl;
		cout << l->codigo << " " << l->nome << " " << l->endereco << " " << l->categoria << " " << l->pontos << endl;
		wcout << endl;
		wcout << "---------------------------------------------------------------------------------------------------" << endl;
	}

}

Lanchonete *Cliente::buscarLanchonete(int codigo)
{
	for (auto l : sistema->getTodasLanchonetes())
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
	wcout << "Qual lanchonete gostaria de visualizar?" << endl;
	//int codigo = s->nextInt();
	int codigo;
	cin >> codigo;
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		throw CodigoNaoEncontradoException("Codigo invalido!");
	}
	else {
		l->listarLanches();
	}
}

/*
void Cliente::listarLanchonetesPontuacao()
{
	ComparaLanchonetePontos *c = new ComparaLanchonetePontos();
	Collections::sort(sistema::getTodasLanchonetes(), c);
	exibirLanchonetes();
}
*/


/* void Cliente::listarPontuacaoCategoria()
{
	//Scanner *s = new Scanner(System::in);
	wcout << "Categoria das lanchonetes a serem exibidas:";
	//string categoria = s->nextLine();
	string categoria;
	cin >> categoria;
	vector<Lanchonete*> *lanchonetes = vector<Lanchonete*>();
	for(Lanchonete *l : sistema->getTodasLanchoentes())
	{
		/*int c = l->categoria.compare(categoria);
		if(c == 0)
		if(l->categoria == categoria)
		{
			lanchonetes->push_back(l);
		}
		if(strcmp(l->categoria, categoria) == 0)
			lanchonetes->push_back(l);
		if (l->categoria.equals(categoria))
			lanchonetes->push_back(l);
	}
	ComparaLanchonetePontos *c = new ComparaLanchonetePontos();
	Collections::sort(lanchonetes, c);
	wcout << "---------------------------------------------------------" << endl;
	cout << "CODIGO " << "NOME " << "ENDERECO " << "CATEGORIA " << "PONTOS" << endl;
	wcout << endl;
	wcout << "---------------------------------------------------------" << endl;
	for (auto l : *lanchonetes)
	{
		wcout << "---------------------------------------------------------" << endl;
		cout << l->codigo << l->nome << l->endereco << l->categoria << l->pontos << endl;
		wcout << endl;
		wcout << "---------------------------------------------------------" << endl;
	}
	//delete s;
}
*/
/*
void Cliente::listarLanchonetesPrecoMedio()
{
	ComparaLanchonetePrecoMedio *c = new ComparaLanchonetePrecoMedio();
	Collections::sort(sistema->getTodasLanchonetes(), c);
	exibirLanchonetes();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
}

void Cliente::listarLanchonetesVendas()
{
	ComparaLanchoneteVendas *c = new ComparaLanchoneteVendas();
	Collections::sort(sistema->getTodasLanchonetes(), c);
	exibirLanchonetes();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
}
*/

void Cliente::buscarLanche()
{
	//Scanner *s = new Scanner(System::in);
	wcout << "Digite o lanche que deseja buscar: " << endl;
	//string lancheBuscado = s->nextLine();
	string lancheBuscado;
	cin >> lancheBuscado;
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "NOME " << "LANCHONETE " << "COD. LANCHONETE " << "COD. PRODUTO" << endl;
	wcout << endl;
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	for (Lanchonete *l : sistema->getTodasLanchonetes())
	{
		for (Lanche *lanche : l->getListaLanches())
		{	//u->getEmail().compare(email) == 0
			if (lanche->getNome().compare(lancheBuscado) == 0)
			{
				wcout << "-----------------------------------------------------------------------------------------------------" << endl;
				cout << lanche->getNome() << lanche->getNomeLanchonete() << l->getCodigo() << lanche->getCodigo() << endl;
				wcout << "-----------------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
	//delete s;
}

void Cliente::fazerPedidoLanchonete()
{
	exibirLanchonetes();
	wcout << "Codigo da lanchonete a se fazer pedido: " << endl;
	//int codigo = s::nextInt();
	int codigo;
	cin >> codigo;
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
	wcout << "Qual lanchonete deseja avaliar?" << endl;
	//int codigo = s::nextInt();
	int codigo;
	cin >> codigo;
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		throw CodigoNaoEncontradoException("Codigo invalido!");
	}
	else
	{
		wcout << "Insira uma nota de 0 a 5: " << endl;
		//float nota = s::nextFloat();
		float nota;
		cin >> nota;
		if (nota < 0 || nota > 5)
		{
			wcout << "Nota avaliativa invalida! Insira uma nota de 0 a 5!" << endl;
		}
		else
		{
			l->atualizaPontos(nota);
			arq->salvaLanchoneteArq(sistema->todasLanchonetes);
		}

	}
}
