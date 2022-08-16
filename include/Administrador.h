#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../include/Sistema.h"
#include "../include/Usuario.h"

using namespace std;
//using Sistema = foodApp::Sistema;

class Administrador : public Usuario
{
public:
	//Scanner *s = new Scanner(System::in);
	//Administrador();
	virtual ~Administrador()
	{
		//delete s;
	}

	Administrador(Sistema *sistema);

	Administrador(vector<string> &list);

	void menu() override;

	virtual void relatorioGeral();

	virtual int retornaTotalClientes();
};

#endif
