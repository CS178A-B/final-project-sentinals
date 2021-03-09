#import firebase_admin
#from firebase_admin import auth

#default_app = firebase_admin.initialize_app(cred)
#print(default_app.name)

#To find the token to your device, upon installating the companion_app to your device,
#check the debug console on android studio and look for "D/TAG: the token refreshed: ...". 
#The following string is your device token, take that and assign it to this file's registration_token variable.
import firebase_admin
from firebase_admin import credentials
from firebase_admin import messaging
#import firebase_messaging

if not firebase_admin._apps:
    cred = credentials.Certificate("E:\Luccas\Documents\docs_2\UCR Docs\Fall_2020\cs178a\cs178b-notification-firebase-adminsdk-4vs8i-c3e54116ce.json")
    firebase_admin.initialize_app(cred)

#default_app = firebase_admin.initialize_app()

# This registration token comes from the client FCM SDKs.
registration_token = 'cHxxQeyDRFCkB5HrLzs8yx:APA91bGHRtn-eDOZfO4dKp7fHEL_uNIydJmi7-KJN5ScpfKKaAsdwhvznqDShgeAOcBVSIPBjbnwFv2tk_w-bqq49IW9Lx_rjtKewRtN2-HjK-zk5UQd2S5bx8H_63Kp134uyk1B_b2O'

# See documentation on defining a message payload.
message = messaging.Message(
    notification=messaging.Notification(
        title='ALERT FROM NERF SENTRY',
        body='Your Nerf Sentry detected a possible intruder and was signaled to fire.'
    ),
    #data={
    #    'score': '850',
    #    'time': '2:45',
    #},
    token=registration_token,
)

# Send a message to the device corresponding to the provided
# registration token.
response = messaging.send(message)
# Response is a message ID string.
print('Successfully sent message:', response)

