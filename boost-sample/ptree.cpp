#include <iostream>
#include <string>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

using namespace boost::property_tree;

#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;

const auto json_data = R"({
    "Data": 
    {
        "value": 3,
        "str": "Hello",
        "info": 
        [
            {"id": 1, "name": "Alice"},
            {"id": 2, "name": "Millia"}
        ]
    }
})";

int main()
{
    ptree pt;
    std::stringstream sstream(json_data);

    read_json(sstream, pt);

    // Data.value
    if (boost::optional<int> value = pt.get_optional<int>("Data.value")) {
        std::cout << "value : " << value.get() << std::endl;
    }
    else {
        std::cout << "value is nothing" << std::endl;
    }

    // Data.str
    if (boost::optional<std::string> str = pt.get_optional<std::string>("Data.str")) {
        std::cout << "str : " << str.get() << std::endl;
    }
    else {
        std::cout << "str is nothing" << std::endl;
    }

    // Data.info
    BOOST_FOREACH (const ptree::value_type& child, pt.get_child("Data.info")) {
        const ptree& info = child.second;

        // Data.info.id
        if (boost::optional<int> id = info.get_optional<int>("id")) {
            std::cout << "id : " << id.get() << std::endl;
        }
        else {
            std::cout << "id is nothing" << std::endl;
        }

        // Data.info.name
        if (boost::optional<std::string> name = info.get_optional<std::string>("name")) {
            std::cout << "name : " << name.get() << std::endl;
        }
        else {
            std::cout << "name is nothing" << std::endl;
        }
    }

}
