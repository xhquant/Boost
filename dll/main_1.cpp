#include <iostream>

#include "boost/dll/import.hpp"

#include "plugin_api.hpp"

namespace dll = boost::dll;

int main(int argc, char *argv[])
{
    boost::shared_ptr<plugin_api> plugin = dll::import<plugin_api>("../lib/plugin_sum", "plugin", dll::load_mode::append_decorations);

    std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugin->calculate(1.5, 1.5) << std::endl;
}