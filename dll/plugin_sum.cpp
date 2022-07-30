#include <iostream>

#include <boost/config.hpp>
#include <boost/dll/alias.hpp>

#include "plugin_api.hpp"

namespace my_namespace
{
    class plugin_sum : public plugin_api
    {
    public:
        plugin_sum()
        {
            std::cout << "Constructing my_plugin_sum" << std::endl;
        }

        ~plugin_sum() override
        {
            std::cout << "Destructing my_plugin_sum" << std::endl;
        }

    public:
        std::string name() const override
        {
            return "sum";
        }

        float calculate(float x, float y) override
        {
            return x + y;
        }

        boost::shared_ptr<plugin_api> on_ticks() override
        {
            return shared_from_this();
        }
    };

    extern "C" BOOST_SYMBOL_EXPORT plugin_sum plugin;
    plugin_sum plugin;
}
