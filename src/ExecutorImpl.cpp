#include "ExecutorImpl.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Command.hpp"
#include "Singleton.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, VehicleType type) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, type);
}
ExecutorImpl::ExecutorImpl(const Pose& pose, VehicleType type) noexcept : vehicleType(type), poseHandler(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands, vehicleType);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const std::function<void(PoseHandler & poseHandler)>& cmder) noexcept { cmder(poseHandler); });
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
