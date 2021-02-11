package com.example.myfirstapp

import android.app.*
import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.EditText
import androidx.annotation.RequiresApi
import androidx.core.app.NotificationCompat

const val EXTRA_MESSAGE = "com.example.myfirstapp.MESSAGE"

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    /*val textTitle = "Test Notification"
    var builder = NotificationCompat.Builder(this, CHANNEL_ID)
            .setSmallIcon(R.drawable.Test_Notification)
            .setContentTitle(textTitle)
            .setContentText(EXTRA_MESSAGE)
            .setPriority(NotificationCompat.PRIORITY_DEFAULT)*/
    /** Called when the user taps the Send button */
    fun sendMessage(view: View) {
        // Do something in response to button
        val editText = findViewById<EditText>(R.id.editTextTextPersonName)
        val message = editText.text.toString()
        val intent = Intent(this, DisplayMessageActivity::class.java).apply {
            putExtra(EXTRA_MESSAGE, message)
        }
        startActivity(intent)
    }



    fun sendMessage2(view: View)
    {
        // this is a temporary file that holds the channel value
        val sharedPref = getSharedPreferences(getString(R.string.preference_file_key) , Context.MODE_PRIVATE)
        // this is the notification channel number
        var notificationNumber = sharedPref.getInt("notificationNumber", 0);
        // title of the notification
        val title = "Sentry Alert"
        // temp value to get the text from the message box
        val editText = findViewById<EditText>(R.id.editTextTextPersonName)
        // converting the text into the notification message
        val message = editText.text.toString()
        //creating the notification mannager to intialize notificatons
        val mNotificationManager = getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        //creating a channel for android version 7.0+
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            val channel = NotificationChannel("YOUR_CHANNEL_ID",
                    "YOUR_CHANNEL_NAME",
                    NotificationManager.IMPORTANCE_DEFAULT)
            channel.description = "YOUR_NOTIFICATION_CHANNEL_DESCRIPTION"
            mNotificationManager.createNotificationChannel(channel)
        }
        // building the notification
        val mBuilder = NotificationCompat.Builder(applicationContext, "YOUR_CHANNEL_ID")
                .setSmallIcon(R.mipmap.ic_launcher) // notification icon
                .setContentTitle(title) // title for notification
                .setContentText(message)// message for notification
                .setAutoCancel(true) // clear notification after click
        // giving the action that will happen when the user presses the notfication
        val intent = Intent(applicationContext, MainActivity::class.java)
        // defining pending intent for the notification to wait for an action
        val pi = PendingIntent.getActivity(this, 0, intent, PendingIntent.FLAG_UPDATE_CURRENT)
        // assigning the intent to the notification
        mBuilder.setContentIntent(pi)
        //sending the notification on the channel number
        mNotificationManager.notify( notificationNumber, mBuilder.build())
        //updating the notification channel number to a different value to allow for multiple notifications
        val editor = sharedPref.edit()
        notificationNumber++
        editor.putInt("notificationNumber", notificationNumber)
        editor.apply()


    }

    /*fun showNotification(title: String, message: String) {
        val mNotificationManager = getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            val channel = NotificationChannel("YOUR_CHANNEL_ID",
                    "YOUR_CHANNEL_NAME",
                    NotificationManager.IMPORTANCE_DEFAULT)
            channel.description = "YOUR_NOTIFICATION_CHANNEL_DESCRIPTION"
            mNotificationManager.createNotificationChannel(channel)
        }
        val mBuilder = NotificationCompat.Builder(applicationContext, "YOUR_CHANNEL_ID")
                .setSmallIcon(R.mipmap.ic_launcher) // notification icon
                .setContentTitle(title) // title for notification
                .setContentText(message)// message for notification
                .setAutoCancel(true) // clear notification after click
        val intent = Intent(applicationContext, DisplayMessageActivity::class.java)
        val pi = PendingIntent.getActivity(this, 0, intent, PendingIntent.FLAG_UPDATE_CURRENT)
        mBuilder.setContentIntent(pi)
        mNotificationManager.notify(0, mBuilder.build())
    }
    */
}