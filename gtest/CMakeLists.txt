cmake_minimum_required(VERSION 2.8.2)
#find_package(Boost)
find_package(Boost 1.55.0 COMPONENTS filesystem system)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
               googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)
# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include"
                      "${gmock_SOURCE_DIR}/include")
endif()

add_executable(example_test test.cpp)
target_link_libraries(example_test gtest gtest_main gmock gmock_main)
add_executable(boost_filesystem_test boost_filesystem.cpp)
#add_executable(boost_filesystem boost_filesystem.cpp)
  target_link_libraries(boost_filesystem_test gtest gtest_main gmock gmock_main ${Boost_LIBRARIES})
#target_link_libraries(boost_filesystem boost_filesystem_test gtest gtest_main gmock gmock_main)
# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
