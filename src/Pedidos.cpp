#include "../include/Pedidos.h"
#include <string>
#include <ctime>

using namespace std;

Pedidos::~Pedidos()
{
}

string Pedidos::toString()
{
	return "Pedido [codigo=" + to_string(codigo) + ", cliente=" + nomeCliente + ", valorTotal=" + to_string(valorTotal) + ", qntItens=" + to_string(qntItens) + ", data=" + data + "]";
}

Pedidos::Pedidos(int codigo, vector<Lanche*> &produtos, const string &nomeCliente, double valorTotal, int qntItens, const string &nomeLanchonete, const string &data)
{
	this->codigo = codigo;
	this->produtos = produtos;
	this->nomeCliente = nomeCliente;
	this->valorTotal = valorTotal;
	this->qntItens = qntItens;
	this->data = data;
	this->nomeLanchonete = nomeLanchonete;
}

Pedidos::Pedidos(vector<string> &list)
{
	this->codigo = stoi(list[0]);
	this->nomeCliente = list[1];
	this->valorTotal = stod(list[2]);
	this->qntItens = stoi(list[3]);
	//this->data = LocalDateTime::parse(list[4]);
	this->data = list[4];
	this->nomeLanchonete = list[5];
}

void Pedidos::gravaPedido(ofstream file)
{
	file << this->codigo << endl;
	file << this->nomeCliente << endl;
	file << this->valorTotal << endl;
	file << this->qntItens << endl;
	file << this->data << endl;
	file << this->nomeLanchonete << endl;
}
/*void Pedidos::gravaPedido(BufferedWriter *b)
{
	b->write(to_string(this->codigo) + L"\n");
	b->write(this->nomeCliente + L"\n");
	b->write(to_string(this->valorTotal) + L"\n");
	b->write(to_string(this->qntItens) + L"\n");
	b->write(this->data + L"\n");
	b->write(this->nomeLanchonete + L"\n");
}*/

int Pedidos::getCodigo()
{
	return codigo;
}

vector<Lanche*> Pedidos::getProdutos()
{
	return produtos;
}

int Pedidos::getQntItens()
{
	return qntItens;
}

/*LocalDateTime Pedidos::getData()
{
	return data;
}*/

string Pedidos::getData()
{
	return data;
}
