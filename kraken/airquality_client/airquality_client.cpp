#include "airquality_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::airquality {      // Entra no pacote devtitans::hello

void AirqualityClient::start(int argc, char **argv) {
    cout << "Cliente AirQuality!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-pm10, get-pm25, get-ldr, get-co, get-smoke, get-tmp, get-hum" << endl;
        exit(1);
    }

    AirQuality airquality;             // Classe da biblioteca Airquality

    if (!strcmp(argv[1], "get-pm10")) {
        cout << "Valor de PM10: " << airquality.getPM10() << endl;
    }
    else if (!strcmp(argv[1], "get-pm25")) {
        cout << "Valor de PM25: " << airquality.getPM25() << endl;
    }
    else if (!strcmp(argv[1], "get-ldr")) {
        cout << "Valor de Umidade: " << airquality.getLDR() << endl;
    }
    else if (!strcmp(argv[1], "get-co")) {
        cout << "Valor de Gás: " << airquality.getCO() << endl;
    }
    else if (!strcmp(argv[1], "get-smoke")) {
        cout << "Valor de Gás: " << airquality.getSMOKE() << endl;
    }
    else if (!strcmp(argv[1], "get-tmp")) {
        cout << "Valor de Gás: " << airquality.getTMP() << endl;
    }
    else if (!strcmp(argv[1], "get-hum")) {
        cout << "Valor de Gás: " << airquality.getHUM() << endl;
    }
    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
    /*
    // Comando get-luminosity
    else if (!strcmp(argv[1], "get-luminosity")) {
        cout << "Luminosidade atual: " << airquality.getLuminosity() << endl;
    }

    // Comandos get-threshold e set-threshold
    else if (!strcmp(argv[1], "get-threshold")) {
        cout << "Valor do Threshold: " << airquality.getThreshold() << endl;
    }
    else if (!strcmp(argv[1], "set-threshold")) {
        int thresholdValue = atoi(argv[2]);
        if (airquality.setThreshold(thresholdValue))
            cout << "Valor do Threshold setado para " << thresholdValue << endl;
        else
            cout << "Erro ao setar valor do Threshold para " << thresholdValue << endl;
    }

    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }*/
}

} // namespace



// MAIN

using namespace devtitans::airquality; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    AirqualityClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}
