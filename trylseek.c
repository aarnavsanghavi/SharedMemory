#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main() {
    int fd = open("testfile.txt", O_CREATE | O_RDWR);
    if (fd < 0) {
        printf(2, "Error: Failed to open file\n");
        exit();
    } else {
        printf(1, "Success: File opened successfully with fd = %d\n", fd);
    }

    int offset = 10; 
    int whence = 0;  // SEEK_SET (start of file)

    printf(1, "Calling lseek with fd = %d, offset = %d, whence = %d\n", fd, offset, whence);

    int new_offset = lseek(fd, offset, whence); // Seek to offset 10 from start
    if (new_offset < 0) {
        printf(2, "Error: lseek failed\n");
        close(fd);
        exit();
    } else {
        printf(1, "Success: lseek moved to offset %d\n", new_offset);
    }

    close(fd);
    printf(1, "Success: File closed successfully\n");
    exit();
}

