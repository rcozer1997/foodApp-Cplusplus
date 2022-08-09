#include "Lanche.h"

namespace foodApp::Lanchonetes
{
	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
	Lanche::Lanche(int codigo, const std::wstring &descricao, float preco, const std::wstring &nomeLanchonete)
	{
		this->codigo = codigo;
		this->descricao = descricao;
		this->preco = preco;
		this->nomeLanchonete = nomeLanchonete;
	}

	Lanche::Lanche(std::vector<std::wstring> &list)
	{
		this->codigo = std::stoi(list[0]);
		this->descricao = list[1];
		this->preco = std::stof(list[2]);
		this->nomeLanchonete = list[3];
	}

	void Lanche::gravaLanche(BufferedWriter *b)
	{
		b->write(std::to_wstring(this->codigo) + L"\n");
		b->write(this->descricao + L"\n");
		b->write(std::to_wstring(this->preco) + L"\n");
		b->write(this->nomeLanchonete + L"\n");
	}

	std::wstring Lanche::getNome()
	{
		return this->descricao;
	}

	int Lanche::getCodigo()
	{
		return this->codigo;
	}

	std::wstring Lanche::getDescricao()
	{
		return descricao;
	}

	float Lanche::getPreco()
	{
		return preco;
	}

	std::wstring Lanche::getNomeLanchonete()
	{
		return nomeLanchonete;
	}

	std::wstring Lanche::toString()
	{
		return L"Lanche [codigo=" + std::to_wstring(codigo) + L", descricao=" + descricao + L", preco=" + std::to_wstring(preco) + L"]";
	}

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
}
