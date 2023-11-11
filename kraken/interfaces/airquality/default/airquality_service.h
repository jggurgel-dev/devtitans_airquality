#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/airquality/BnAirQuality.h>            // Criado pelo AIDL automaticamente

#include "airquality_lib.h"                                   // Classe AirQuality (biblioteca)

using namespace devtitans::airquality;

namespace aidl::devtitans::airquality {

class AirQualityService : public BnAirQuality {
    public:
        ndk::ScopedAStatus connect(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getPM10(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getPM25(int32_t* _aidl_return) override;

    private:
        AirQuality airquality;                                 // Biblioteca
};

}
