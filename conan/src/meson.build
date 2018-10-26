
project('hello',
        'cpp',
        version : '0.1.0',
        default_options : ['cpp_std=c++17']
        )

boost_dep = dependency('boost', modules : ['thread', 'system', 'chrono'])

lib = library('hello',
        ['hello.cpp'],
        dependencies: [dependency('zlib'), boost_dep]
        )

exe = executable('hello', 'hello.cpp', dependencies : boost_dep)

