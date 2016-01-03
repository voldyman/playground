#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/URI.h"

#include "Poco/JSON/Parser.h"

#include <iostream>
#include <iterator>
#include <algorithm> //for copy
#include <sstream>

std::string
parse_json(std::string str) {
    Poco::JSON::Parser parser;
    auto result= parser.parse(str);
    auto obj = result.extract<Poco::JSON::Object::Ptr>();
    auto ipprop = obj->get("ip_addr");

    return ipprop.convert<std::string>();
}

int main() {
    try {
        Poco::URI uri("http://ifconfig.me/all.json"); // same as http://ifconfig.me/all.json
        std::string path(uri.getPathAndQuery());

        Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET,
                                       path,
                                       Poco::Net::HTTPMessage::HTTP_1_1);
        request.set("Connection", "close");
        request.set("User-agent", "ninja");
        Poco::Net::HTTPResponse res;

        session.sendRequest(request);

        std::istream& is = session.receiveResponse(res);

        std::stringstream ss;
        std::copy(std::istream_iterator<char>(is),
                  std::istream_iterator<char>(),
                  std::ostream_iterator<char>(ss));

        std::cout << "ip: " << parse_json(ss.str()) << std::endl;

    } catch (Poco::Exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
