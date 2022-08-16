#include "../include/Sistema.h"
#include "../include/Usuario.h"
#include <string>
#include <string.h>

using namespace std;

Sistema::Sistema()
{
}

Sistema::~Sistema()
{
	//delete s;
	delete arq;
}

bool verificaCadastro(Usuario *u, vector<Usuario*> &listaUsuarios)
{
	for (Usuario *usu : listaUsuarios)
	{
		if (usu->getEmail() == u->getEmail()){
			throw EmailInvalidoException("Email ja cadastrado!");
		}
	}
	return true;
}

void Sistema::login(vector<Usuario*> &listaUsuarios, Sistema *sistema)
{
	string email, senha;
	wcout << "Email: ";
	cin >> email;
	wcout << "Senha: ";
	cin >> senha;

	Usuario *usu = nullptr;
	for (Usuario *u : listaUsuarios)
	{		
		if (u->getEmail().compare(email) == 0)
		{
			usu = u;
			try{
				validaSenha(usu, senha, sistema);
			}catch (const SenhaInvalidaException &e){
				wcout << "Exceptions occurred" << endl;
			}
			break;
		}
	}
	if (usu == nullptr)
	{
		throw EmailInvalidoException("Usuario nao existe!");
	}
}

void Sistema::validaSenha(Usuario *u, const string &senha, Sistema *sistema)
{
	if (u->getSenha() == senha)
	{
		if (u->getIdent() == 1)
		{
			wcout << "Logado com sucesso!" << endl;
			Administrador *a = static_cast<Administrador*>(u);
			a->sistema = sistema;
			a->menu();
		}
		else if (u->getIdent() == 2)
		{
			wcout << "Logado com sucesso!" << endl;
			Proprietario *p = static_cast<Proprietario*>(u);
			p->sistema = sistema;
			p->menu();
		}
		else if (u->getIdent() == 3)
		{
			wcout << "Logado com sucesso!" << endl;
			Cliente *c = static_cast<Cliente*>(u);
			c->sistema = sistema;
			c->menu();
		}
	}
	else
	{
		throw SenhaInvalidaException("Senha incorreta!");
	}
}

vector<Lanchonete*> Sistema::getTodasLanchonetes()
{
	return this->todasLanchonetes;
}

vector<Usuario*> Sistema::getListaUsuarios()
{
	return this->listaUsuarios;
}

vector<Pedidos*> Sistema::getTodosPedidos()
{
	return this->todosPedidos;
}

vector<Lanche*> Sistema::getTodosLanches()
{
	return this->todosLanches;
}

bool Sistema::verificaExistenciaLanchonete(int codigo)
{
	for(Lanchonete *l : this->todasLanchonetes){
		if (l->getCodigo() == codigo){
			return false;
		}
	}		
	return true;
}

