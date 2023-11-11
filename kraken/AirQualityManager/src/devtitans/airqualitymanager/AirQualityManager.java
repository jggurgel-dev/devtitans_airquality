package devtitans.airqualitymanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.airquality.IAirQuality;                      // Criado pelo AIDL

public class AirQualityManager {
    private static final String TAG = "DevTITANS.AirQualityManager";
    private IBinder binder;
    private IAirQuality service;

    private static AirQualityManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada. 
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private AirQualityManager() {
        Log.d(TAG, "Nova (única) instância do AirQualityManager ...");

        binder = ServiceManager.getService("devtitans.airquality.IAirQuality/default");
        if (binder != null) {
            service = IAirQuality.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço AirQuality acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço AirQuality!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static AirQualityManager getInstance() {
        if (instance == null)
            instance = new AirQualityManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getPM10() throws RemoteException {
        Log.d(TAG, "Executando método getPM10() ...");
        return service.getPM10();
    }

    public int getPM25() throws RemoteException {
        Log.d(TAG, "Executando método getPM25() ...");
        return service.getPM25();
    }

}
