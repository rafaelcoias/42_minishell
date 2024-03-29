# 42_minishell

## Assigment

Create your own mini shell that works like a normal terminal shell. Make sure it follows the given rules.

## Skills Learned

  - Forks - processes
  - New C libraries and its functions
  - Change file descriptors
  - Signals between processes

## Rules

  - Display a prompt when waiting for a new command.
  - Have a working directory
  - Search and launch the right executable
  - Handle ' and "  (single and double quotes)
  - Handle redirections (< , > , << and >>)
  - Implement here_doc
  - Implement pipes
  - Handle environment variables
  - Handle $?
  - Handle signals like ctrl-C , ctrl-D and crtl-\ which should work like bash
  - Implement the following builtins
    - echo 
    - pwd 
    - cd 
    - export 
    - unset
    - env
    - exit
  - You can only use the functions given in the project pdf
    
## Before doing Minishell

Make sure you know what all the following function are and what they do

  - <a href="https://man7.org/linux/man-pages/man3/readline.3.html">readline()</a> 
  - <a href="https://manpages.org/termreadlinegnu/3">all readline functions</a> 
  - <a href="https://linux.die.net/man/3/history">add_history()</a> 
  - <a href="https://linux.die.net/man/2/waitpid">waitpid()</a> 
  - <a href="https://man7.org/linux/man-pages/man7/signal.7.html">signal()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/sigaction.2.html">sigaction()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigemptyset.3p.html">sigemptyset()</a> 
  - <a href="https://linux.die.net/man/3/sigaddset">sigaddset()</a> 
  - <a href="https://linux.die.net/man/1/kill">kill()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getcwd.3.html">getcwd()</a>
  - <a href="https://man7.org/linux/man-pages/man2/chdir.2.html">chdir()</a>
  - <a href="https://man7.org/linux/man-pages/man2/stat.2.html">stat()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/fstat.2.html">fstat()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/unlink.2.html">unlink()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/execve.2.html">execve()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/dup2.2.html">dup2()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/pipe.2.html">pipe()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/opendir.3.html">opendir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/readdir.3.html">readdir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/closedir.3.html">closedir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/isatty.3.html">isatty()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyname.3.html">ttyname()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyslot.3.html">ttyslot()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/ioctl.2.html">ioctl()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getenv.3.html">getenv()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tcsetattr.3.html">tcsetattr()</a> 
  - <a href="https://linux.die.net/man/3/tgetent">tgetent()</a>
  - <a href="https://linux.die.net/man/3/tgetflag">tgetflag()</a>
  - <a href="https://linux.die.net/man/3/tgetstr">tgetstr()</a> 
  - <a href="https://linux.die.net/man/3/tgoto">tgoto()</a> 
  - <a href="https://linux.die.net/man/3/tputs">tputs()</a> 
  
  ## Preview

<details><summary>My grade</summary>
  
![Screenshot from 2023-08-30 04-32-20](https://github.com/rafaelcoias/42_minishell/assets/91686183/6556f233-71a5-45ff-8d0f-e9b32c24e41c)
  
</details>

<hr>

I hope you found it interesting!

If you are going to do minishell, I wish you good luck and hope that you learned something here!
