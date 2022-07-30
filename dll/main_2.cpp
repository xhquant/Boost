#include <boost/dll/import.hpp>
#include <boost/function.hpp>
#include <iostream>
#include "plugin_api.hpp"

namespace dll = boost::dll;

int main(int argc, char **argv)
{
    boost::function<boost::shared_ptr<plugin_api>()> creator = boost::dll::import_alias<boost::shared_ptr<plugin_api>()>("../lib/plugin_aggregator", "create", dll::load_mode::append_decorations);

    boost::shared_ptr<plugin_api> plugin = creator();
    std::cout << "plugin->on_ticks()->calculate(1., 1.) call:  " << plugin->on_ticks()->calculate(1., 1.) << std::endl;
    std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugin->calculate(1.5, 1.5) << std::endl;
    std::cout << "plugin->calculate(1.5, 1.5) second call:  " << plugin->calculate(1.5, 1.5) << std::endl;
    std::cout << "Plugin Name:  " << plugin->name() << std::endl;
}