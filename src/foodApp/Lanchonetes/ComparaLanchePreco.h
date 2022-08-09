#pragma once

#include "Lanche.h"

namespace foodApp::Lanchonetes
{

	using Comparator = java::util::Comparator;

	class ComparaLanchePreco : public Comparator<Lanche*>
	{
	public:
		virtual int compare(Lanche *a, Lanche *b);
	};

}
