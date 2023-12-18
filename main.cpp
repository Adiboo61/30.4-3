#include <iostream>
#include <cpr/cpr.h>
#include <map>
#include <vector>

int main() {
    std::string arg = "1";
    std::string meaning = "q";
    std::string text;
    cpr::Response r;
    std::map<std::string, std::string> m;
    std::vector<cpr::Pair> vecpair;
    while(arg != "post" && arg!="get"){
        std::cout << "Enter argument: " <<std::endl;
        std::cin >> arg;
        std::cout << "Enter meaning: " <<std::endl;
        std::cin >> meaning;
        if(arg == "post"){
            r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                          cpr::Payload(vecpair.begin(), vecpair.end()));
        }
        if (arg == "get"){

            for ( std::map<std::string, std::string>::iterator it = m.begin();
            it != m.end() ; ++it) {
               text += it->first + "=" + it->second + "&";
            }
            r = cpr::Get(cpr::Url("http://httpbin.org/get?" + text));
        }
        else {
            vecpair.push_back(cpr::Pair((std::string) arg, (std::string) meaning));
            m.insert(std::pair<std::string, std::string>(arg, meaning));
        }
    }
    std::cout << r.text;

	return 0;
}