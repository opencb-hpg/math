Import('debug')

env = Environment(CFLAGS = '-std=c99 -D_XOPEN_SOURCE=600 -D_BSD_SOURCE ',
                  LIBS = ['gsl'], 
                  CPPPATH = [ '.', 'data' ])

env.Decider('MD5-timestamp')

if debug == 1:
    env['CFLAGS'] += ' -O0 -g'
else:
    env['CFLAGS'] += ' -O3'


# Targets
algebra_obj = env.Object(Glob('algebra/*.c'))
data_obj = env.Object(Glob('data/*.c'))
stats_obj = env.Object(Glob('stats/*.c'))
utils_obj = env.Object('math_utils.c')

env.Library('hpgmath', algebra_obj + data_obj + stats_obj + utils_obj)
