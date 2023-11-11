#include "airquality_service.h"

using namespace aidl::devtitans::airquality;                // AirQualityService (airquality_service.cpp)
using namespace std;                                       // std::shared_ptr
using namespace ndk;                                       // ndk::SharedRefBase

int main() {
    LOG(INFO) << "Iniciando AirQuality AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<AirQualityService> airquality_service = SharedRefBase::make<AirQualityService>();

    const string instance = std::string() + IAirQuality::descriptor + "/default";   // devtitans.airquality.IAirQuality/default
    binder_status_t status = AServiceManager_addService(airquality_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "AirQuality AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;                                   // Não deve chegar nunca aqui
}
