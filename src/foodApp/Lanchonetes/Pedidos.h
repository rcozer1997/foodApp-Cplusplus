#pragma once

#include "Lanchonete.h"
#include "Lanche.h"
#include <string>
#include <vector>

namespace foodApp::Lanchonetes
{

	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using LocalDateTime = java::time::LocalDateTime;
	using ArrayList = java::util::ArrayList;

	class Pedidos
	{
	public:
		int codigo = 0;
		std::wstring nomeCliente;
		double valorTotal = 0.0;
		int qntItens = 0;
		std::wstring nomeLanchonete;
		LocalDateTime data;
		Lanchonete *lanchonete;
		std::vector<Lanche*> produtos = std::vector<Lanche*>();

		virtual ~Pedidos()
		{
			delete lanchonete;
		}

		virtual std::wstring toString();

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
		Pedidos(int codigo, std::vector<Lanche*> &produtos, const std::wstring &nomeCliente, double valorTotal, int qntItens, const std::wstring &nomeLanchonete, LocalDateTime data); //super();

		Pedidos(std::vector<std::wstring> &list);

		virtual void gravaPedido(BufferedWriter *b);
		virtual int getCodigo();

		virtual std::vector<Lanche*> getProdutos();

		virtual int getQntItens();

		virtual LocalDateTime getData();
	};


}
