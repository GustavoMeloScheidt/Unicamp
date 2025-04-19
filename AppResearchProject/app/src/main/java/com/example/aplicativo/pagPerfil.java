//pagPerfil
package com.example.aplicativo;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;
import android.widget.Button;

import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.aplicativo.databinding.ActivityMainBinding;

public class pagPerfil extends AppCompatActivity {

    private Button Voltar2;
    private Button Web;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pag_perfil);

        Voltar2 = findViewById(R.id.Voltar2XML);

        Voltar2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent voltar2Intent = new Intent(pagPerfil.this, pagInicial.class);
                startActivity(voltar2Intent);
            }
        });

        Web=findViewById(R.id.webXML);

        Web.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent WebIntent = new Intent(pagPerfil.ACTIVITY_SERVICE, Uri.parse("https://www.who.int/pt"));
            }
        });

    }}