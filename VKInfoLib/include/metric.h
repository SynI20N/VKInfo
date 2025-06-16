#ifndef METRIC_H_
#define METRIC_H_

#include <string>

#include "export.h"

namespace VkInfo {

class VKINFO_API IMetric {
public:
    virtual ~IMetric() = default;
    virtual std::string get_name() const = 0;
    virtual std::string get_value_and_reset() = 0;
    virtual void set_random_value() = 0;
};

} // namespace VkInfo

#endif // METRIC_H_