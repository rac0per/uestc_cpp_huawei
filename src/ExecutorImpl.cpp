#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>
#include <algorithm>
#include "CmderFactory.hpp"
#include "Singleton.hpp"
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
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
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