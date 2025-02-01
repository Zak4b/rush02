#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#if BUFFER_SIZE > 20000
# undef BUFFER_SIZE
# define BUFFER_SIZE 20000
#endif

char	*get_next_line(int fd);