package com.example.cs178_myfirstapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

/*public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}*/

public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.example.cs128_MyFirstApp.MESSAGE";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    //called when user taps send button
    public void sendMessage(View view) {
        //do something
        //intent - obj that provides runtime binding bw separate components like two activities
        Intent intent = new Intent(this, DisplayMessageActivity.class);
        //above's second arg is the activity, or 'intent', to start

        EditText editText = (EditText) findViewById(R.id.editText);
        String message = editText.getText().toString();

        //
        intent.putExtra(EXTRA_MESSAGE, message);
        //basically starts the displaymessageactivity "string"
        startActivity(intent);
    }

    public void videoActivity(View v) {
        Intent i = new Intent(this, video_activity.class);
        startActivity(i);
    }


}
