#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

int main() {
    std::ifstream file;
    
    std::string line;
    std::string quote;
    std::map<std::string,std::string> values;
    bool on_quote = false;

    file.open("text.txt");
    while(std::getline(file,line)) {
        size_t start = 0;

        if(line.find('[') < line.find('\"')) {
            start = line.find('[');
            size_t end = line.find(']');
            std::string var = line.substr(start+1,end-start-1);
            std::cin >> values[var];
        }

        for(size_t pos=line.find('\"');
          pos!=std::string::npos;
          pos=line.find('\"',pos+1)) {
            on_quote = !on_quote;

            if(on_quote)
                start = pos;
            else {
                if(quote.empty())
                    quote = line.substr(start,pos-start+1);
                else {
                    quote += line.substr(0,pos+1);
                }

                for(size_t pos2=quote.find('[');
                  pos2!=std::string::npos;
                  pos2=quote.find('[',pos2+1)) {
                    size_t end = line.find(']');
                    std::string get = quote.substr(pos2+1,end-pos2-1);
                    quote.replace(pos2,end-pos2+1,values[get]);
                }
                std::cout << quote << std::endl;
                quote.clear();
            }
        }
        if(on_quote) {
            quote += line.substr(start,std::string::npos) + ' ';
        }
    }

    std::cout << "Vars:\n";
    for(auto var: values) {
        std::cout << var.first << ":" << var.second << "\n";
    }
    return 0;
}