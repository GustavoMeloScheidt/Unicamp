//pagInicial
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

public class pagInicial extends AppCompatActivity {

    private ImageButton Saude;
    private ImageButton Perfil;
    private Button Voltar1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pag_inicial);

        Voltar1 = findViewById(R.id.Voltar1XML);
        Saude = findViewById(R.id.imageButton1);
        Perfil = findViewById(R.id.imageButton2);

        Saude.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent SaudeIntent = new Intent(pagInicial.this, pagSaude.class);
                startActivity(SaudeIntent);
            }
        });

        Perfil.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent PerfilIntent = new Intent(pagInicial.this, pagPerfil.class);
                startActivity(PerfilIntent);
            }
        });

        Voltar1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar1Intent = new Intent(pagInicial.this, MainActivity.class);
                startActivity(voltar1Intent);
            }
        });
    }
}