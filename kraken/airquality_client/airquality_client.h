#pragma once                      // Inclui esse cabeçalho apenas uma vez

#include <iostream>               // std::cout (char-out) e std::endl (end-line)
#include <string.h>               // Função strcmp
#include <stdlib.h>               // Função atoi

#include "airquality_lib.h"        // Classe Airquality

namespace devtitans::airquality {  // Pacote que a classe abaixo pertence

class AirqualityClient {           // Classe

    public:
        void start(int argc, char **argv);

};

} // namespace