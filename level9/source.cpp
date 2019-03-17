/*
	source9.cpp
*/

#include <unistd.h>
#include <string.h>

class N;

unsigned int		operator+(N & lhs, N & rhs);
unsigned int		operator-(N & lhs, N & rhs);

void *				g_vtable[2] = { (void *)operator+, (void *)operator- };

class N
{
public:

	void			**func;
	char			annotation[100];
	unsigned int	value;

	N(unsigned int v) : value(v)
	{
		this->func = (void **) &g_vtable;
	}

	void			setAnnotation(char *str)
	{
		memcpy(this->annotation, str, strlen(str));
	}
};

unsigned int		operator+(N & lhs, N & rhs)
{
	return (lhs.value + rhs.value);
}

unsigned int		operator-(N & lhs, N & rhs)
{
	return (lhs.value - rhs.value);
}

int					main(int argc, char **argv)
{
	if (argc <= 1)
		_exit(1);

	N				*a = new N(5);
	N				*b = new N(6);

	a->setAnnotation(argv[1]);
	return ( (unsigned int (*)(N &, N &)) (b->func)[0] )(*b, *a);
}
