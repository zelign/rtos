#include <FreeRTOS.h>
#include <stdlib.h>
#include <unistd.h>
#include "system.h"
#include <sys/stat.h>
#include "stdarg.h"

// void *__wrap_malloc(struct _reent *reent, size_t size)
// {
// 	return pvPortMalloc(size);
// }

// int __wrap_strlen(const char *s)
// {
// 	return strlen(s);
// }

// int __wrap_printf(const char *format, ...) {
//     va_list args;
//     va_start(args, format);
//     my_printf(format, args);
//     va_end(args);
//     return 0;
// }

void *__wrap__malloc_r(struct _reent *reent, size_t size)
{
	return pvPortMalloc(size);
}

void __wrap__free_r(struct _reent *reent, void *ptr)
{
	vPortFree(ptr);
}

int _close(int file)
{
	return -1;
}

int _fstat(int file, struct stat *st)
{
	return -1;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

int _read(int file, char *ptr, int len) {
    return 0;
}

void _exit(int status) {
    while (1) {
        ; // loop forever
    }
}

int _kill(int pid, int sig) {
    return -1;
}

int _getpid(void) {
    return 1;
}

int _write(int file, const void *ptr, size_t len)
{
	signed char *px_next = NULL;
	size_t len_r = 0;
	if ((file < 0) || (file == STDIN_FILENO) )
		return -1;
	if ((file == STDERR_FILENO) || (file == STDOUT_FILENO)) {
		px_next = (signed char *)ptr;
		while( len-- && *px_next ) {
			if (*px_next == '\n')
				putc_usart1('\r');
			putc_usart1(*px_next);
			px_next++;
			len_r++;
		}
	}
	return len_r;
}
