#include "Pedidos.h"

namespace foodApp::Lanchonetes
{
	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using LocalDateTime = java::time::LocalDateTime;
	using ArrayList = java::util::ArrayList;

	std::wstring Pedidos::toString()
	{
		return L"Pedido [codigo=" + std::to_wstring(codigo) + L", cliente=" + nomeCliente + L", valorTotal=" + std::to_wstring(valorTotal) + L", qntItens=" + std::to_wstring(qntItens) + L", data=" + data + L"]";
	}

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
	Pedidos::Pedidos(int codigo, std::vector<Lanche*> &produtos, const std::wstring &nomeCliente, double valorTotal, int qntItens, const std::wstring &nomeLanchonete, LocalDateTime data)
	{
		this->codigo = codigo;
		this->produtos = produtos;
		this->nomeCliente = nomeCliente;
		this->valorTotal = valorTotal;
		this->qntItens = qntItens;
		this->data = data;
		this->nomeLanchonete = nomeLanchonete;
	}

	Pedidos::Pedidos(std::vector<std::wstring> &list)
	{
		this->codigo = std::stoi(list[0]);
		this->nomeCliente = list[1];
		this->valorTotal = std::stod(list[2]);
		this->qntItens = std::stoi(list[3]);
		this->data = LocalDateTime::parse(list[4]);
		this->nomeLanchonete = list[5];
	}

	void Pedidos::gravaPedido(BufferedWriter *b)
	{
		b->write(std::to_wstring(this->codigo) + L"\n");
		b->write(this->nomeCliente + L"\n");
		b->write(std::to_wstring(this->valorTotal) + L"\n");
		b->write(std::to_wstring(this->qntItens) + L"\n");
		b->write(this->data + L"\n");
		b->write(this->nomeLanchonete + L"\n");
	}

	int Pedidos::getCodigo()
	{
		return codigo;
	}

	std::vector<Lanche*> Pedidos::getProdutos()
	{
		return produtos;
	}

	int Pedidos::getQntItens()
	{
		return qntItens;
	}

	LocalDateTime Pedidos::getData()
	{
		return data;
	}
}
