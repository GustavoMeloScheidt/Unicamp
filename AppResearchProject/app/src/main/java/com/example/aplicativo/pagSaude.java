//pagSaude
package com.example.aplicativo;

import android.content.Intent;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.aplicativo.databinding.ActivityMainBinding;

public class pagSaude extends AppCompatActivity {

    private ImageButton frequênciaSaude;
    private ImageButton pressãoSaude;
    private ImageButton glicoseSaude;
    private Button Voltar3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pag_saude);

        frequênciaSaude = findViewById(R.id.freqXML);
        pressãoSaude = findViewById(R.id.pressaoXML);
        glicoseSaude = findViewById(R.id.glicoseXML);
        Voltar3 = findViewById(R.id.Voltar3XML);

        frequênciaSaude.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent frequenciaIntent = new Intent(pagSaude.this, telaFrequencia.class);
                startActivity(frequenciaIntent);
            }
        });
        pressãoSaude.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent pressaoIntent = new Intent(pagSaude.this, telaPressao.class);
                startActivity(pressaoIntent);
            }
        });
        glicoseSaude.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent glicoseIntent = new Intent(pagSaude.this, telaGlicose.class);
                startActivity(glicoseIntent);
            }
        });
        Voltar3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar3Intent = new Intent(pagSaude.this, pagInicial.class);
                startActivity(voltar3Intent);
            }
        });
    }

}