#include "airquality_service.h"

namespace aidl::devtitans::airquality {
    ndk::ScopedAStatus AirQualityService::connect(int32_t* _aidl_return) {
        *_aidl_return = this->airquality.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus AirQualityService::getPM10(int32_t* _aidl_return) {
        *_aidl_return = this->airquality.getPM10();
        LOG(INFO) << "getPM10(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus AirQualityService::getPM25(int32_t* _aidl_return) {
        *_aidl_return = this->airquality.getPM25();
        LOG(INFO) << "getPM25(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }
}
