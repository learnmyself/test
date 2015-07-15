#include<ctime>
#include<iostream>
#include<string>
#include<boost/asio.hpp>

using namespace boost;
using boost::asio::ip::tcp;

int main()
{	
	try
	{
		asio::io_service io_service;
		tcp::acceptor acceptor(io_service,tcp::endpoint(tcp::v4(), 3200));
		for(;;)
		{
			tcp::socket socket(io_service);
			acceptor.accept(socket);
			printf("sockfd: %d, ip :%s, port: %d\n", &socket, socket.remote_endpoint().address().to_string().c_str(), socket.remote_endpoint().port());
			time_t now = time(0);
			std::string message = ctime(&now);
			system::error_code ignored_error;
			socket.write_some(asio::buffer(message), ignored_error);

		}
	}
	catch(std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	
	return 0;
}
