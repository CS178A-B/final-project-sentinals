package com.example.cs178_myfirstapp;

import android.util.Log;

//import com.google.firebase.iid.FirebaseInstanceId;
import com.google.firebase.messaging.FirebaseMessagingService;

public class MyFirebaseMessagingService extends FirebaseMessagingService {
    @Override
    public void onNewToken(String token) {
        Log.d("TAG", "the token refreshed: " + token);
    }
}


