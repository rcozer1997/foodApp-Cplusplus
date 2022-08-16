#include "../include/Usuario.h"
#include "../include/Sistema.h"
#include <iostream>
#include <fstream>

using namespace std;

string Usuario::toString()
{
	return "Usuario [nome=" + nome + ", email=" + email + ", senha=" + senha + ", ident=" + to_string(ident) + "]";
}

Usuario::Usuario(Sistema *sistema)
{
	wcout << "Nome: ";
	string nome;
	cin >> nome;
	wcout << "Email: ";
	string email;
	cin >> email;
	wcout << "Senha: ";
	string senha;
	cin >> senha;
	this->nome = nome;
	this->email = email;
	this->senha = senha;
	this->sistema = sistema;
}

Usuario::Usuario(vector<string> &list)
{
	this->nome = list[0];
	this->email = list[1];
	this->senha = list[2];
	this->ident = stoi(list[3]);
}

void Usuario::gravaUsuariosArq(ofstream file)
{
	file << this->nome << endl;
	file << this->email << endl;
	file << this->senha << endl;
	file << to_string(this->ident) << endl;
}

string Usuario::getEmail()
{
	return this->email;
}

string Usuario::getSenha()
{
	return this->senha;
}

string Usuario::getNome()
{
	return this->nome;
}

int Usuario::getIdent()
{
	return this->ident;
}

bool Usuario::isProp()
{
	if(this->ident == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Usuario::removerCadastro(const string &email, vector<Usuario*> &listaUsuarios)
{
	for(int i=0; i<listaUsuarios.size(); i++)
	{
		cout << listaUsuarios[i]->toString() << endl;
	}
	for(int i=0; i<listaUsuarios.size(); i++)
	{
		Usuario *u = listaUsuarios[i];
		if(u->getEmail() == email)
		{
			wcout << "Tem certeza que deseja remover o cadastro?" << endl;
			wcout << "1 - sim\n2 - Nao" << endl;
			int opcao;
			cin >> opcao;

			if(opcao == 1)
			{	
				std::remove(listaUsuarios.begin(), listaUsuarios.end(), u);
				//listaUsuarios.remove(u);
				wcout << "Cliente removido!" << endl;
				arq->salvaUsuariosArq(listaUsuarios);
				break;
			}
			else if(opcao == 2)
			{
				break;
			}
		}
	}
}




