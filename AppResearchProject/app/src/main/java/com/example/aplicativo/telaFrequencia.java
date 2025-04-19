//telaFrequencia
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

public class telaFrequencia extends AppCompatActivity {

    private Button Voltar4;
    private EditText CaixaFrequencia;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tela_frequencia);

        Voltar4 = findViewById(R.id.Voltar4XML);

        Voltar4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar4Intent = new Intent(telaFrequencia.this, pagSaude.class);
                startActivity(voltar4Intent);
            }
        });

    }


    View.OnClickListener handler = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            CaixaFrequencia = findViewById(R.id.frequenciadadosXML);
            if(CaixaFrequencia.getText().equals()=> 100 && <60)
            {
                Toast.makeText(telaFrequencia.this, "Procure seu médico imediatamente", Toast.LENGTH_SHORT).show();
            }else{
                Toast.makeText(telaFrequencia.this, "Seu batimento cardíaco está normal", Toast.LENGTH_SHORT).show();
            }
        }
};