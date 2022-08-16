#include "../include/Proprietario.h"

using namespace std;

Proprietario::~Proprietario()
{
	delete arq;
	//delete s;
}

Proprietario::Proprietario(Sistema *sistema) : Usuario(sistema)
{
	this->ident = 2;
}

Proprietario::Proprietario(vector<string> &list) : Usuario(list)
{
}

void Proprietario::menu()
{
	lerLanchonetesProp(); //Esse metodo le todas as lanchonetes do sistema e insere as lanchonetes do proprietario em sua lista, checando o email do proprietario
	int opcao;
	do
	{
		wcout << "------------------------------------------------" << endl;
		wcout << "              MENU PROPRIETARIO                 " << endl;
		wcout << "------------------------------------------------" << endl;
		wcout << "1) Cadastrar Lanchonete" << endl;
		wcout << "2) Remover Lanchonete" << endl;
		wcout << "3) Cadastrar Lanche" << endl;
		wcout << "4) Visualizar lista de pedidos de uma lanchonete" << endl;
		wcout << "5) Visualizar um pedido de uma lanchonete - nao funciona" << endl;
		wcout << "6) Remover pedido" << endl;
		wcout << "7) Remover cadastro" << endl;
		wcout << "0) Sair" << endl;

		//opcao = s->nextInt();
		cin >> opcao;
		switch (opcao)
		{
		case 1:
			try
			{
				cadastraLanchonete();
				arq->salvaLanchoneteArq(sistema->todasLanchonetes);
			}
			catch (const CodigoReplicadoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
			break;
		case 2:
			removeLanchonete();
			arq->salvaLanchoneteArq(sistema->todasLanchonetes);
			break;
		case 3:
			cadastraLancheLanchonete();
			arq->salvaLanchesArq(sistema->todosLanches);
			break;
		case 4:
			try
			{
				visualizarPedidosLanchonete();
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
			break;
		/*case 5:
			break;*/
		case 6:
			try
			{
				removePedido();
				arq->salvaPedidosArq(sistema->todosPedidos);
			}
			catch (const CodigoNaoEncontradoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
			break;
		case 7:
			this->removerCadastro(this->getEmail(), sistema->listaUsuarios); //Ao remover o cadastro, todas as lanchonetes do proprietario, bem como os pedidos e lanches, sao removidos
			//App::main(vector<string>());
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

void Proprietario::cadastraLanchonete()
{
	wcout << "Informe os dados da lanchonete a ser cadastrada: " << endl;
	wcout << "Codigo identificador: " << endl;
	int codigo;
	cin >> codigo;
	wcout << "Nome: " << endl;
	string nome;
	cin >> nome;
	wcout << "Endereço: " << endl;
	string endereco;
	cin >> endereco;
	wcout << "Categoria de produtos: " << endl;
	string categoria;
	cin >> categoria;

	if (codigo == 0)
	{
		wcout << "Zero nao eh um codigo valido!" << endl;
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
		throw CodigoReplicadoException("Codigo ja cadastrado!");
	}
}

void Proprietario::removeLanchonete()
{	
	listaLanchonetesProprietario();
	int codigo;
	cin >> codigo;
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		wcout << "Codigo invalido!" << endl;
	}
	else if (verificaProprietario(l))
	{
		l->removeTodosLanches();
		l->removeTodosPedidos();
		for(int i = 0; i < sistema->getTodasLanchonetes().size(); i++){
			for(Lanchonete *lanchonete: sistema->getTodasLanchonetes()){
				if(lanchonete == l){
				
			}
		}
	}

		
		//sistema->getTodasLanchonetes().remove(l);
	}
	arq->salvaLanchoneteArq(sistema->todasLanchonetes);
	arq->salvaLanchesArq(sistema->todosLanches);
	arq->salvaPedidosArq(sistema->todosPedidos);
}

void Proprietario::lerLanchonetesProp()
{
	for (Lanchonete *l : sistema->getTodasLanchonetes())
	{
		if(l->getProprietarioEmail() == this->getEmail())
		{
			this->lanchonetes.push_back(l);
		}
	}
}

void Proprietario::removerLanchonetesProprietario()
{
	 for (Lanchonete *doProprietario : this->lanchonetes)
	 {
		 for (Lanchonete *l : sistema->getTodasLanchonetes())
		 {
			 if (l->getCodigo() == doProprietario->getCodigo())
			 {
				 l->removeTodosLanches();
				 l->removeTodosPedidos();
				 std::remove(sistema->getTodasLanchonetes().begin(), sistema->getTodasLanchonetes().end(), l);
				 //sistema->getTodasLanchonetes()->remove(l);
			 }
		 }
	 }
	arq->salvaLanchoneteArq(sistema->todasLanchonetes);
	arq->salvaLanchesArq(sistema->todosLanches);
	arq->salvaPedidosArq(sistema->todosPedidos);
}

void Proprietario::exibirLanchonetes(vector<Lanchonete*> &lanchonetes)
{
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "CODIGO " << "NOME " << "ENDERECO " << "CATEGORIA " << "PONTOS" << endl;
	wcout << endl;
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	for (auto l : lanchonetes)
	{
		if(l->getProprietarioNome() == this->nome)
		{
			wcout << "---------------------------------------------------------------------------------------------" << endl;
			cout << l->codigo << " " << l->nome << " " << l->endereco << " " << l->categoria << " " << l->pontos << endl;
			wcout << endl;
			wcout << "--------------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void Proprietario::cadastraLancheLanchonete()
{
	listaLanchonetesProprietario();
	int codigo;
	cin >> codigo;
	if (codigo == 0)
	{
		wcout << "Zero nao eh um codigo valido!" << endl;
	}
	else
	{
		Lanchonete *l = buscarLanchonete(codigo);
		if (l == nullptr)
		{
			wcout << "Codigo invalido!" << endl;
		}
		else if (verificaProprietario(l))
		{
			try
			{
				l->cadastraLanche(l);
			}
			catch (const CodigoReplicadoException &e)
			{
				wcout << "Exceptions occurred" << endl;
			}
		}

	}

}

Lanchonete *Proprietario::buscarLanchonete(int codigo)
{
	for (Lanchonete *l : sistema->getTodasLanchonetes())
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
	int codigo;
	cin >> codigo;
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
	int codigo;
	cin >> codigo;
	Lanchonete *l = buscarLanchonete(codigo);
	if (l == nullptr)
	{
		wcout << "Codigo invalido!" << endl;
	}
	else if (verificaProprietario(l))
	{
		l->visualizarPedidos();
		wcout << "Qual pedido deseja remover?" << endl;
		int codigoPedido;
		cin >> codigoPedido;
		Pedidos *p = l->buscarPedido(codigoPedido);
		if (p == nullptr)
		{
			throw CodigoNaoEncontradoException("Codigo invalido!");
		}
		else
		{
			l->removePedido(p);
			//sistema->getTodosPedidos().clear();
			//sistema.getTodosPedidos().remove(p);
		}
	}
}

void Proprietario::listaLanchonetesProprietario()
{
	exibirLanchonetes(sistema->todasLanchonetes);
	wcout << "Codigo da lanchonete: " << endl;
}

bool Proprietario::verificaProprietario(Lanchonete *l)
{
	if(l->getProprietarioNome() == this->nome)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<Lanchonete*> Proprietario::getLanchonetes()
{
	return this->lanchonetes;
}

void Proprietario::removerCadastro(const string &email, vector<Usuario*> &listaUsuarios)
{
	for(int i=0; i<listaUsuarios.size(); i++)
	{
		Usuario *u = listaUsuarios[i];
		if(u->getEmail() == email)
		{
			wcout << "Tem certeza que deseja remover o cadastro?" << endl;
			wcout << "1 - Sim\n2 - Nao" << endl;
			//int opcao = s::nextInt();
			int opcao;
			cin >> opcao;
			if (opcao == 1)
			{
				removerLanchonetesProprietario();
				std::remove(listaUsuarios.begin(), listaUsuarios.end(), u);
				//listaUsuarios->remove(u);
				wcout << "Cliente removido!" << endl;
				arq->salvaUsuariosArq(listaUsuarios);
				break;
			}
			else if (opcao == 2)
			{
				break;
			}
		}
	}
}
