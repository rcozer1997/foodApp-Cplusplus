#include "Sistema.h"

namespace foodApp
{
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using EmailInvalidoException = foodApp::Exceptions::EmailInvalidoException;
	using SenhaInvalidaException = foodApp::Exceptions::SenhaInvalidaException;
	using Lanche = foodApp::Lanchonetes::Lanche;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;
	using Pedidos = foodApp::Lanchonetes::Pedidos;
	using Administrador = foodApp::Usuarios::Administrador;
	using Cliente = foodApp::Usuarios::Cliente;
	using Proprietario = foodApp::Usuarios::Proprietario;
	using Usuario = foodApp::Usuarios::Usuario;

	bool Sistema::verificaCadastro(Usuario *u, std::vector<Usuario*> &listaUsuarios)
	{
		for (int i = 0; i < listaUsuarios.size();i++)
		{
			Usuario *usu = listaUsuarios[i];
			if (usu->getEmail() == u->getEmail())
			{
				throw EmailInvalidoException(L"Email ja cadastrado!");
			}
		}
		return true;
	}

	void Sistema::login(std::vector<Usuario*> &listaUsuarios, Sistema *sistema)
	{
		std::wcout << L"Email:";
		std::wstring email = s->nextLine();
		std::wcout << L"Senha:";
		std::wstring senha = s->nextLine();

		Usuario *usu = nullptr;
		for (int i = 0; i < listaUsuarios.size();i++)
		{
			Usuario *u = listaUsuarios[i];
			if (u->getEmail() == email)
			{
				usu = u;
				try
				{
					validaSenha(usu, senha, sistema);
				}
				catch (const SenhaInvalidaException &e)
				{
					std::wcout << e->what() << std::endl;
				}
				break;
			}
		}
		if (usu == nullptr)
		{
			throw EmailInvalidoException(L"Usuario nao existe!");
		}
	}

	void Sistema::validaSenha(Usuario *u, const std::wstring &senha, Sistema *sistema)
	{
		if (u->getSenha() == senha)
		{
			if (u->getIdent() == 1)
			{
				std::wcout << L"Logado com sucesso!" << std::endl;
				Administrador *a = static_cast<Administrador*>(u);
				a->sistema = sistema;
				a->menu();
			}
			else if (u->getIdent() == 2)
			{
				std::wcout << L"Logado com sucesso!" << std::endl;
				Proprietario *p = static_cast<Proprietario*>(u);
				p->sistema = sistema;
				p->menu();
			}
			else if (u->getIdent() == 3)
			{
				std::wcout << L"Logado com sucesso!" << std::endl;
				Cliente *c = static_cast<Cliente*>(u);
				c->sistema = sistema;
				c->menu();
			}
		}
		else
		{
			throw SenhaInvalidaException(L"Senha incorreta!");
		}
	}

	std::vector<Lanchonete*> Sistema::getTodasLanchonetes()
	{
		return this->todasLanchonetes;
	}

	std::vector<Usuario*> Sistema::getListaUsuarios()
	{
		return this->listaUsuarios;
	}

	std::vector<Pedidos*> Sistema::getTodosPedidos()
	{
		return this->todosPedidos;
	}

	std::vector<Lanche*> Sistema::getTodosLanches()
	{
		return this->todosLanches;
	}

	bool Sistema::verificaExistenciaLanchonete(int codigo)
	{
		for (int i = 0; i < this->todasLanchonetes.size();i++)
		{
			Lanchonete *l = this->todasLanchonetes[i];
			if (l->getCodigo() == codigo)
			{
				return false;
			}
		}
		return true;
	}
}
