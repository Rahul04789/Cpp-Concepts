#include <cstring>
#include <map>
class MyString{
    int i;
    char *m_Ptr;
public:
    MyString(int i= 0, const char* ptr = nullptr):i{i}, m_Ptr{nullptr}{
        cout<<"CALLING constructor"<<endl;
        if(ptr != nullptr) {
            int l=strlen(ptr);
            m_Ptr = new(std::nothrow) char[l+1];
            if(m_Ptr != nullptr)
                strcpy(m_Ptr, ptr);
        }
    }
    MyString(const MyString &  val): m_Ptr{nullptr} {
        cout<<"CALLING MyString(const MyString & val)"<<endl;
        i=val.i;
        if(val.m_Ptr != nullptr) {
            int l = strlen(val.m_Ptr);
            m_Ptr = new(std::nothrow) char[l+1];
            if(m_Ptr != nullptr)
                strcpy(m_Ptr, val.m_Ptr);
        }
    }
    MyString (MyString && val) {
        cout<<"CALLING MyString(MyString && val)"<<endl;
        i=val.i;
        m_Ptr=val.m_Ptr;
        val.m_Ptr=nullptr;
    }
    MyString& operator=(const MyString & val) {
        cout<<"CALLING operator=(const MyString & val)"<<endl;
        if(this == &val)
            return *this;
        if(val.m_Ptr != nullptr) {
            int l = strlen(val.m_Ptr);
            char * optr = m_Ptr;
            m_Ptr = new(std::nothrow) char[l+1];
            if(m_Ptr==nullptr) {
                m_Ptr=optr;
            }
            else {
                i=val.i;
                strcpy(m_Ptr, val.m_Ptr);
                delete optr;
            }
        }
        return *this;
    }
    /*
     * MyString& operator=(MyString && val) is called when:
     * 1) Assigning a temporary object directly:
     *       MyString a;
     *       a = MyString(10, "Hello"); // Calls the move assignment operator
     * 2) Using std::move to convert an lvalue to an rvalue:
     *      MyString a(10, "Hello");
     *      MyString b;
     *      b = std::move(a); // Calls the move assignment operator
     */
    MyString& operator=(MyString && val) {
        cout<<"CALLING operator=(MyString && val)"<<endl;
        if(this == &val)
            return *this;
        delete []m_Ptr;
        i=val.i;
        m_Ptr=val.m_Ptr;
        val.m_Ptr=nullptr;
        return *this;
    }
    ~MyString() {
        cout<<"CALLING Destructor"<<endl;
        if(m_Ptr!= nullptr)
            delete []m_Ptr;
    }
    void print() const {
        qDebug()<<"i="<<i<<", m_Ptr="<<m_Ptr;
    }
    /*
     * When we create a std::map<MyString int> M; then in order to store key in some order we need to overload bool operator<(const MyString& val) const
     * and it must be const
     */
    bool operator<(const MyString& val) const{
        return this->i<val.i;
    }
    /*
    * The operator<< cannot be a member function of the MyString class because the left-hand operand for this operator is a std::ostream object,
    * not a MyString object. For the << operator to work with std::ostream as the left operand and MyString as the right operand, it must be defined
    * as a non-member function. This allows the << operator to access both the std::ostream and MyString objects correctly.
    */
    friend std::ostream& operator<<(std::ostream& os, const MyString& var){
        os << "i: " << var.i << ", m_Ptr: " << (var.m_Ptr ? var.m_Ptr : "null");
        return os;
    }
    /*
     * Implicit Conversion: The operator bool() can be used for both implicit and explicit conversions. This means that objects of the
     * MyString class can be implicitly converted to bool in contexts where a boolean value is expected.
     *
     * Explicit Conversion: The explicit operator bool() can only be used for explicit conversions. This means that objects of the MyString
     * class cannot be implicitly converted to bool; the conversion must be explicit. This prevents unintentional conversions and requires
     * the use of the static_cast operator or direct type conversion when you want to convert an instance of MyString to bool.
     */
    explicit operator bool() {
        return false;
    }
    explicit operator string() {
        return std::string(m_Ptr);
    }
};

int main(int argc, char *argv[])
{
    char p[] = "HELL";
    MyString t6(10, p);
    MyString t7(10, p);
    MyString t8(14, p);

    std::map<Test, int> M;
    M.insert({t6, 300});
    M.insert({t7, 30});
    M.insert({t8, 400});    
    for(auto& [key, val]: M) {
        key.print();     // here print() must be const function bec key is always const.
    }
    return 0;
}
