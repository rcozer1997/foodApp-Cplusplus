#ifndef USUARIO_H_
#define USUARIO_H_

#include "../include/Arquivos.h"
#include "../include/Sistema.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Sistema;
class Arquivos;

class Usuario {
private:
	string email;
	string senha;
public:
	string nome;
	int ident = 0; // 1 - Administrador , 2 - Proprietario , 3 - Cliente
	Sistema *sistema;
	Arquivos *arq;
	
	string toString();

	Usuario(Sistema *sistema);

	Usuario(vector<string> &list);

	virtual void gravaUsuariosArq(ofstream file);

	virtual string getEmail();

	virtual string getSenha();

	virtual string getNome();

	virtual int getIdent();

	virtual bool isProp();

	virtual void menu() = 0;

	virtual void removerCadastro(const string &email, vector<Usuario*> &listaUsuarios);
};

#endif
