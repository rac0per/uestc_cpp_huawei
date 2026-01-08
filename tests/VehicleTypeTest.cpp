#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
// ==================== Sport Car Tests ====================
TEST(SportCarTest, sport_car_move_forward_2_steps)
{
    // Given: Sport car facing East at origin
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Sport));

    // When: Execute M command
    executor->Execute("M");

    // Then: Should move 2 steps forward
    const Pose target({2, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(SportCarTest, sport_car_move_backward_2_steps)
{
    // Given: Sport car facing East with reverse enabled
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Sport));

    // When: Execute B (reverse) then M
    executor->Execute("BM");

    // Then: Should move 2 steps backward
    const Pose target({-2, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(SportCarTest, sport_car_move_fast_forward_4_steps)
{
    // Given: Sport car facing North with fast mode
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, VehicleType::Sport));

    // When: Execute F (fast) then M
    executor->Execute("FM");

    // Then: Should move 4 steps forward
    const Pose target({0, 4, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(SportCarTest, sport_car_turn_left_and_move)
{
    // Given: Sport car facing East
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Sport));

    // When: Execute L (left turn 90, move 1 step)
    executor->Execute("L");

    // Then: Should turn left (to N) and move 1 step forward
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(SportCarTest, sport_car_fast_turn_left)
{
    // Given: Sport car facing East with fast mode
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Sport));

    // When: Execute F (fast) then L
    // Fast L: 前进 1 格，再左转 90°，而后再前进 1 格
    executor->Execute("FL");

    // Then: Should move 1 forward (x=1), turn left (facing N), move 1 forward (y=1)
    const Pose target({1, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}

// ==================== Bus Tests ====================
TEST(BusTest, bus_move_forward_1_step)
{
    // Given: Bus car facing East at origin
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));

    // When: Execute M command
    executor->Execute("M");

    // Then: Should move 1 step forward
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, bus_move_backward_1_step)
{
    // Given: Bus car facing East with reverse enabled
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));

    // When: Execute B (reverse) then M
    executor->Execute("BM");

    // Then: Should move 1 step backward
    const Pose target({-1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, bus_fast_move_2_steps)
{
    // Given: Bus car facing North with fast mode
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, VehicleType::Bus));

    // When: Execute F (fast) then M
    executor->Execute("FM");

    // Then: Should move 2 steps forward (1+1)
    const Pose target({0, 2, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, bus_turn_left_and_move)
{
    // Given: Bus car facing East
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));

    // When: Execute L (move 1 step, then turn left 90)
    executor->Execute("L");

    // Then: Should move 1 step forward first, then turn left (to N)
    const Pose target({1, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, bus_fast_turn_left_move_twice_then_turn)
{
    // Given: Bus car facing East with fast mode
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));

    // When: Execute F (fast) then L
    executor->Execute("FL");

    // Then: Should move 2 steps forward, then turn left
    const Pose target({2, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, bus_complex_command)
{
    // Given: Bus car facing North
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, VehicleType::Bus));

    // When: Execute M (move 1) L (move 1, turn left) M (move 1)
    executor->Execute("MLM");

    // Then:
    // M: move 1 forward facing N → (0, 1) facing N
    // L: move 1 forward → (0, 2) facing N, turn left → (0, 2) facing W
    // M: move 1 forward facing W → (-1, 2) facing W
    const Pose target({-1, 2, 'W'});
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas
