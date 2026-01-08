#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose, VehicleType type = VehicleType::Normal) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    bool IsReverse(void) const noexcept;
    void Reverse(void) noexcept;

private:
    VehicleType vehicleType;
    Pose pose;
    bool fast{false};
    bool reverse{false};
    PoseHandler poseHandler;
};
}  // namespace adas