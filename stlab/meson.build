project('stlab_example', 'cpp')
thread_dep = dependency('threads')
stlab_incdir = include_directories('.')
executable('demo', 'main.cpp', 
include_directories : stlab_incdir,
dependencies : thread_dep)
subproject('gtest')
gtest_dep = dependency('gtest', fallback : ['gtest', 'gtest_dep'])
gmock_dep = dependency('gtest', fallback : ['gtest', 'gmock_dep'])

e = executable('testprog', ['test.cpp', 'test_main.cpp'], dependencies : gtest_dep)
test('gtest test', e)
