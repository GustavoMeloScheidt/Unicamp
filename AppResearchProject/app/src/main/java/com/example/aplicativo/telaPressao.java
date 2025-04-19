//telaPressao
package com.example.aplicativo;

import android.content.Intent;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.aplicativo.databinding.ActivityMainBinding;

public class telaPressao extends AppCompatActivity {

    private Button Voltar6;
    private EditText CaixaPressao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tela_glicose);

        Voltar6 = findViewById(R.id.Voltar5XML);

        Voltar6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar6Intent = new Intent(telaPressao.this, pagSaude.class);
                startActivity(voltar6Intent);
            }
        });

        View.OnClickListener handler = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CaixaPressao = findViewById(R.id.pressaodadosXML);
                if(CaixaPressao.getText().equals()=> 130 && <80)
                {
                    Toast.makeText(telaPressao.this, "Procure seu médico imediatamente", Toast.LENGTH_SHORT).show();
                }else{
                    Toast.makeText(telaPressao.this, "Sua pressão está normal", Toast.LENGTH_SHORT).show();
                }
            }
        };


    }}