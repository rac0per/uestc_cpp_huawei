#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
// 倒车状态 - M命令测试（不同朝向）
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_minus_1_given_status_is_back_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{1, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_back_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{0, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - L命令测试（右转，位置不变）
TEST(ExecutorReverseTest, should_return_S_and_no_move_given_status_is_back_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_E_and_no_move_given_status_is_back_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - R命令测试（左转，位置不变）
TEST(ExecutorReverseTest, should_return_N_and_no_move_given_status_is_back_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_W_and_no_move_given_status_is_back_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 快速+倒车叠加状态 - M命令测试（后退2格）
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_fast_and_back_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FBM");
    // then
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_minus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BFM");
    // then
    const Pose target{0, -2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 快速+倒车叠加状态 - L命令测试（先后退1格，然后右转）
TEST(ExecutorReverseTest, should_return_S_and_x_minus_1_given_status_is_fast_and_back_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FBL");
    // then
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_E_and_y_minus_1_given_status_is_back_and_fast_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BFL");
    // then
    const Pose target{0, -1, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 快速+倒车叠加状态 - R命令测试（先后退1格，然后左转）
TEST(ExecutorReverseTest, should_return_N_and_x_minus_1_given_status_is_fast_and_back_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FBR");
    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_W_and_y_minus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{0, -1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 取消倒车状态测试（两次B）
TEST(ExecutorReverseTest, should_return_x_plus_1_given_command_is_BBM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BBM");
    // then
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 组合测试：连续倒车
TEST(ExecutorReverseTest, should_return_x_minus_3_given_command_is_BMMM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BMMM");
    // then
    const Pose target{-3, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 组合测试：倒车+转向
TEST(ExecutorReverseTest, should_return_correct_pose_given_command_is_BMRL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BMRL");
    // then
    // BM: 后退到(-1,0,E), BR: 左转到(-1,0,N), BL: 右转到(-1,0,E)
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

}