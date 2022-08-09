#pragma once

#include <string>
#include <vector>

namespace foodApp::Lanchonetes
{

	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;

	class Lanche
	{
	public:
		int codigo = 0;
		std::wstring descricao;
		float preco = 0.0F;
		std::wstring nomeLanchonete;

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
		Lanche(int codigo, const std::wstring &descricao, float preco, const std::wstring &nomeLanchonete); //super();

		Lanche(std::vector<std::wstring> &list);

		virtual void gravaLanche(BufferedWriter *b);

		virtual std::wstring getNome();

		virtual int getCodigo();

		virtual std::wstring getDescricao();

		virtual float getPreco();

		virtual std::wstring getNomeLanchonete();

		virtual std::wstring toString();

		virtual int compareTo(Lanche *l);
	};

}
