#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])	//������ �ּҸ� �Է�
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13)));	//port number 13, argv[1] �� ���� 127.0.0.1 �� �־ �۵���
		if (!stream)
		{
			std::cout << "Unable to connect: " << stream.error().message() << std::endl;
			return 1;
		}

		//send message to server
		stream << "Hello from client";
		stream << std::endl;	//send new-line to end receiver's stream getline

		//receive message from server
		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	 

	return 0;
}



