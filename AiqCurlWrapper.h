//
// Created by Christopher Jaramillo on 2019-04-14.
//

#ifndef ATTACKIQ_AIQCURLWRAPPER_H
#define ATTACKIQ_AIQCURLWRAPPER_H

#include <string>
#include <curl/curl.h>

namespace AIQ {
    class AiqCurlWrapper
    {
    public:
        static const AiqCurlWrapper& instance();
        void init()const;
        CURLcode post(const std::string&, const std::string&, std::string&)const;

        virtual ~AiqCurlWrapper();

    private:
        AiqCurlWrapper();
    };
}


#endif //ATTACKIQ_AIQCURLWRAPPER_H
