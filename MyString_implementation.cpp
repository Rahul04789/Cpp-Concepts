class MyString
{
    int m_length;
    char * m_string;
public:
    MyString():m_length(0),m_string(nullptr){}
    MyString(const char * rhs):m_length(0),m_string(rhs){}
    MyString(const MyString& rhs);
    MyString& operator= (const MyString& rhs);
};
MyString& MyString::operator= (const MyString& rhs)
{
    if(&rhs == this)
        return *this;
    int l=m_length;
    char* pc=m_string;
    m_string=nullptr;
    m_length=rhs.m_length;
    m_string=new (std::no_throw) char[m_length+1];
    if(m_string != nullptr)
    {
        memcpy(m_string, rhs.m_string, m_length+1);
        if(pc!= nullptr)
            delete []pc;
    }
    else
    {
        m_length = l;
        m_string = pc;
    }
    return *this;
}

MyString::MyString(const MyString& rhs)
{
    m_string=nullptr;
    m_length=rhs.m_length;
    m_string=new (std::no_throw) char[m_length+1];
    if(m_string != nullptr)
    {
        memcpy(m_string, rhs.m_string, m_length+1);
    }
    else
    {
        m_length = 0;
        m_string = nullptr;
    }
}

