
project('task_system', 'cpp', default_options : ['cpp_std=c++17'])
threads_dep = dependency('threads')
boost_dep = dependency('boost', modules : ['system'], default_options : ['library=static'])
benchmark_dep = dependency('google-benchmark', method : 'pkg-config')

executable('fibonacci', 'main.cpp', dependencies : [boost_dep, threads_dep])

bench_exe = executable('bench', 'bench.cpp', dependencies : [boost_dep, benchmark_dep, threads_dep])

benchmark('bench', bench_exe )
