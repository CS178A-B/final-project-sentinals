package com.example.cs178_myfirstapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TCP extends AppCompatActivity {
    EditText el;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_t_c_p);

        el = (EditText)findViewById(R.id.tcp_message);

        Thread myThread = new Thread(new TCPThread() );
        myThread.start();

    }

    class TCPThread implements  Runnable {
        Socket s;
        ServerSocket ss;
        InputStreamReader isr;
        BufferedReader bufferedReader;
        String msg;
        Handler h = new Handler();

        @Override
        public void run() {
            try {
                ss = new ServerSocket(7801);
                while (true) {
                    s = ss.accept();
                    isr = new InputStreamReader(s.getInputStream());
                    bufferedReader = new BufferedReader(isr);
                    msg = bufferedReader.readLine();
                    
                    h.post(new Runnable() {
                        @Override
                        public void run() {
                            Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_SHORT).show();
                        }
                    });
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public void send(View V) {
        TCP_sender tcp_sender = new TCP_sender();
        tcp_sender.execute(el.getText().toString());
    }
}
