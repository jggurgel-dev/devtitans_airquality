#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <android-base/properties.h>   // Função GetBoolProperty
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devtitans::airquality {       // Pacote Airquality

class Airquality {
    public:
        
        int connect();
        int getPM25();
        int getPM10();
        int getDHT();
        int getMQ();

    private:
       
        int readFileValue(string file);

        int simPM10Value = 1180;
        int simPM25Value = 1950;
};

} // namespace