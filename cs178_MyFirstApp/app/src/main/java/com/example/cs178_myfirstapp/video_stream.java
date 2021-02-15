package com.example.cs178_myfirstapp;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;
import android.widget.MediaController;
import android.widget.Toast;
import android.widget.VideoView;
import android.net.Uri;
import android.os.Bundle;

import com.devbrackets.android.exomedia.listener.OnPreparedListener;
import com.devbrackets.android.exomedia.ui.widget.EMVideoView;
import com.google.android.exoplayer2.ExoPlayerFactory;
import com.google.android.exoplayer2.SimpleExoPlayer;
import com.google.android.exoplayer2.extractor.DefaultExtractorsFactory;
import com.google.android.exoplayer2.extractor.ExtractorsFactory;
import com.google.android.exoplayer2.source.ExtractorMediaSource;
import com.google.android.exoplayer2.source.MediaSource;
import com.google.android.exoplayer2.trackselection.AdaptiveTrackSelection;
import com.google.android.exoplayer2.trackselection.DefaultTrackSelector;
import com.google.android.exoplayer2.trackselection.TrackSelector;
import com.google.android.exoplayer2.ui.SimpleExoPlayerView;
import com.google.android.exoplayer2.upstream.BandwidthMeter;
import com.google.android.exoplayer2.upstream.DefaultBandwidthMeter;
import com.google.android.exoplayer2.upstream.DefaultHttpDataSourceFactory;

public class video_stream extends AppCompatActivity {
    SimpleExoPlayerView exoPlayerView;
    SimpleExoPlayer exoPlayer;
    //String videourl = "https://imgur.com/7bMqysJ.mp4";

    EMVideoView emPlayer;

    EditText addr;
    Button connect;
    VideoView streamView;
    MediaController mediaController;

    private WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video_stream);

        addr = (EditText)findViewById(R.id.addr);
        connect = (Button)findViewById(R.id.connect);
        //streamView = (VideoView)findViewById(R.id.streamview);



        connect.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String s = addr.getEditableText().toString();
                //playStream(s);
                webView = (WebView)findViewById(R.id.webview_stream);
                webView.setWebViewClient(new WebViewClient()); //ensures webview in app and not in another browser
                webView.loadUrl(s);

               /* WebSettings webSettings = webView.getSettings();
                webSettings.setJavaScriptEnabled(true); */
            }
        });
    }

    private void playStream(String src) {
        Uri UriSrc = Uri.parse(src);
        //exoPlayerView=(SimpleExoPlayerView)findViewById(R.id.exovideo_stream);

        if(UriSrc == null) {
            Toast.makeText(video_stream.this,
                    "UriSrc == null", Toast.LENGTH_LONG).show();
        } else {
            /* streamView.setVideoURI(UriSrc);
            mediaController = new MediaController(this);
            streamView.setMediaController(mediaController);
            streamView.start(); */

            /* try {
                BandwidthMeter bandwidthMeter = new DefaultBandwidthMeter();
                TrackSelector trackSelector = new DefaultTrackSelector(new AdaptiveTrackSelection.Factory(bandwidthMeter));
                exoPlayer= ExoPlayerFactory.newSimpleInstance(this, trackSelector);
                //Uri videoUri = Uri.parse(src);
                DefaultHttpDataSourceFactory dataSourceFactory = new DefaultHttpDataSourceFactory("exoplayer_video");
                ExtractorsFactory extractorsFactory = new DefaultExtractorsFactory();
                MediaSource mediaSource = new ExtractorMediaSource(UriSrc, dataSourceFactory,
                        extractorsFactory, null, null);
                exoPlayerView.setPlayer(exoPlayer);
                exoPlayer.prepare(mediaSource);
                exoPlayer.setPlayWhenReady(true);
                Toast.makeText(video_stream.this,
                        "Connect: " + src, Toast.LENGTH_LONG).show();
            } catch (Exception e){
                Log.e("video_stream", "exoplayer error: "+e.toString());
            } */

            /* emPlayer = (EMVideoView)findViewById(R.id.em_view);
            emPlayer.setOnPreparedListener(this);
            emPlayer.setVideoURI(Uri.parse(src)); */
        }
    }

    /*@Override
    public void onBackPressed() {
        if(webView.canGoBack()) {
            webView.goBack(); //if thereis a webpage to go back to, go back to it
        } else {
            super.onBackPressed(); //else go back in app
        }
    } */

    /*@Override
    protected  void onDestroy() {
        super.onDestroy();
        streamView.stopPlayback();
    } */

    /* @Override
    public void onPrepared() {
        emPlayer.start();
        Log.v("TAG", "vid is playing");
    } */
}
