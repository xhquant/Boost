#ifndef BOOST_PLUGIN_API_HPP
#define BOOST_PLUGIN_API_HPP

#include <string>

#include <boost/enable_shared_from_this.hpp>


class plugin_api: public boost::enable_shared_from_this<plugin_api>
{
public:
    virtual ~plugin_api() = default;

public:
    virtual std::string name() const = 0;

    virtual float calculate(float x, float y) = 0;

    virtual boost::shared_ptr<plugin_api> on_ticks() = 0;
};

#endif // BOOST_PLUGIN_API_HPP

