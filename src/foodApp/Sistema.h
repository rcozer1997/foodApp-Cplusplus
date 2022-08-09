#pragma once

#include "Exceptions/EmailInvalidoException.h"
#include "Exceptions/SenhaInvalidaException.h"
#include "Lanchonetes/Lanche.h"
#include "Lanchonetes/Lanchonete.h"
#include "Lanchonetes/Pedidos.h"
#include "Usuarios/Administrador.h"
#include "Usuarios/Cliente.h"
#include "Usuarios/Proprietario.h"
#include "Usuarios/Usuario.h"
#include "Arquivos.h"
#include <string>
#include <vector>
#include <iostream>

namespace foodApp
{
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;

	using EmailInvalidoException = foodApp::Exceptions::EmailInvalidoException;
	using SenhaInvalidaException = foodApp::Exceptions::SenhaInvalidaException;
	using Lanche = foodApp::Lanchonetes::Lanche;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;
	using Pedidos = foodApp::Lanchonetes::Pedidos;
	using Usuario = foodApp::Usuarios::Usuario;

	class Sistema
	{
	public:
		Scanner *s = new Scanner(System::in);
		Arquivos *arq = new Arquivos();
		std::vector<Usuario*> listaUsuarios = std::vector<Usuario*>();
		std::vector<Lanchonete*> todasLanchonetes = std::vector<Lanchonete*>();
		std::vector<Pedidos*> todosPedidos = std::vector<Pedidos*>();
		std::vector<Lanche*> todosLanches = std::vector<Lanche*>();

		virtual ~Sistema()
		{
			delete s;
			delete arq;
		}

		virtual bool verificaCadastro(Usuario *u, std::vector<Usuario*> &listaUsuarios);

		virtual void login(std::vector<Usuario*> &listaUsuarios, Sistema *sistema);

		virtual void validaSenha(Usuario *u, const std::wstring &senha, Sistema *sistema);

		virtual std::vector<Lanchonete*> getTodasLanchonetes();

		virtual std::vector<Usuario*> getListaUsuarios();

		virtual std::vector<Pedidos*> getTodosPedidos();

		virtual std::vector<Lanche*> getTodosLanches();

		virtual bool verificaExistenciaLanchonete(int codigo);
	};

}
