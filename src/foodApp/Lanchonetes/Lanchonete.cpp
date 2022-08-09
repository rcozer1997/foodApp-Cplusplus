#include "Lanchonete.h"

namespace foodApp::Lanchonetes
{
	using BufferedReader = java::io::BufferedReader;
	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using LocalDateTime = java::time::LocalDateTime;
	using ArrayList = java::util::ArrayList;
	using Random = java::util::Random;
	using Scanner = java::util::Scanner;
	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;
	using CodigoReplicadoException = foodApp::Exceptions::CodigoReplicadoException;

	std::wstring Lanchonete::toString()
	{
		return L"Lanchonete [codigo=" + std::to_wstring(codigo) + L", nome=" + nome + L", endereco=" + endereco + L", categoria=" + categoria + L", pontos=" + std::to_wstring(pontos) + L", proprietario= " + nomeProprietario + L"]";
	}

	Lanchonete::Lanchonete(BufferedReader *b, Sistema *sistema)
	{
		try
		{
		this->codigo = static_cast<int>(b->readLine());
		this->nome = b->readLine();
		this->endereco = b->readLine();
		this->categoria = b->readLine();
		this->pontos = static_cast<Float>(b->readLine());
		this->nomeProprietario = b->readLine();
		this->emailProprietario = b->readLine();
		this->sistema = sistema;
		}
		catch (const IOException &e)
		{
			std::wcout << L"Erro" << std::endl;
		}
	}

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
	Lanchonete::Lanchonete(int codigo, const std::wstring &nome, const std::wstring &endereco, const std::wstring &categoria, const std::wstring &nomeProprietario, const std::wstring &emailProprietario)
	{
		this->codigo = codigo;
		this->nome = nome;
		this->endereco = endereco;
		this->categoria = categoria;
		this->pontos = 0;
		this->nomeProprietario = nomeProprietario;
		this->emailProprietario = emailProprietario;
	}

	void Lanchonete::gravaLanchonete(BufferedWriter *b)
	{
			b->write(std::to_wstring(this->codigo) + L"\n");
			b->write(this->nome + L"\n");
			b->write(this->endereco + L"\n");
			b->write(this->categoria + L"\n");
			b->write(std::to_wstring(this->pontos) + L"\n");
			b->write(this->nomeProprietario + L"\n");
			b->write(this->emailProprietario + L"\n");
	}

	void Lanchonete::cadastraLanche(Lanchonete *l)
	{
		std::wcout << L"Informe os dados do lanche:" << std::endl;
		std::wcout << L"Codigo identificador: " << std::endl;
		int codigo = s->nextInt();
		s->nextLine();
		std::wcout << L"Descricao: " << std::endl;
		std::wstring descricao = s->nextLine();
		std::wcout << L"Preco: " << std::endl;
		float preco = s->nextFloat();

		if (verificaExistenciaLanche(codigo))
		{
			Lanche *lanche = new Lanche(codigo,descricao, preco, this->getNome());
			lanches.push_back(lanche);
			sistema->getTodosLanches().push_back(lanche);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete lanche' statement was not added since lanche was passed to a method or constructor. Handle memory management manually.
		}
		else if (!verificaExistenciaLanche(codigo))
		{
			throw CodigoReplicadoException(L"Codigo ja cadastrado!");
		}

	}

	int Lanchonete::getCodigo()
	{
		return this->codigo;
	}

	std::wstring Lanchonete::getProprietarioNome()
	{
		return this->nomeProprietario;
	}

	std::wstring Lanchonete::getProprietarioEmail()
	{
		return this->emailProprietario;
	}

	std::vector<Lanche*> Lanchonete::getListaLanches()
	{
		return this->lanches;
	}

	void Lanchonete::removeTodosPedidos()
	{
		for (auto thisPedido : listaPedidos)
		{
			for (int i = 0; i < sistema->getTodosPedidos().size(); i++)
			{
				Pedidos *p = sistema->getTodosPedidos()[i];
				if (p->getCodigo() == thisPedido->getCodigo())
				{
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
					sistema->getTodosPedidos().remove(p);
				}
			}
		}
		//listaPedidos.removeAll(listaPedidos);
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
					sistema->getTodosLanches().remove(l);
				}
			}
		}
		//lanches.removeAll(lanches);
	}

	void Lanchonete::listarLanches()
	{
		std::wcout << L"-------------------------------DADOS DA LANCHONETE-----------------------------------------" << std::endl;
		std::wcout << std::endl;
		printf(L"%20s%20s%15s%15s", L"NOME", L"ENDERECO", L"CATEGORIA", L"PONTOS");
		std::wcout << std::endl;
		std::wcout << L"-------------------------------------------------------------------------------------------" << std::endl;
		System::out::format(L"%20s%20s%15s%15s",this->nome, this->endereco, this->categoria, this->pontos);
		std::wcout << std::endl;
		std::wcout << std::endl;
		std::wcout << std::endl;

		std::wcout << L"-------------------------------------LANCHES------------------------------------------------" << std::endl;
		std::wcout << std::endl;
		printf(L"%15s%20s%15s", L"CODIGO", L"DESCRICAO", L"PRECO");
		std::wcout << std::endl;
		for (auto l : lanches)
		{
			std::wcout << L"----------------------------------------------------------------------------------------" << std::endl;
			System::out::format(L"%15s%20s%15s",l->codigo, l->descricao, l->preco);
			std::wcout << std::endl;
			std::wcout << L"----------------------------------------------------------------------------------------" << std::endl;

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
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	printf(L"%15s%20s%15s%15s%20s", L"CODIGO", L"NOME CLIENTE", L"VALOR TOTAL", L"QTD. ITENS", L"DATA");
	std::wcout << std::endl;
	std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
	for (Pedidos *p : listaPedidos)
	{
		std::wcout << L"-------------------------------------------------------------------------------------------------" << std::endl;
		System::out::format(L"%15s%20s%15s%10s%40s",p->codigo, p->nomeCliente, p->valorTotal, p->qntItens, p->data);
		std::wcout << std::endl;
		std::wcout << L"-------------------------------------------------------------------------------------------------" << std::endl;
	}
	std::wcout << L"Numero de pedidos: " << this->listaPedidos->size() << std::endl;
}

void Lanchonete::visualizarPedidoEspecifico()
{
	visualizarPedidos();
	std::wcout << L"Codigo do pedido a ser visto: " << std::endl;
	int codigo = s::nextInt();
	Pedidos *p = buscarPedido(codigo);
	if (p == nullptr)
	{
		std::wcout << L"Codigo invalido!" << std::endl;
	}
	else
	{
		std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
		printf(L"%15s%20s%15s%15s%20s", L"CODIGO", L"NOME CLIENTE", L"DATA", L"PRODUTOS");
		std::wcout << std::endl;
		std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
		std::wcout << L"-----------------------------------------------------------------------------------------------------" << std::endl;
			System::out::format(L"%15s%20s%15s%15s%20s",p->codigo, p->nomeCliente, p->data, p->produtos);
			std::wcout << std::endl;
			std::wcout << L"-------------------------------------------------------------------------------------------------" << std::endl;
	}
}

Pedidos *Lanchonete::buscarPedido(int codigo)
{
	for (Pedidos *p : listaPedidos)
	{
		if (p->codigo == codigo)
		{
			return p;
		}
	}
	return nullptr;
}

std::vector<Lanche*> *Lanchonete::getLanches()
{
	return lanches;
}

std::vector<Pedidos*> *Lanchonete::getListaPedidos()
{
	return listaPedidos;
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
	if (this->listaPedidos->size() < l->listaPedidos->size())
	{
		return -1;
	}
	if (this->listaPedidos->size() > l->listaPedidos->size())
	{
		return 1;
	}
	return 0;
}

void Lanchonete::precoMedioLanches()
{
	double soma = 0;
	for (int i = 0; i < lanches->size(); i++)
	{
		soma += lanches->get(i).getPreco();
	}
	this->precoMedio = (soma / lanches->size());
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

void Lanchonete::fazerPedido(const std::wstring &nomeCliente)
{
	int opcao;
	int quant;
	float valor;
	std::vector<Lanche*> *produtosComprados = std::vector<Lanche*>();
	LocalDateTime dataAtual = LocalDateTime::now();
	do
	{
		listarLanches();
		quant = 0;
		valor = 0;
	std::wcout << L"Digite o codigo do produto ou pressione 0 para sair: " << std::endl;
	opcao = s::nextInt();
	if (opcao == 0)
	{
		std::wcout << L"Obrigado! Volte sempre!" << std::endl;
		break;
	}
	for (Lanche *l : lanches)
	{
		if (l->getCodigo() == opcao)
		{
			std::wcout << L"Qual a quantidade?" << std::endl;
			quant = s::nextInt();
			for (int i = 0; i < quant; i++)
			{
				produtosComprados->add(l);
			}
			valor = l->getPreco() * quant;
		}

	}while (opcao != 0);

	int codigoPedido = geraCodigoPedido(); //Optei por gerar randomicamente o codigo do pedido, checando tambem se o numero randomizado ja esta cadastrado. Caso sim, randomiza novamente
	int qntItens = produtosComprados->size();
	double valorTotal = calculaValorTotalPedido(produtosComprados);
	Pedidos *p = new Pedidos(codigoPedido, produtosComprados, nomeCliente, valorTotal, qntItens, this->getNome(), dataAtual);
	listaPedidos->add(p);
	sistema::getTodosPedidos()->add(p);
	if (p->getQntItens() == 0)
	{
		listaPedidos->remove(p);
		sistema::getTodosPedidos()->remove(p);
	}
	std::wcout << L"Deseja comprar mais ou finalizar? Caso queira finalizar, pressione 0." << std::endl;

//JAVA TO C++ CONVERTER TODO TASK: A 'delete p' statement was not added since p was passed to a method or constructor. Handle memory management manually.
	}

void removePedido(Pedidos p)
{
	listaPedidos->remove(p);
	sistema::getTodosPedidos()->remove(p);
	//arq.salvaPedidosArq(sistema.getTodosPedidos());
}

std::wstring getNome()
{
//JAVA TO C++ CONVERTER TODO TASK: A 'delete produtosComprados' statement was not added since produtosComprados was passed to a method or constructor. Handle memory management manually.
	return this->nome;
}


void Lanchonete::atualizaPontos(float nota)
{
		this->pontos = (pontos + nota) / 2;
}

int Lanchonete::geraCodigoPedido()
{
	Random tempVar();
	int codigoPedido = (&tempVar)->nextInt(10000) + 1;
		for (Pedidos *p : sistema::getTodosPedidos())
		{
			if (p->getCodigo() == codigoPedido)
			{
				Random tempVar2();
				codigoPedido = (&tempVar2)->nextInt(10000) + 1;
			}
		}
	if (codigoPedido == 0)
	{
		codigoPedido++;
	}
	return codigoPedido;
}

double Lanchonete::calculaValorTotalPedido(std::vector<Lanche*> *lanchesComprados)
{
	double valorTotal = 0;
	for (auto l : *lanchesComprados)
	{
		valorTotal = valorTotal + l->getPreco();
	}
	return valorTotal;
}
}
}
