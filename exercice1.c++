#include <iostream>
#include <string>
using namespace std;

class Configuration
{

private:
    static Configuration *configuration;
    string chemin;
    string user;
    string password;

    Configuration(string chemin, string user, string password)
    {
        this->chemin = chemin;
        this->password = password;
        this->user = user;
    }

public:
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    static Configuration *getInstance(string chemin, string user, string password)
    {
        if (configuration == nullptr)
        {
            configuration = new Configuration(chemin, user, password);
        }
        return configuration ;
    }
    void afficherParametres(){
        std::cout << "chemin : "<<this->chemin<<"  user : "<<this->user<<"  password : "<<this->password<< std::endl;
    }
};
Configuration* Configuration::configuration = nullptr;

int main(int argc, char const *argv[])
{
    Configuration *configuration = Configuration::getInstance("/opt","oussama","123");
    configuration->afficherParametres();

    Configuration* config2 = Configuration::getInstance("/etc", "ahmed", "456");
    config2->afficherParametres();

    std::cout << "adresse 1 : "<<configuration<< std::endl;
    std::cout << "adresse 2 : "<<config2<< std::endl;
    
    return 0;
}

