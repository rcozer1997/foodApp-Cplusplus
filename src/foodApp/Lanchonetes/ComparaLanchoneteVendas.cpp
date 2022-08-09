#include "ComparaLanchoneteVendas.h"

namespace foodApp::Lanchonetes
{
	using Comparator = java::util::Comparator;

	int ComparaLanchoneteVendas::compare(Lanchonete *a, Lanchonete *b)
	{
			return a->comparaVendas(b);
	}
}
