#import firebase_admin
#from firebase_admin import auth

#default_app = firebase_admin.initialize_app(cred)
#print(default_app.name)


import firebase_admin
from firebase_admin import credentials
from firebase_admin import messaging
#import firebase_messaging

if not firebase_admin._apps:
    cred = credentials.Certificate("<insert path to json file>")
    firebase_admin.initialize_app(cred)

#default_app = firebase_admin.initialize_app()

# This registration token comes from the client FCM SDKs.
registration_token = '<token for device>'

# See documentation on defining a message payload.
message = messaging.Message(
    notification=messaging.Notification(
        title='hello there',
        body='general kenobi! you are a bold one!'
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

