#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"
#include "Executor.hpp"
namespace adas
{
class CmderFactory final
{
public:
    CmderFactory(void) = default;
    ~CmderFactory(void) = default;
    CmderFactory(const CmderFactory&) = delete;
    CmderFactory& operator=(const CmderFactory&) = delete;

public:
    std::list<std::function<void(PoseHandler& poseHandler)>> GetCmders(
        const std::string& commands, VehicleType type = VehicleType::Normal) const noexcept;

private:
    // Normal car commands
    const std::unordered_map<char, std::function<void(PoseHandler& poseHandler)>> normalCmderMap{
        {'M', NormalMoveCommand()}, {'L', NormalTurnLeftCommand()}, {'R', NormalTurnRightCommand()},
        {'F', FastCommand()},       {'B', ReverseCommand()},
    };

    // Sport car commands
    const std::unordered_map<char, std::function<void(PoseHandler& poseHandler)>> sportCmderMap{
        {'M', SportMoveCommand()}, {'L', SportTurnLeftCommand()}, {'R', SportTurnRightCommand()},
        {'F', FastCommand()},      {'B', ReverseCommand()},
    };

    // Bus commands
    const std::unordered_map<char, std::function<void(PoseHandler& poseHandler)>> busCmderMap{
        {'M', BusMoveCommand()}, {'L', BusTurnLeftCommand()}, {'R', BusTurnRightCommand()},
        {'F', FastCommand()},    {'B', ReverseCommand()},
    };
};
}  // namespace adas
