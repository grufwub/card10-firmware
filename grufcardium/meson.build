name = 'grufcardium'

src = files(
  'test.c'
)

elf = executable(
  name + '.elf',
  'main.c',
  src,
  dependencies: [max32665_startup_core1, periphdriver, api_caller],
  link_whole: [max32665_startup_core1_lib, api_caller_lib],
  link_args: [
    '-Wl,-Map=' + meson.current_build_dir() + '/' + name + '.map',
  ],
)

bin = custom_target(
  name + '.bin',
  build_by_default: true,
  output: name + '.bin',
  input: elf,
  command: [build_image, '@INPUT@', '@OUTPUT0@'],
)

custom_target(
  name + '_epicardium.bin',
  build_by_default: true,
  output: name + '_epicardium.bin',
  input: [epicardium_bin, bin],
  command: [build_multi_image, '@INPUT@', '@OUTPUT0@'],
)
