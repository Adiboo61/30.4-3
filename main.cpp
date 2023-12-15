#include <iostream>
#include <cpr/cpr.h>
#include <map>


int main() {
    std::string arg = "";
    std::string meaning = "";
    cpr::Response r;
    std::map<std::string, std::string> m;
    do {
        std::cout << "Enter argument: " <<std::endl;
        std::cin >> arg;
        if (arg != "post"){
            std::cout << "Enter meaning: " <<std::endl;
            std::cin >> meaning;
            //m.insert(std::pair<std::string,std::string>(arg,meaning));
            r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                          cpr::Payload({{cpr::Pair((std::string)arg,(std::string) meaning)}}));
        }
        if (arg == "get"){
            for (std::map<std::string, std::string>::iterator it = m.begin();
                 it != m.end(); it++) {

                r = cpr::Get(cpr::Url("http://httpbin.org/get"),
                             cpr::Header {{it->first, it->second}});
            }
        }



    }while (arg != "get" && arg !="post");

    std::cout << r.text;

	return 0;
}