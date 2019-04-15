import grpc
import aiq_server_pb2
import aiq_server_pb2_grpc
import uuid
import socket
import json

def run():
    with grpc.insecure_channel('35.231.16.132:12345') as channel:
        stub = aiq_server_pb2_grpc.AiqTranslationServerStub(channel)
        msgUuid = str(uuid.uuid1())
        senderId = socket.gethostbyname(socket.gethostname())
        anApiKey = raw_input("What is your API key: ")
        aMessage = raw_input("What would you like to translate? ")
        aMessage = aMessage.replace(" ","%20")
        response = stub.Translate(aiq_server_pb2.Translatable(messageId=msgUuid, sender=senderId, fromLanguage='en', toLanguage='es', message=aMessage, apiKey=anApiKey))
        aTranslation = json.loads(response.translatedMessage)
        print(aTranslation['data']['translations'][0]['translatedText'])

if __name__ == '__main__':
    run()
