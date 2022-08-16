#include "../include/Lanchonete.h"
#include <cstdlib>

using namespace std;
using std::remove;
/*Lanchonete::Lanchonete()
{
}*/

Lanchonete::~Lanchonete()
{
	delete sistema;
	delete arq;
	//delete s;
}

string Lanchonete::toString()
{
	//cout << "Lanchonete [codigo=" << codigo << ", nome=" << nome << ", endereco=" << endereco << ", categoria=" << categoria << ", pontos=" << pontos << ", proprietario=" << nomeProprietario << "]" << endl;
	return "Lanchonete [codigo=" + to_string(codigo) + ", nome=" + nome + ", endereco=" + endereco + ", categoria=" + categoria + ", pontos=" + to_string(pontos) + ", proprietario= " + nomeProprietario + "]";
}

Lanchonete::Lanchonete(ifstream file, Sistema *sistema)
{
	file >> this->codigo;
	file >> this->nome;
	file >> this->endereco;
	file >> this->categoria;
	file >> this->pontos;
	file >> this->nomeProprietario;
	file >> this->emailProprietario;
	this->sistema = sistema;
}

Lanchonete::Lanchonete(int codigo, const string &nome, const string &endereco, const string &categoria, const string &nomeProprietario, const string &emailProprietario)
{
	this->codigo = codigo;
	this->nome = nome;
	this->endereco = endereco;
	this->categoria = categoria;
	this->pontos = 0;
	this->nomeProprietario = nomeProprietario;
	this->emailProprietario = emailProprietario;
}

void Lanchonete::gravaLanchonete(ofstream file)
{
	file << this->codigo << endl;
	file << this->nome << endl;
	file << this->endereco << endl;
	file << this->categoria << endl;
	file << fixed << setprecision(2) << this->pontos << endl;
	file << this->nomeProprietario << endl;
	file << this->emailProprietario << endl;
}

void Lanchonete::cadastraLanche(Lanchonete *l)
{
	wcout << "Informe os dados do lanche: " << endl;
	wcout << "Codigo identificador: " << endl;
	int codigo;
	cin >> codigo;
	wcout << "Descricao: " << endl;
	string descricao;
	cin >> descricao;
	wcout << "Preco: " << endl;
	float preco;
	cin >> preco;

	if (verificaExistenciaLanche(codigo))
	{
		Lanche *lanche = new Lanche(codigo,descricao, preco, this->getNome());
		lanches.push_back(lanche);
		sistema->getTodosLanches().push_back(lanche);
	}
	else if (!verificaExistenciaLanche(codigo))
	{
		throw CodigoReplicadoException("Codigo ja cadastrado!");
	}

}

int Lanchonete::getCodigo()
{
	return this->codigo;
}

string Lanchonete::getProprietarioNome()
{
	return this->nomeProprietario;
}

string Lanchonete::getProprietarioEmail()
{
	return this->emailProprietario;
}

vector<Lanche*> Lanchonete::getListaLanches()
{
	return this->lanches;
}

void Lanchonete::removeTodosPedidos()
{
	for (auto thisPedido : pedidos)
	{
		for (int i = 0; i < sistema->getTodosPedidos().size(); i++)
		{
			Pedidos *p = sistema->getTodosPedidos()[i];
			if (p->getCodigo() == thisPedido->getCodigo())
			{
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
				std::remove(sistema->getTodosPedidos().begin(), sistema->getTodosPedidos().end(), p);
				//sistema->getTodosPedidos().remove(p);
			}
		}
	}
	//listaPedidos.removeAll(listaPedidos);
	pedidos.clear();
}

void Lanchonete::removeTodosLanches()
{
	for (auto thisLanches : lanches)
	{
		for (int i = 0; i < sistema->getTodosLanches().size(); i++)
		{
			Lanche *l = sistema->getTodosLanches()[i];
			if (l->getCodigo() == thisLanches->getCodigo())
			{
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
				std::remove(sistema->getTodosLanches().begin(), sistema->getTodosLanches().end(), l);
				//sistema->getTodosLanches().remove(l);
				//std::remove(str1.begin(), str1.end(), ' ')
			}
		}
	}
	//lanches.removeAll(lanches);
	lanches.clear();
}

void Lanchonete::listarLanches()
{
	wcout << "-------------------------------DADOS DA LANCHONETE-----------------------------------------" << endl;
	wcout << endl;
	cout << "NOME " << "ENDERECO " << "CATEGORIA " << "PONTOS" << endl;
	wcout << endl;
	wcout << "-------------------------------------------------------------------------------------------" << endl;
	cout << this->nome << " " << this->endereco << " " << this->categoria << " " << this->pontos << endl;
	wcout << endl;
	wcout << endl;
	wcout << endl;

	wcout << "-------------------------------------LANCHES------------------------------------------------" << endl;
	wcout << endl;
	cout << "CODIGO " << "DESCRICAO " << "PRECO" << endl;
	wcout << endl;
	for (auto l : lanches)
	{
		wcout << "----------------------------------------------------------------------------------------" << endl;
		cout << l->codigo << " " << l->descricao << " " << l->preco << endl;
		wcout << endl;
		wcout << "----------------------------------------------------------------------------------------" << endl;

	}
}

bool Lanchonete::verificaExistenciaLanche(int codigo)
{
	for (int i = 0; i < lanches.size();i++)
	{
		Lanche *l = sistema->getTodosLanches()[i];
		if (l->getCodigo() == codigo)
		{
			return false;
		}
	}
	return true;
}

void Lanchonete::visualizarPedidos()
{
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "CODIGO " << "NOME CLIENTE " << "VALOR TOTAL " << "QTD. ITENS " << "DATA" << endl;
	wcout << endl;
	wcout << "-----------------------------------------------------------------------------------------------------" << endl;
	for (Pedidos *p : pedidos)
	{
		wcout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << p->codigo << " " << p->nomeCliente << " " << p->valorTotal << " " << p->qntItens << " " << p->data << endl;
		wcout << endl;
		wcout << "-------------------------------------------------------------------------------------------------" << endl;
	}
	wcout << "Numero de pedidos: " << this->pedidos.size() << endl;
}

void Lanchonete::visualizarPedidoEspecifico()
{
	visualizarPedidos();
	wcout << "Codigo do pedido a ser visto: " << endl;
	int codigo;
	cin >> codigo;
	Pedidos *p = buscarPedido(codigo);
	if (p == nullptr)
	{
		wcout << "Codigo invalido!" << endl;
	}
	else
	{	
		p->toString();
		/*
		wcout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << "CODIGO " << "NOME CLIENTE " << "DATA " << "PRODUTOS" << endl;
		wcout << endl;
		wcout << "-----------------------------------------------------------------------------------------------------" << endl;
		wcout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << p->codigo << " " << p->nomeCliente << " " << p->data << " " << p->produtos << " " << endl;
		wcout << endl;
		wcout << "-------------------------------------------------------------------------------------------------" << endl;
		*/
	}
}

Pedidos *Lanchonete::buscarPedido(int codigo)
{
	for(Pedidos *p : pedidos)
	{
		if (p->codigo == codigo)
		{
			return p;
		}
	}
	return nullptr;
}

vector<Lanche*> Lanchonete::getLanches()
{
	return lanches;
}

vector<Pedidos*> Lanchonete::getListaPedidos()
{
	return pedidos;
}

double Lanchonete::getPrecoMedio()
{
	return precoMedio;
}

int Lanchonete::comparaPontos(Lanchonete *l)
{
	if (this->pontos < l->pontos)
	{
		return 1;
	}
	if (this->pontos > l->pontos)
	{
		return -1;
	}
	return 0;
}

int Lanchonete::comparaVendas(Lanchonete *l)
{
	if (this->pedidos.size() < l->pedidos.size())
	{
		return -1;
	}
	if (this->pedidos.size() > l->pedidos.size())
	{
		return 1;
	}
	return 0;
}

void Lanchonete::precoMedioLanches()
{
	double soma = 0;
	for (int i = 0; i < lanches.size(); i++)
	{
		soma += lanches[i]->getPreco();
		//soma += lanches->get(i).getPreco();
	}
	this->precoMedio = (soma / lanches.size());
}

int Lanchonete::compareTo(Lanchonete *l)
{
	if (this->precoMedio < l->precoMedio)
	{
		return 1;
	}
	if (this->precoMedio > l->precoMedio)
	{
		return -1;
	}
	return 0;
}

void Lanchonete::fazerPedido(const string &nomeCliente)
{
	int opcao;
	int quant;
	float valor;
	vector<Lanche*> produtosComprados = vector<Lanche*>();
	//LocalDateTime dataAtual = LocalDateTime::now();
	time_t now = time(0);
	string data = ctime(&now);
	do
	{
		listarLanches();
		quant = 0;
		valor = 0;
		wcout << "Digite o codigo do produto ou pressione 0 para sair: " << endl;
		int opcao;
		cin >> opcao;
		if(opcao == 0)
		{
			wcout << "Obrigado! Volte sempre!" << endl;
			break;
		}
		for(Lanche *l : lanches)
		{
			if(l->getCodigo() == opcao)
			{
				wcout << "Qual a quantidade?" << endl;
				cin >> quant;
				for(int i=0; i<quant; i++)
				{
					produtosComprados.push_back(l);
				}
				valor = l->getPreco() * quant;
			}
		}
	}while(opcao != 0);

	int codigoPedido = geraCodigoPedido(); //Optei por gerar randomicamente o codigo do pedido, checando tambem se o numero randomizado ja esta cadastrado. Caso sim, randomiza novamente
	int qntItens = produtosComprados.size();
	double valorTotal = calculaValorTotalPedido(produtosComprados);
	Pedidos *p = new Pedidos(codigoPedido, produtosComprados, nomeCliente, valorTotal, qntItens, this->getNome(), data);
	pedidos.push_back(p);
	sistema->getTodosPedidos().push_back(p);
	if(p->getQntItens() == 0)
	{	
		std::remove(pedidos.begin(), pedidos.end(), p);
		std::remove(sistema->getTodosPedidos().begin(), sistema->getTodosPedidos().end(), p);
		//pedidos.remove(p);
		//sistema->getTodosPedidos().remove(p);
	}
	wcout << "Deseja comprar mais ou finalizar? Caso queira finalizar, pressione 0." << endl;

}

void Lanchonete::removePedido(Pedidos *p)
{	
	std::remove(pedidos.begin(), pedidos.end(), p);
	std::remove(sistema->getTodosPedidos().begin(), sistema->getTodosPedidos().end(), p);
	//pedidos.remove(p);
	//sistema->getTodosPedidos().remove(p);
	//arq.salvaPedidosArq(sistema.getTodosPedidos());
}

string Lanchonete::getNome()
{
	return this->nome;
}

void Lanchonete::atualizaPontos(float nota)
{
	this->pontos = (pontos + nota) / 2;
}

/*
int Lanchonete::geraCodigoPedido()
{
	srand(time(0));
	int tempVar = rand();
	//Random tempVar();
	int codigoPedido = (&tempVar)->nextInt(10000) + 1;
	for (Pedidos *p : sistema->getTodosPedidos())
	{
		if (p->getCodigo() == codigoPedido)
		{
			int tempVar2 = rand();
			//Random tempVar2();
			codigoPedido = (&tempVar2)->nextInt(10000) + 1;
		}
	}
	if (codigoPedido == 0)
	{
		codigoPedido++;
	}
	return codigoPedido;
}*/

double Lanchonete::calculaValorTotalPedido(vector<Lanche*> &lanchesComprados)
{
	double valorTotal = 0;
	for (auto l : lanchesComprados)
	{
		valorTotal = valorTotal + l->getPreco();
	}
	return valorTotal;
}

