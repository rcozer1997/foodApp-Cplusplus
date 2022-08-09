#pragma once

#include "../App.h"
#include "../Sistema.h"
#include "../Exceptions/CodigoNaoEncontradoException.h"
#include "../Lanchonetes/ComparaLanchonetePontos.h"
#include "../Lanchonetes/ComparaLanchonetePrecoMedio.h"
#include "../Lanchonetes/ComparaLanchoneteVendas.h"
#include "../Lanchonetes/Lanche.h"
#include "../Lanchonetes/Lanchonete.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

namespace foodApp::Usuarios
{

	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using Sistema = foodApp::Sistema;
	using CodigoNaoEncontradoException = foodApp::Exceptions::CodigoNaoEncontradoException;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;

	class Cliente : public Usuario
	{
	public:
		Scanner *s = new Scanner(System::in);
		virtual ~Cliente()
		{
			delete s;
		}

		Cliente(Sistema *sistema);

		Cliente(std::vector<std::wstring> &list);

		void menu() override;

		virtual void exibirLanchonetes();

		virtual Lanchonete *buscarLanchonete(int codigo);

		virtual void verLanchesLanchonete();

		virtual void listarLanchonetesPontuacao();

		virtual void listarPontuacaoCategoria();

		virtual void listarLanchonetesPrecoMedio();

		virtual void listarLanchonetesVendas();

		virtual void buscarLanche();

		virtual void fazerPedidoLanchonete();

		virtual void avaliaLanchonete();
	};

}
