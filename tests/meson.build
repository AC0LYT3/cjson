
macrosrc = ['macro/macro-test.c']
initsrc = ['cjson-init.c']

local_include = include_directories('../src/include')
cjson_dep = declare_dependency(link_with : cjson_static)

executable('macro-test',
  sources : macrosrc,
  include_directories : local_include)

executable('cjson-init-test',
  sources : initsrc,
  include_directories : local_include,
  dependencies : [cjson_dep])
