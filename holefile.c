/*************************************************************************
	> File Name: holefile.c
	> Author: zhouming
	> Mail: wy39666161@163.com 
	> Created Time: 2015年01月04日 星期日 19时47分48秒
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int		fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0) {
		err_sys("creat error");
	}
	if (write(fd, buf1, 10) != 10) {
		err_sys("buf1 write error");
	}
	/*offset now = 10 */
	if (lseek(fd, 16384, SEEK_SET) == -1) {
		err_sys("lseek error");
	}
	/*offset now = 16384 */
	if (write(fd, buf2, 10) != 10) {
		err_sys("buf2 write error");
	}
	/*offset now = 16394*/
	close(fd);
	exit(0);
}
