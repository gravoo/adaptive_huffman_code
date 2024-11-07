add_executable(Tests BasicTest.cpp)
catch_discover_tests(Tests)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

add_executable(NodeTests NodeTests.cpp ${CMAKE_SOURCE_DIR}/src/Node.cpp)
target_link_libraries(NodeTests PRIVATE Catch2::Catch2WithMain)
target_include_directories(NodeTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
catch_discover_tests(NodeTests)

add_executable(TreeTests TreeTests.cpp ${CMAKE_SOURCE_DIR}/src/Tree.cpp ${CMAKE_SOURCE_DIR}/src/Node.cpp)
target_link_libraries(TreeTests PRIVATE Catch2::Catch2WithMain)
target_include_directories(TreeTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
catch_discover_tests(TreeTests)

add_executable(TransmiterTests TransmiterTests.cpp ${CMAKE_SOURCE_DIR}/src/Transmiter.cpp ${CMAKE_SOURCE_DIR}/src/Tree.cpp ${CMAKE_SOURCE_DIR}/src/Node.cpp)
target_link_libraries(TransmiterTests PRIVATE Catch2::Catch2WithMain)
target_include_directories(TransmiterTests PRIVATE ${CMAKE_SOURCE_DIR}/include)
catch_discover_tests(TransmiterTests)