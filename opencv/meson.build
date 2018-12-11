
project('opencv_hello_world', 'cpp', default_options : ['cpp_std=c++17'])
threads_dep = dependency('threads')
boost_dep = dependency('boost', modules : ['system'], default_options : ['library=static'])

executable('opencv_hello_world', 'main.cpp', dependencies : [boost_dep, threads_dep])

