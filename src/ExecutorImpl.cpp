#include "ExecutorImpl.hpp"
#include <unordered_map>
#include <memory>

#include "Command.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    // std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap;
    // cmderMap.emplace('M', MoveCommand());
    // cmderMap.emplace('L', TurnLeftCommand());
    // cmderMap.emplace('R', TurnRightCommand());
    // cmderMap.emplace(‘F’, FastCommand());
    const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap{
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()}
    };
    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            it->second(poseHandler);
        }
    }
}

void ExecutorImpl::Forward(void) noexcept
{
    poseHandler.Forward();
}
void ExecutorImpl::Backward(void) noexcept
{
    poseHandler.Backward();
}
void ExecutorImpl::TurnLeft(void) noexcept
{
    poseHandler.TurnLeft();
}

void ExecutorImpl::TurnRight(void) noexcept
{
    poseHandler.TurnRight();
}

void ExecutorImpl::Fast(void) noexcept
{
    poseHandler.Fast();
}

bool ExecutorImpl::IsFast(void) const noexcept
{
    return poseHandler.IsFast();
}
void ExecutorImpl::Reverse(void) noexcept
{
    poseHandler.Reverse();
}

bool ExecutorImpl::IsReverse(void) const noexcept
{
    return poseHandler.IsReverse();
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas