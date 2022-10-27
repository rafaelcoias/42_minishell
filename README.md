# 42_minishell

## Assigment

Create your own mini shell that works like a normal terminal shell. Make sure it follows the given rules.

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
  - <a href="https://man7.org/linux/man-pages/man3/rl_clear_history.3.html">rl_clear_history()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/rl_on_new_line.3.html">rl_on_new_line()</a>
  - <a href="https://man7.org/linux/man-pages/man3/rl_replace_line.3.html">rl_replace_line()</a>
  - <a href="https://man7.org/linux/man-pages/man3/rl_redisplay.3.html">rl_redisplay()</a>
  - <a href="https://man7.org/linux/man-pages/man3/add_history.3.html">add_history()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/waitpid.3.html">waitpid()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/signal.3.html">signal()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigaction.3.html">sigaction()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigemptyset.3.html">sigemptyset()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigaddset.3.html">sigaddset()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/kill.3.html">kill()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getcwd.3.html">getcwd()</a>
  - <a href="https://man7.org/linux/man-pages/man3/chdir.3.html">chdir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/stat.3.html">stat()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/fstat.3.html">fstat()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/unlink.3.html">unlink()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/execve.3.html">execve()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/dup2.3.html">dup2()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pipe.3.html">pipe()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/opendir.3.html">opendir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/readdir.3.html">readdir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/closedir.3.html">closedir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/isatty.3.html">isatty()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyname.3.html">ttyname()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyslot.3.html">ttyslot()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ioctl.3.html">ioctl()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getenv.3.html">getenv()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tcsetattr.3.html">tcsetattr()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tcgetattr.3.html">tcgetattr()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetent.3.html">tgetent()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetflag.3.html">tgetflag()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetstr.3.html">tgetstr()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tgoto.3.html">tgoto()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tputs3.html">tputs()</a> 
  
## Preview

<details><summary>My Minishell</summary>
  
Coming soon
  
</details>

<details><summary>My grade</summary>
  
Coming soon
  
</details>

<hr>

I hope you found it interesting!

If you are going to do minishell, I wish you good luck and hope that you learned something here!
