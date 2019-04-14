//
// Created by Christopher Jaramillo on 2019-04-14.
//

#include "AiqCurlWrapper.h"

#include <iostream>

AIQ::AiqCurlWrapper::AiqCurlWrapper()
{

}

AIQ::AiqCurlWrapper::~AiqCurlWrapper()
{
    curl_global_cleanup();
}

const AIQ::AiqCurlWrapper& AIQ::AiqCurlWrapper::instance()
{
    static AiqCurlWrapper wrapperInstance;
    return wrapperInstance;
}

void AIQ::AiqCurlWrapper::init()const
{
    curl_global_init(CURL_GLOBAL_ALL);
}

size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

CURLcode
AIQ::AiqCurlWrapper::post(const std::string &url, const std::string &content, std::string& readBuffer) const
{
    CURL *curl = curl_easy_init();
    CURLcode res(CURLE_RECV_ERROR);

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, content.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        std::cout << readBuffer << std::endl;
    }
    return res;
}