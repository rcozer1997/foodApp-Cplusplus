#include "Proprietario.h"

namespace foodApp::Usuarios
{
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using App = foodApp::App;
	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;
	using CodigoNaoEncontradoException = foodApp::Exceptions::CodigoNaoEncontradoException;
	using CodigoReplicadoException = foodApp::Exceptions::CodigoReplicadoException;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;
	using Pedidos = foodApp::Lanchonetes::Pedidos;

	Proprietario::Proprietario(Sistema *sistema) : Usuario(sistema)
	{
		this->ident = 2;
	}

	Proprietario::Proprietario(std::vector<std::wstring> &list) : Usuario(list)
	{
	}

	void Proprietario::menu()
	{
		lerLanchonetesProp(); //Esse metodo le todas as lanchonetes do sistema e insere as lanchonetes do proprietario em sua lista, checando o email do proprietario
		int opcao;
		do
		{
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"              MENU PROPRIETARIO                 " << std::endl;
		std::wcout << L"------------------------------------------------" << std::endl;
		std::wcout << L"1) Cadastrar Lanchonete" << std::endl;
		std::wcout << L"2) Remover Lanchonete" << std::endl;
		std::wcout << L"3) Cadastrar Lanche" << std::endl;
		std::wcout << L"4) Visualizar lista de pedidos de uma lanchonete" << std::endl;
		std::wcout << L"5) Visualizar um pedido de uma lanchonete - nao funciona" << std::endl;
		std::wcout << L"6) Remover pedido" << std::endl;
		std::wcout << L"7) Remover cadastro" << std::endl;
		std::wcout << L"0) Sair" << std::endl;

		opcao = s->nextInt();
		switch (opcao)
		{
		case 1:
			try
			{
				cadastraLanchonete();
				arq->salvaLanchoneteArq(sistema->getTodasLanchonetes());
			}
			catch (const CodigoReplicadoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
			break;
		case 2:
			removeLanchonete();
			arq->salvaLanchoneteArq(sistema->getTodasLanchonetes());
			break;
		case 3:
			cadastraLancheLanchonete();
			arq->salvaLanchesArq(sistema->getTodosLanches());
			break;
		case 4:
			try
			{
			visualizarPedidosLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
			break;
		/*case 5:
			break;*/
		case 6:
			try
			{
			removePedido();
			arq->salvaPedidosArq(sistema->getTodosPedidos());
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				std::wcout << e->what() << std::endl;
			}
			break;
		case 7:
			this->removerCadastro(this->getEmail(), sistema->getListaUsuarios()); //Ao remover o cadastro, todas as lanchonetes do proprietario, bem como os pedidos e lanches, sao removidos
			App::main(std::vector<std::wstring>());
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

	void Proprietario::cadastraLanchonete()
	{
		std::wcout << L"Informe os dados da lanchonete a ser cadastrada: " << std::endl;
		std::wcout << L"Codigo identificador: " << std::endl;
		int codigo = s->nextInt();
		s->nextLine();
		std::wcout << L"Nome: " << std::endl;
		std::wstring nome = s->nextLine();
		std::wcout << L"Endereço: " << std::endl;
		std::wstring endereco = s->nextLine();
		std::wcout << L"Categoria de produtos: " << std::endl;
		std::wstring categoria = s->nextLine();

		if (codigo == 0)
		{
			std::wcout << L"Zero nao eh um codigo valido!" << std::endl;
		}
		if (sistema->verificaExistenciaLanchonete(codigo))
		{
			//verifica existencia da lanchonete na lista onde tem todas as lanchonetes do sistema
			Lanchonete *l = new Lanchonete(codigo,nome,endereco,categoria, this->getNome(), this->getEmail());
			lanchonetes.push_back(l); //adiciona lanchonete no arraylist do proprietario
			sistema->getTodasLanchonetes().push_back(l); //adiciona na lista, em Sistema, de todas as lanchonetes

//JAVA TO C++ CONVERTER TODO TASK: A 'delete l' statement was not added since l was passed to a method or constructor. Handle memory management manually.
		}
		else if (!sistema->verificaExistenciaLanchonete(codigo))
		{
			throw CodigoReplicadoException(L"Codigo ja cadastrado!");
		}
	}

	void Proprietario::removeLanchonete()
	{
		listaLanchonetesProprietario();
		int codigo = s->nextInt();
		Lanchonete *l = buscarLanchonete(codigo);
		if (l == nullptr)
		{
			std::wcout << L"Codigo invalido!" << std::endl;
		}
		else if (verificaProprietario(l))
		{
			l->removeTodosLanches();
			l->removeTodosPedidos();
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
			sistema->getTodasLanchonetes().remove(l);
		}
		arq->salvaLanchoneteArq(sistema->getTodasLanchonetes());
		arq->salvaLanchesArq(sistema->getTodosLanches());
		arq.salvaPedidosArq(sistema.getTodosPedidos());
	}
	}

	void Proprietario::lerLanchonetesProp()
{
	for (Lanchonete *l : sistema::getTodasLanchonetes())
	{
		if (l->getProprietarioEmail().equals(this->getEmail()))
		{
			this->lanchonetes->add(l);
		}
	}
}

void Proprietario::removerLanchonetesProprietario()
{
		 for (Lanchonete *doProprietario : this->lanchonetes)
		 {
			 for (int i = 0; i < sistema::getTodasLanchonetes()->size(); i++)
			 {
				 Lanchonete *l = sistema::getTodasLanchonetes()->get(i);
				 if (l->getCodigo() == doProprietario->getCodigo())
				 {
					 l->removeTodosLanches();
					 l->removeTodosPedidos();
					 sistema::getTodasLanchonetes()->remove(l);
				 }
			 }
		 }
	arq::salvaLanchoneteArq(sistema::getTodasLanchonetes());
	arq::salvaLanchesArq(sistema::getTodosLanches());
	arq::salvaPedidosArq(sistema::getTodosPedidos());
}

void Proprietario::exibirLanchonetes(std::vector<Lanchonete*> *lanchonetes)
{
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	printf(L"%15s%20s%15s%15s%15s", L"CODIGO", L"NOME", L"ENDERECO", L"CATEGORIA", L"PONTOS");
	std::wcout << std::endl;
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	for (auto l : *lanchonetes)
	{
		if (l->getProprietarioNome().equals(this->nome))
		{
			std::wcout << L"---------------------------------------------------------------------------------------------" << std::endl;
		System::out::format(L"%15s%20s%15s%15s%15s",l->codigo, l->nome, l->endereco, l->categoria, l->pontos);
		std::wcout << std::endl;
		std::wcout << L"--------------------------------------------------------------------------------------------------" << std::endl;
		}
	}
}

void Proprietario::cadastraLancheLanchonete()
{
	listaLanchonetesProprietario();
	int codigo = s::nextInt();
	if (codigo == 0)
	{
		std::wcout << L"Zero nao eh um codigo valido!" << std::endl;
	}
	else
	{
		Lanchonete *l = buscarLanchonete(codigo);
		if (l == nullptr)
		{
			std::wcout << L"Codigo invalido!" << std::endl;
		}
		else if (verificaProprietario(l))
		{
			try
			{
				l->cadastraLanche(l);
			}
			catch (const CodigoReplicadoException &e)
			{
				std::wcout << e->getMessage() << std::endl;
			}
		}

	}

}

Lanchonete *Proprietario::buscarLanchonete(int codigo)
{
	for (Lanchonete *l : sistema::getTodasLanchonetes())
	{
		if (l->codigo == codigo)
		{
			return l;
		}
	}
	return nullptr;
}

void Proprietario::visualizarPedidosLanchonete()
{
	listaLanchonetesProprietario();
	int codigo = s::nextInt();
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		throw CodigoNaoEncontradoException("Codigo invalido!");
	}
	else if (verificaProprietario(l))
	{
		l->visualizarPedidos();
	}
}

void Proprietario::removePedido()
{
	listaLanchonetesProprietario();
	int codigo = s::nextInt();
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		std::wcout << L"Codigo invalido!" << std::endl;
	}
	else if (verificaProprietario(l))
	{
		l->visualizarPedidos();
		std::wcout << L"Qual pedido deseja remover?" << std::endl;
		int codigoPedido = s::nextInt();
		Pedidos *p = l->buscarPedido(codigoPedido);
		if (p == nullptr)
		{
			throw CodigoNaoEncontradoException("Codigo invalido!");
		}
		else
		{
			l->removePedido(p);
			//sistema.getTodosPedidos().remove(p);
		}
	}
}

void Proprietario::listaLanchonetesProprietario()
{
	exibirLanchonetes(sistema::getTodasLanchonetes());
	std::wcout << L"Codigo da lanchonete: ";
}

bool Proprietario::verificaProprietario(Lanchonete *l)
{

	if (l->getProprietarioNome().equals(this->nome))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<Lanchonete*> *Proprietario::getLanchonetes()
{
	return this->lanchonetes;
}

void Proprietario::removerCadastro(const std::wstring &email, std::vector<Usuario*> *listaUsuarios)
{
	for (int i = 0; i < listaUsuarios->size();i++)
	{
		Usuario *u = listaUsuarios->get(i);
		if (u->getEmail().equals(email))
		{
			std::wcout << L"Tem certeza que deseja remover o cadastro?" << std::endl;
			std::wcout << L"1 - Sim\n2 - Nao" << std::endl;
			int opcao = s::nextInt();

			if (opcao == 1)
			{
				removerLanchonetesProprietario();
				listaUsuarios->remove(u);
				std::wcout << L"Cliente removido!" << std::endl;
				arq::salvaUsuariosArq(listaUsuarios, L"Usuarios.csv");
				break;
			}
			else if (opcao == 2)
			{
				break;
			}
		}
	}
}
