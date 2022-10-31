# include <iostream>

class Log {

public:
    enum logLevel 
    {
        Info = 0,
        Warn = 1,
        Error = 2,
        Verbos = 3 
    };


private:
    logLevel m_logLevel;


public:
    void setLevel(logLevel logLevel)
    {
        m_logLevel = logLevel;
    }
    
    void info(const char *data)
    {
        if(m_logLevel  >= Info)
            std::cout << "[INFO]: " << data << std::endl;
    }
  
    void warn(const char *data)
    {
        if(m_logLevel  >= Warn)
            std::cout << "[WARN]: " << data << std::endl;
    }
    

    void error(const char *data)
    {
        if(m_logLevel  >= Error)
            std::cout << "[ERROR]: " << data << std::endl;
    }
    
    void verbos(const char *data)
    {
        if(m_logLevel  >= Verbos)
            std::cout << "[VERBOS]: " << data << std::endl;
    }
};


int main(void)
{
   Log uartLog;
   uartLog.setLevel(Log::Error);
   uartLog.info("init of drivers complete ");
   uartLog.warn("drivers are not init properly ");
   uartLog.error("drivers are not installed ");
   uartLog.verbos("drivers for uart 1,2,3 has some error ");
}