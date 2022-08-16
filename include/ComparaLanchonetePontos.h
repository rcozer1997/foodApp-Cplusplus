/* #ifndef COMPARALANCHONETEPONTOS_H_
#define COMPARALANCHONETEPONTOS_H_

#include <iostream>
#include "Lanchonete.h"

using namespace std;

class ComparaLanchonetePontos : public Comparator<Lanchonete*>
{
public:
	ComparaLanchonetePontos();
	virtual ~ComparaLanchonetePontos();
	virtual int compare(Lanchonete *a, Lanchonete *b);
};

#endif
 */