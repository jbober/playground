project('tutorial', 'cpp')
##executable('demo', 'main.cpp')
idlc = find_program('tao_idl')

gen = generator(idlc,
                output  : ['@BASENAME@C.h', '@BASENAME@C.cpp'],
                arguments : ['@INPUT@', '-o', '@BUILD_DIR@'])

gen_src = gen.process('time.idl', 'hello_world.idl')

thread_dep = dependency('threads')
cc = meson.get_compiler('cpp')
ace = cc.find_library('ACE', required : true)
tao = cc.find_library('TAO', required : true)
portable_server = cc.find_library('TAO_PortableServer', required : true)
tao_any = cc.find_library('TAO_AnyTypeCode', required : true)
e2 = executable('program', 'main.cpp', gen_src, dependencies : [thread_dep, ace, tao, portable_server,tao_any])


