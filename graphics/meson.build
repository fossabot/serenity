inc = include_directories('include')
serenity_graphics = library('serenity-graphics', [
	'renderer.cpp',
], include_directories: inc, dependencies: [dependency('sup'), dependency('sdl3'), dependency('gtk4'), serenity_dep], install: true)
serenity_graphics_dep = declare_dependency(link_with: serenity_graphics, dependencies: [dependency('sup'), dependency('sdl3'), serenity_dep], include_directories: inc)

pkg = import('pkgconfig')
pkg.generate(libraries : [serenity_graphics],
             subdirs : ['include'],
             version : '1.0',
             name : 'libserenity_graphics',
             filebase : 'serenity_graphics',
             description : 'Graphics for a game engine for C++ and SDL3')
