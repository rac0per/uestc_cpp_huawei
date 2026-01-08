#pragma once
#include <functional>

#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
namespace adas
{
// ==================== Normal Car Commands ====================
class NormalMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
        } else {
            poseHandler.Forward();
        }
    }
};
class NormalTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.TurnRight();
        } else {
            poseHandler.TurnLeft();
        }
    }
};
class NormalTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.TurnLeft();
        } else {
            poseHandler.TurnRight();
        }
    }
};

// ==================== Sport Car Commands ====================
class SportMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 4 格 / B&F: 后退 4 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.Forward();
            }
        } else {
            // Normal: 前进 2 格 / B: 后退 2 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
                poseHandler.Forward();
            }
        }
    }
};
class SportTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 1 格，再左转 90°，而后再前进 1 格
            // B&F: 后退 1 格，再右转 90°，而后再后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.TurnRight();
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
                poseHandler.TurnLeft();
                poseHandler.Forward();
            }
        } else {
            // Normal: 左转 90°，再前进 1 格
            // B: 右转 90°，再后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.TurnRight();
                poseHandler.Backward();
            } else {
                poseHandler.TurnLeft();
                poseHandler.Forward();
            }
        }
    }
};
class SportTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 1 格，再右转 90°，而后再前进 1 格
            // B&F: 后退 1 格，再左转 90°，而后再后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.TurnLeft();
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
                poseHandler.TurnRight();
                poseHandler.Forward();
            }
        } else {
            // Normal: 右转 90°，再前进 1 格
            // B: 左转 90°，再后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.TurnLeft();
                poseHandler.Backward();
            } else {
                poseHandler.TurnRight();
                poseHandler.Forward();
            }
        }
    }
};

// ==================== Bus Commands ====================
class BusMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 1 格，再前进 1 格
            // B&F: 后退 1 格，再后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
                poseHandler.Forward();
            }
        } else {
            // Normal: 前进 1 格 / B: 后退 1 格
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
    }
};
class BusTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 1 格，再前进 1 格，最后左转 90°
            // B&F: 后退 1 格，再后退 1 格，最后右转 90°
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.TurnRight();
            } else {
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.TurnLeft();
            }
        } else {
            // Normal: 前进 1 格，再左转 90°
            // B: 后退 1 格，再右转 90°
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.TurnRight();
            } else {
                poseHandler.Forward();
                poseHandler.TurnLeft();
            }
        }
    }
};
class BusTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            // F: 前进 1 格，再前进 1 格，最后右转 90°
            // B&F: 后退 1 格，再后退 1 格，最后左转 90°
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.TurnLeft();
            } else {
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.TurnRight();
            }
        } else {
            // Normal: 前进 1 格，再右转 90°
            // B: 后退 1 格，再左转 90°
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
                poseHandler.TurnLeft();
            } else {
                poseHandler.Forward();
                poseHandler.TurnRight();
            }
        }
    }
};

// ==================== Common Commands ====================
class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};

// Keep backward compatibility aliases
using MoveCommand = NormalMoveCommand;
using TurnLeftCommand = NormalTurnLeftCommand;
using TurnRightCommand = NormalTurnRightCommand;

}  // namespace adas
