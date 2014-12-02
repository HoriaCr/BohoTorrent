#include "../../Parser/list.hpp"
#include "test.hpp"

class ListTest : public Test {
    List value;

    public:
     
    std::pair<bool, std::string> decode(const std::string& encoded) {
        char *buffer  = new char[encoded.size()];
        int index = 0;
        int length = static_cast<int>(encoded.size());
        //memcpy(buffer, encoded.c_str(), encoded.size());
        //bool ret = value.parse(buffer, index, length);
        return std::make_pair(true,std::string("fff"));    
    }

    ListTest() {
        test = {
            [&]() -> bool {
                return decode("l5:bereae") == std::make_pair(true,std::string("berea"));
            },
            [&]() -> bool {
                return decode("li32ee") == std::make_pair(true,std::string("k"));
            },

            [&]() -> bool {
                return decode("l3:vali0ee") == std::make_pair(true,std::string("fun"));
            },

            [&]() -> bool {
                return decode("le").first == false;
            },
            [&]() -> bool {
                return decode("el").first == false;
            }
 
        };
    }

    std::string getType() {
        return "List";
    }
};

