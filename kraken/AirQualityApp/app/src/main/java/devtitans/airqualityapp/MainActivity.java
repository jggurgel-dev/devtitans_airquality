package devtitans.airqualityapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.graphics.Color;
import android.util.Log;
import android.view.View;
import android.widget.*;

import devtitans.airqualityapp.R;
import devtitans.airqualitymanager.AirQualityManager;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "DevTITANS.AirQualityApp";
    private TextView textStatus, textPM10, textPM25;
    private AirQualityManager manager;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus =     findViewById(R.id.textStatus);
        textPM10 =     findViewById(R.id.textPM10);
        textPM25 =     findViewById(R.id.textPM25);

        manager = AirQualityManager.getInstance();

        updateAll(null);
    }

    public void updateAll(View view) {
        Log.d(TAG, "Atualizando dados do dispositivo ...");

        textStatus.setText("Atualizando ...");
        textStatus.setTextColor(Color.parseColor("#c47e00"));

        try {
            float pm10 = new Float(manager.getPM10())/100;
            textPM10.setText(String.valueOf(pm10));

            float pm25 = new Float(manager.getPM25())/100;
            textPM25.setText(String.valueOf(pm25));

            int status = manager.connect();
            if (status == 0) {
                textStatus.setText("Desconectado");
                textStatus.setTextColor(Color.parseColor("#73312f"));
            }
            else if (status == 1) {
                textStatus.setText("Conectado");
                textStatus.setTextColor(Color.parseColor("#6d790c"));
            }
            else {
                textStatus.setText("Simulado");
                textStatus.setTextColor(Color.parseColor("#207fb5"));
            }

        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();
            Log.e(TAG, "Erro atualizando dados:", e);
        }

    }
}