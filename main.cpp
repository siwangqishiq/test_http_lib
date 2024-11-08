

#include <iostream>
#include <string>


#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"


void test(std::string &url){
    httplib::Client client(url);

    std::cout << "start to request " << url << "..." << std::endl;
    auto res = client.Get(url);

    std::cout << "status: " << res.error() << std::endl;
    auto data = res.value();
    std::cout << "body:" << data.body << std::endl;
}

/**
 * @brief 
 * 
 * windows compile :
 *  
 *  g++ main.cpp -lwsock32 -lWs2_32 -lssl -lcrypto -lcrypt32 -o test
 * 
 * @return int 
 */
int main(int argc , char *argv[]){
    std::string url = argv[1];
    test(url);
    return 0;
}
