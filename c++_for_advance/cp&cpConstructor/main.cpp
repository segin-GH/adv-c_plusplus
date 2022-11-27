# include <iostream>
// # include <string>
# include <string.h>

class String
{
    private:
        char* m_buff;
        unsigned int m_size;
    
    public:
        String(const char* string)
        {
            m_size = strlen(string);
            m_buff = new char[m_size+1];
            memcpy(m_buff, string, m_size);
            m_buff[m_size] = 0;
        }
        
        ~String()
        {
            delete[] m_buff;
        }

    friend std::ostream& operator << (std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buff;
    return stream;
}

int main()
{
    String str = "luffy";
    std::cout << str << std::endl;
}
