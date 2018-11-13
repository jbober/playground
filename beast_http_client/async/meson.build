project('beast_http_client', 'cpp', default_options : ['cpp_std=c++17'])
boost_dep = dependency('boost', modules : ['thread', 'system'], default_options : ['library=static'])

executable('myexe', 'http_client_async.cpp', dependencies : boost_dep)
