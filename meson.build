project('cjson', 'c')

src = fileglob('src/*.c')

# Debug build options
debug_options = ['-I./src/include', '-O0', '-g', '-D_DEBUG']
debug_build = configuration_data()

debug_build.set('buildtype', 'debug')
debug_build.set('c_args', debug_options)

# Release build options
release_options = ['-I./src/include', '-O2', '-Wall', '-Wpedantic', '-Wextra']
release_build = configuration_data()

release_build.set('buildtype', 'release')
release_build.set('c_args', release_options)

shared_library('cjson', 
  sources : src,
  configuration : [debug_build, release_build])
