class MyString
{
    int m_length;
    char * m_string;
public:
    MyString():m_length(0),m_string(nullptr){}
    MyString(const char * rhs):m_length(0),m_string(rhs){std::string s(m_string);m_length=s.size();}
    MyString(const MyString& rhs);
    MyString& operator= (const MyString& rhs);
    ~MyString();
};
MyString& MyString::operator= (const MyString& rhs)
{
     if(&rhs == this)
            return *this;
        char *temp = m_string;
        int ltemp  = m_length;
        if(rhs.m_string!=nullptr)
        {
            m_string = new(std::nothrow) char[m_length+1];
            if(m_string!=nullptr)
            {
                memcpy(m_string, rhs.m_string, m_length+1);
                m_length=rhs.m_length;
                if(temp != nullptr)
                    delete temp;
            }
            else
            {
                m_string=temp;
                m_length=ltemp;
            }
        }
        return *this;
}

MyString::MyString(const MyString& rhs)
{
    m_length = rhs.m_length;
    m_string = nullptr;
    if(rhs.m_string!=nullptr)
    {
        m_string=new (std::no_throw) char[m_length+1];
        if(m_string != nullptr)
        {
            memcpy(m_string, rhs.m_string, length+1);
        }
    }
}

MyString::~MyString()
{
    if(m_string!=nullptr)
    {
        delete m_string;
    }
}

