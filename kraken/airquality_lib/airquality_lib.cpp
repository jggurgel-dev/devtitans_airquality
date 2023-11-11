#include "airquality_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base;                         // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devtitans::airquality{                       // Entra no pacote devtitans::airquality

int AirQuality::connect() {
    char dirPath[] = "/sys/kernel/airquality";
    struct stat dirStat;
    if (stat(dirPath, &dirStat) == 0)
        if (S_ISDIR(dirStat.st_mode))
            return 1;                                  // Se o diretório existir, retorna 1

    // Diretório não existe, vamos verificar a propriedade
    bool allowSimulated = GetBoolProperty("devtitans.airquality.allow_simulated", true);
    if (!allowSimulated)
        return 0;                                      // Dispositivo não encontrado
    else
        return 2;                                      // Usando valores simulados
}

int AirQuality::readFileValue(string file) {
    int connected = this->connect();

    if (connected == 2) {                               // Usando valores simulados
        if (file == "pm10")
            return this->simPM10Value;
        else if (file == "pm25")
            return this->simPM25Value;
        else {
            // "ldr" (luminosity): Gera um número aleatório entre 0 e 100
            random_device dev;
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> dist100(0,100);
            return (int) dist100(rng);
        }
    }

    else if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        int value;
        string filename = string("/sys/kernel/airquality/") + file;
        ifstream file(filename);                        // Abre o arquivo do módulo do kernel

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file >> value;                              // Lê um inteiro do arquivo
            file.close();
            return value;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return -1;
}

//bool Smartlamp::writeFileValue(string file, int value) {
//    int connected = this->connect();
//
//    if (connected == 2) {                                // Usando valores simulados
//        if (file == "led") {
//            this->simLedValue = value;
//            return true;
//        }
//        else if (file == "threshold") {
//            this->simThresholdValue = value;
//            return true;
//        }
//    }
//
//    else if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
//        string filename = string("/sys/kernel/smartlamp/") + file;
//        ofstream file(filename, ios::trunc);            // Abre o arquivo limpando o seu conteúdo
//
//        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
//            file << value;                              // Escreve o ledValue no arquivo
//            file.close();
//            return true;
//        }
//    }
//
//    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
//    return false;
//}

int AirQuality::getPM10() {
    return this->readFileValue("pm10");
}

int AirQuality::getPM25() {
	return this->readFileValue("pm25");
}

} // namespace
