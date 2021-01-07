cmake_minimum_required(VERSION 3.17)
project(GitCode)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

#add_executable(t4 selfTests/t4.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp selfTests/t4.cpp)
#add_executable(check_option1 selfTests/check_option1.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp selfTests/t5.cpp selfTests/generateBoardFile.cpp)
#add_executable(testGame1 selfTests/testGame.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Game.cpp Code_Skeleton/utils.cpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp)
#add_executable(t5 selfTests/t5.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Game.cpp Code_Skeleton/utils.cpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp)
#add_executable(tester1 selfTests/tester1.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Game.cpp Code_Skeleton/utils.cpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp)
#add_executable(tester0 tester0/run_test0.cpp Code_Skeleton/Headers.hpp Code_Skeleton/Game.cpp Code_Skeleton/utils.cpp Code_Skeleton/Thread.hpp Code_Skeleton/ThreadP.cpp)
#add_executable(random_board selfTests/generateBoardFile.cpp)

#add_executable(ts1 selfTests/ts1.cpp Code_Skeleton/Part1/Headers.hpp Code_Skeleton/Part1/Semaphore.cpp)
#add_executable(ts2 selfTests/ts2.cpp Code_Skeleton/Part1/Headers.hpp Code_Skeleton/Part1/Semaphore.cpp Code_Skeleton/Part1/PCQueue.cpp)
#add_executable(ts3 selfTests/ts3.cpp Code_Skeleton/Part1/Headers.hpp Code_Skeleton/Part1/Semaphore.cpp Code_Skeleton/Part1/PCQueue.cpp)


add_executable(test_sem1 tests2/t1.cpp Code2/Headers.hpp Code2/Semaphore.cpp)
add_executable(test_PCQ1 tests2/t2.cpp Code2/Headers.hpp Code2/Semaphore.cpp Code2/PCQueue.hpp)
add_executable(test_Game1 tests2/testGame.cpp Code2/Thread.hpp Code2/ThreadP.cpp Code2/Headers.hpp Code2/Semaphore.cpp Code2/PCQueue.hpp Code2/Game.cpp Code2/Job.cpp Code2/utils.cpp)
add_executable(test_Game_but_not_ours tests2/testGame.cpp CodeT/Thread.hpp CodeT/ThreadP.cpp CodeT/Headers.hpp CodeT/Semaphore.cpp CodeT/PCQueue.hpp CodeT/Game.cpp CodeT/TileJob.h CodeT/utils.cpp)
