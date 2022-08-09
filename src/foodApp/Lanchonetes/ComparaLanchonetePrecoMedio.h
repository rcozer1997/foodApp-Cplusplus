#pragma once

#include "Lanchonete.h"

namespace foodApp::Lanchonetes
{

	using Comparator = java::util::Comparator;

	class ComparaLanchonetePrecoMedio : public Comparator<Lanchonete*>
	{
	public:
		virtual int compare(Lanchonete *a, Lanchonete *b);
	};

}
