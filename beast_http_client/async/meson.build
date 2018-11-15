project('beast_http_client', 'cpp', default_options : ['cpp_std=c++17'])
boost_dep = dependency('boost', modules : ['thread', 'system', 'program_options', 'regex'], default_options : ['library=static'])
openssl = dependency('openssl')
benchmark = dependency('google-benchmark')

executable('async', 'http_client_async.cpp', dependencies : boost_dep)
executable('sync', 'http_client_sync.cpp', dependencies : boost_dep)
executable('sync_ssl', 'http_client_sync_ssl.cpp', dependencies : [boost_dep, openssl, benchmark])
