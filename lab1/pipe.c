#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd_pipe[2], in_fd;

  if (argc == 1)
    exit(EINVAL); // Handle missing command

  if (argc == 2) {
    // Single command case
    return execute_command(-1, -1, argv[1]);
  }

  pipe_helper(fd_pipe);

  for (int i = 1; i < argc; i++) {
    if (i == 1) {
      if (execute_command(-1, fd_pipe[1], argv[i]) != 0) {
        return -1; // Indicate failure
      }
      close(fd_pipe[1]);
      in_fd = fd_pipe[0];
    } else if (i == argc - 1) {
      // Last command
      if (execute_command(fd_pipe[0], -1, argv[i]) != 0) {
        return -1; // Indicate failure
      }
      close(fd_pipe[0]);
    } else {
      // Middle command
      int fd_mid[2];
      pipe_helper(fd_mid);

      if (execute_command(fd_pipe[0], fd_mid[1], argv[i]) != 0) {
        return -1; // Indicate failure
      }
      close_helper(fd_pipe[0]);
      close_helper(fd_mid[1]);

      fd_pipe[0] = fd_mid[0];
    }
  }

  return 0;
}


void dup_helper(int in, int out) {
  if (dup2(in, out) == -1) {
    perror("dup2");
    exit(errno);
  }
}

void close_helper(int fd) {
  if (close(fd) == -1) {
    perror("close");
    exit(errno);
  }
}

void pipe_helper(int *fd) {
  if (pipe(fd) == -1) {
    perror("pipe");
    exit(errno);
  }
}

int execute_command(int in_fd, int out_fd, char *command) {
  pid_t child = fork();

  if (child == -1) {
    perror("fork");
    exit(errno); 
  }

  if (child == 0) {
    if (in_fd != -1) {
      dup_helper(in_fd, STDIN_FILENO);
      close_helper(in_fd);
    }

    if (out_fd != -1) {
      dup_helper(out_fd, STDOUT_FILENO);
      close_helper(out_fd);
    }

    execlp(command, command, NULL);
    perror("execlp");
    exit(errno); // Handle execlp error
  }

  int status;
  waitpid(child, &status, 0);

  if (WIFEXITED(status)) {
    return WEXITSTATUS(status);
  } else {
    return -1; // Indicate failure
  }
}

