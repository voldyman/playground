#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/URI.h"

#include <iostream>
#include <iterator>
#include <algorithm> //for copy

int main() {
    try {
        Poco::URI uri("http://ifconfig.me/all");
        std::string path(uri.getPathAndQuery());

        Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET,
                                       path,
                                       Poco::Net::HTTPMessage::HTTP_1_1);
        Poco::Net::HTTPResponse res;

        session.sendRequest(request);

        std::istream& is = session.receiveResponse(res);

        std::copy(std::istream_iterator<char>(is),
                  std::istream_iterator<char>(),
                  std::ostream_iterator<char>(std::cout));

        std::cout << std::endl;

    } catch (Poco::Exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
