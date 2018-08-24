project('boost_asio_socket', 'cpp')

boost_dep = dependency('boost', modules : ['system', 'fusion'])
thread_dep = dependency('threads')

executable('server', 'server.cpp', dependencies : boost_dep)
executable('client', 'client.cpp', dependencies : [boost_dep, thread_dep])

