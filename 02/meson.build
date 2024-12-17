day_num = meson.current_source_dir().split('/')[-1]
input_file = meson.project_source_root() / 'myinputs' / ('day' + day_num + '.txt')

day = executable('day' + day_num, 'main.cpp')

run_target(
  'run' + day_num,
  command: [day, input_file]
)
