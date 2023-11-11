#include "airquality_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::airquality {      // Entra no pacote devtitans::hello

void AirQualityClient::start(int argc, char **argv) {
    cout << "Cliente AirQuality!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-pm10, get-pm25d" << endl;
        exit(1);
    }

    AirQuality airquality;             // Classe da biblioteca AirQuality

    // Comandos get-led e set-led
    if (!strcmp(argv[1], "get-pm10")) {
        cout << "Valor de PM10: " << airquality.getPM10() << endl;
    }
    else if (!strcmp(argv[1], "get-pm25")) {
        cout << "Valor de PM25: " << airquality.getPM25() << endl;
    }
    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::airquality; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    AirQualityClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}
