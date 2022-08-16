#ifndef PROPRIETARIO_H_
#define PROPRIETARIO_H_

#include "../include/Arquivos.h"
#include "../include/Sistema.h"
#include "../include/Excecoes/CodigoNaoEncontradoException.h"
#include "../include/Excecoes/CodigoReplicadoException.h"
#include "../include/Lanchonete.h"
#include "../include/Pedidos.h"
#include "../include/Usuario.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Proprietario : public Usuario
{
public:
	vector<Lanchonete*> lanchonetes = vector<Lanchonete*>();
	Arquivos *arq;

	virtual ~Proprietario();

	Proprietario(Sistema *sistema);

	Proprietario(vector<string> &list);

	void menu() override;

	virtual void cadastraLanchonete();

	virtual void removeLanchonete();

	virtual void lerLanchonetesProp();

	virtual void removerLanchonetesProprietario();

	virtual void exibirLanchonetes(vector<Lanchonete*> &lanchonetes);

	virtual void cadastraLancheLanchonete();

	virtual Lanchonete *buscarLanchonete(int codigo);

	virtual void visualizarPedidosLanchonete();

	virtual void removePedido();

	virtual void listaLanchonetesProprietario();

	virtual bool verificaProprietario(Lanchonete *l);

	virtual vector<Lanchonete*> getLanchonetes();

	virtual void removerCadastro(const string &email, vector<Usuario*> &listaUsuarios);
};

#endif
