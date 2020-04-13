#include <iostream>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source = open("datafile.bin", O_RDONLY);
    int destination;

    long offset = 1024*1024*1024;    // 1GB
    size_t byte_count = 2*offset;    // 2GB

    if(source<0){
        std::cout<< "Source file not found." << "\n";
        return -1;
    }
    else{
       destination = open("newfile.bin", O_WRONLY|O_CREAT, 0666);
    }

    if(destination<0){
        std::cout<< "Destination file couldn't be created." << "\n";
        return -1;
    }

    sendfile64(destination, source, &offset, byte_count);

    close(destination);
    close(source);

    return 0;
}
