project('cjson', 'c',
  default_options: [
    'buildtype=release',
    'warning_level=3'])

cjson_src = ['src/cjson.c']

local_include = include_directories('./src/include')

if get_option('buildtype') == 'debug'
  add_project_arguments('-D_DEBUG', language : 'c')
endif

shared_library('cjson', 
  sources : cjson_src,
  include_directories : local_include)

subdir('tests')
