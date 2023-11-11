#include <android/binder_manager.h>
#include <aidl/devtitans/airquality/IAirQuality.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devtitans::airquality;     // IAirQuality
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<IAirQuality> service;
    service = IAirQuality::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.airquality.IAirQuality/default")));
    
    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_return1;
    int32_t _aidl_return2;
    ScopedAStatus status1 = service->getPM10(&_aidl_return1);
    ScopedAStatus status2 = service->getPM25(&_aidl_return2);
    int pm10 = static_cast<int32_t>(_aidl_return1);
    int pm25 = static_cast<int32_t>(_aidl_return2);
    cout << "PM10: " << pm10 << endl;
    cout << "PM25: " << pm25 << endl;
    
    return 0;
}
