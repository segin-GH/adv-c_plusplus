#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    std::cout << "Starting..." << std::endl;

    // create a named pipe for receiving Event
    std::string pipe_name = "/tmp/event_pipe";
    mkfifo(pipe_name.c_str(), 0666);
    // open the pipe for reading
    int fd = open(pipe_name.c_str(), O_RDONLY);

    // create a named pipe for sending state
    std::string pipe_name2 = "/tmp/state_pipe";
    mkfifo(pipe_name2.c_str(), 0666);
    // open the pipe for writing
    int fd2 = open(pipe_name2.c_str(), O_WRONLY);

    while (true)
    {
        // read the Event from the pipe
        char buffer[1024];
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read > 0)
        {
            std::string event(buffer, bytes_read);
            std::cout << "Received Event: " << event << std::endl;

            // write the State to the pipe
            std::string state = "received " + event;
            write(fd2, state.c_str(), state.size());
            std::cout << "Sent State: " << state << std::endl;

            if (event == "quit")
                break;
        }
    }

    std::cout << "Exiting..." << std::endl;
    close(fd);                  // close the reading pipe
    close(fd2);                 // close the writing pipe
    unlink(pipe_name.c_str());  // remove the receiving pipe
    unlink(pipe_name2.c_str()); // remove the sending pipe
}