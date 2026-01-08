#include "CmderFactory.hpp"
namespace adas
{
std::list<std::function<void(PoseHandler& poseHandler)>> CmderFactory::GetCmders(const std::string& commands,
                                                                                 VehicleType type) const noexcept
{
    std::list<std::function<void(PoseHandler & poseHandler)>> cmders;

    // Select the appropriate command map based on vehicle type
    const auto* cmderMapPtr = &normalCmderMap;
    if (type == VehicleType::Sport) {
        cmderMapPtr = &sportCmderMap;
    } else if (type == VehicleType::Bus) {
        cmderMapPtr = &busCmderMap;
    }

    for (const auto cmd : commands) {
        const auto it = cmderMapPtr->find(cmd);
        if (it != cmderMapPtr->end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}
}  // namespace adas
