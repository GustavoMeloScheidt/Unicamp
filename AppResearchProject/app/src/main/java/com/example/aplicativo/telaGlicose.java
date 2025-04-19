//telaGlicose
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

public class telaGlicose extends AppCompatActivity {

    private Button Voltar5;
    private EditText CaixaGlicose;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tela_glicose);

        Voltar5 = findViewById(R.id.Voltar5XML);

        Voltar5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar5Intent = new Intent(telaGlicose.this, pagSaude.class);
                startActivity(voltar5Intent);
            }
        });

        View.OnClickListener handler = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CaixaGlicose = findViewById(R.id.glicosedadosXML);
                if(CaixaGlicose.getText().equals()=> 100 && <65)
                {
                    Toast.makeText(telaGlicose.this, "Procure seu médico imediatamente", Toast.LENGTH_SHORT).show();
                }else{
                    Toast.makeText(telaGlicose.this, "Sua taxa de glicose está normal", Toast.LENGTH_SHORT).show();
                }
            }
        };
    }



}