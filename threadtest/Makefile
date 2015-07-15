all:test client server async_server
test:test.o
	g++ -o test test.o -lpthread

client:client.o
	g++ -o client client.o -lboost_system

server:server.o
	g++ -o server server.o -lboost_system

async_server: async_server.o
	g++ -std=c++11 -o async_server async_server.o -lboost_system 
