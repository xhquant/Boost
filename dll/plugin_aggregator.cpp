#include <iostream>
#include <boost/make_shared.hpp>

#include <boost/dll/alias.hpp>

#include "plugin_api.hpp"

namespace my_namespace
{
    class plugin_aggregator : public plugin_api
    {
    public:
        static boost::shared_ptr<plugin_aggregator> create()
        {
            return boost::shared_ptr<plugin_aggregator>(new plugin_aggregator());
        }

    public:
        std::string name() const override
        {
            return "aggregator";
        }

        float calculate(float x, float y) override
        {
            aggr_ += x + y;
            return aggr_;
        }

        boost::shared_ptr<plugin_api> on_ticks() override
        {
            return shared_from_this();
        }

    private:
        plugin_aggregator() = default;

        float aggr_ = 0;
    };
}

BOOST_DLL_ALIAS(my_namespace::plugin_aggregator::create, create)