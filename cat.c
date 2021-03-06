#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>


static int error(const char *args, ...)
{
    va_list ap;

    va_start(ap, args);

    if (args != 0)
    {
	fprintf(stderr, "%s", args);
	
	args = va_arg(ap, const char *);	
    }

    while (args != 0)
    {
	fprintf(stderr, ": %s", args);

	args = va_arg(ap, const char *);
    };

    va_end(ap);
    
    fprintf(stderr, "\n");

    return 1;
}

int main(int argc, char *argv[])
{
    const char *name = argv[0];

    int fd = STDIN_FILENO;

    if (argc > 1)
    {
	const char *path = argv[1];

	fd = open(path, O_RDONLY);

	if (fd == -1)
	    return error(name, path, strerror(errno), '\0');
    }

    char rbuf[4096];
    size_t rbuf_size = sizeof(rbuf);
    ssize_t nr;

    while ((nr = read(fd, rbuf, rbuf_size)) != 0)
    {
	if (nr == -1)
	    return error(name, strerror(errno), '\0');

	char *wbuf = rbuf;
	ssize_t nw;

	while (nr !=0 && (nw = write(STDOUT_FILENO, wbuf, nr)) != 0)
	{
	    if (nw == -1)
	    {
		if (errno == EINTR)
		    continue;

		return error(name, strerror(errno), '\0');
	    };

	    nr -= nw;
	    wbuf += nw;
	};
    };

    if (close(fd) == -1)
	return error(name, strerror(errno), '\0');

    return 0;
}
