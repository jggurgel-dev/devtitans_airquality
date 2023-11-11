# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_kraken
PRODUCT_DEVICE := kraken
PRODUCT_BRAND := KrakenBrand
PRODUCT_MODEL := KrakenModel

PRODUCT_PACKAGES += \
	airquality_client

BOARD_SEPOLICY_DIRS += device/devtitans/kraken/sepolicy

# AirQuality AIDL Interface
PRODUCT_PACKAGES += devtitans.airquality

# AirQuality Binder Service
PRODUCT_PACKAGES += devtitans.airquality-service

# Device Framework Matrix (Declara que o nosso produto Kraken precisa do serviço airquality)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devtitans/kraken/device_framework_matrix.xml

# Cliente de Linha de Comando para o Serviço AirQuality
PRODUCT_PACKAGES += airquality_service_client

# Manager
PRODUCT_PACKAGES += devtitans.airqualitymanager
