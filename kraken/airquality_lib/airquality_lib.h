#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <android-base/properties.h>   // Função GetBoolProperty
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devtitans::airquality {       // Pacote Airquality

class AirQuality {
    public:
        /**
         * Verifica se o diretório /sys/kernel/airquality existe. Se existir
         * o dispositivo AirQuality está conectado via USB. Caso contrário,
         * verifica a propriedade devtitans.airquality.allow_simulated
         * para ver se valores simulados podem ser usados.
         *
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         *      2: simulado (disp. não encontrado, mas usando valores simulados)
         */
        int connect();

        /**
         * Acessa e seta a intensidade do led.
         *
         * Valor retornado/setado:
         *      0: led desligado
         *      1 a 99: led ligado com intensidade ledValue
         *      100: led ligado com intensidade máxima
         */
        int getPM10();
        int getPM25();
        int getDHT();
        int getMQ();

    private:
       
        int readFileValue(string file);

        int simPM10Value = 1180;
        int simPM25Value = 1950;
        int simDHTValue = 1180;
        int simMQValue = 1950;

};

} // namespace