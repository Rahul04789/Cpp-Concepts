#include <new> //std::nothrow is defined in "new"
class X
{
	char *m_pchar;
	int length;
public:
	X():m_pchar{nullptr},length{0}{}
	X& operator=(const X& rhs);
};
X& X::operator=(const X& rhs)
{
	if(this == &rhs)
		return (*this);
	char * var = m_pchar;
	int l = length;
	m_pchar = nullptr;
	length = 0;
	m_pchar = new(std::nothrow) char[rhs.length];
	if(m_pchar != nullptr)
	{
		if(var != nullptr)
			delete []var;
		length = rhs.length;
		for(int i=0;i<=length; i++)
		{
			m_pchar[i] = rhs.m_pchar[i];
		}
	}
	else
	{
		m_pchar = var;
		length = l;
	}
	return (*this);
}
