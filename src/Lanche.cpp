#include "../include/Lanche.h"

using namespace std;

Lanche::~Lanche()
{
}

Lanche::Lanche(int codigo, const string &descricao, float preco, const string &nomeLanchonete)
{
	this->codigo = codigo;
	this->descricao = descricao;
	this->preco = preco;
	this->nomeLanchonete = nomeLanchonete;
}

Lanche::Lanche(vector<string> &list)
{
	this->codigo = stoi(list[0]);
	this->descricao = list[1];
	this->preco = stof(list[2]);
	this->nomeLanchonete = list[3];
}

void Lanche::gravaLanche(ofstream file)
{
	file << this->codigo;
	file << this->descricao;
	file << this->preco;
	file << this->nomeLanchonete;
}

string Lanche::getNome()
{
	return this->descricao;
}

int Lanche::getCodigo()
{
	return this->codigo;
}

string Lanche::getDescricao()
{
	return descricao;
}

float Lanche::getPreco()
{
	return preco;
}

string Lanche::getNomeLanchonete()
{
	return nomeLanchonete;
}

string Lanche::toString()
{
	return "Lanche [codigo=" + to_string(codigo) + ", descricao=" + descricao + ", preco=" + to_string(preco) + "]";
}


/*void Lanche::toString()
{
	cout << "Lanche [codigo=" << codigo << ", descricao=" << descricao << ", preco=" << preco << "]" << endl;
}*/

int Lanche::compareTo(Lanche *l)
{
	if (this->preco < l->preco)
	{
		return -1;
	}
	if (this->preco > l->preco)
	{
		return 1;
	}
	return 0;
}
