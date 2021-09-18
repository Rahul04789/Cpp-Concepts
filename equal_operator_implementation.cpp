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
	if(&rhs == this)
            return *this;
        char *temp = m_pchar;
        int ltemp  = length;
        m_pchar=nullptr;
        if(rhs.m_pchar!=nullptr)
        {
            m_pchar = new(std::nothrow) char[length+1];
            if(m_pchar!=nullptr)
            {
                memcpy(m_pchar, rhs.m_pchar, length+1);
                length=rhs.length;
                if(temp != nullptr)
                    delete temp;
            }
            else
            {
                m_pchar=temp;
                length=ltemp;
            }
        }
        return *this;
}
