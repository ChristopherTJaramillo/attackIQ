# AttackIQ
Repository to hold code specific to AttackIQ code sample

## What is it?
I've put together a server using grpc/protobuf that accepts a 
string of english as a request and translates that request to spanish.  
client <--> attackIQ <--> google translate REST API  
The request is packed into a Translatable message defined in the 
aiq_server.proto, transmitted to the running server. The server receives the message,
extracts the string to translate, sends the message to google translate via HTTP Rest 
(https://translation.googleapis.com/language/translate/v2?target=es&key={an api key}&q={some text}). 
The response body is written into a buffer, populated in a Translate message and returned 
to the client. 

## Dependencies
cmake  
curl  
grpc

## How to build
`$ mkdir build`  
`$ cd build`    
`$ cmake ..`    
`$ cmake --build .` 

## How to modify the API
In order to modify the API, adding messages, modifying fields in existing messages, etc. 
one would first modify the aiq_server.proto file found in the schema/protos directory under 
the base project directory.  
`$ vi schema/protos/aiq_server.proto`    
When the changes are completed, one would then re-generate the grpc code:  
`$ $GRPC_HOME/bins/opt/protobuf/protoc -I schema/protos --grpc_out=generated --plugin=protoc-gen-grpc=$GRPC_HOME/bins/opt/grpc_cpp_plugin aiq_server.proto`  
`$ $GRPC_HOME/bins/opt/protobuf/protoc --proto_path=schema/protos --cpp_out=generated schema/protos/aiq_server.proto`
