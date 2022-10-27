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
  - <a href="https://man7.org/linux/man-pages/man3/rl_clear_history.html">rl_clear_history()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/rl_on_new_line.html">rl_on_new_line()</a>
  - <a href="https://man7.org/linux/man-pages/man3/rl_replace_line.html">rl_replace_line()</a>
  - <a href="https://man7.org/linux/man-pages/man3/rl_redisplay.html">rl_redisplay()</a>
  - <a href="https://man7.org/linux/man-pages/man3/add_history.html">add_history()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/waitpid.html">waitpid()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/signal.html">signal()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigaction.html">sigaction()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigemptyset.html">sigemptyset()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/sigaddset.html">sigaddset()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/kill.html">kill()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getcwd.html">getcwd()</a>
  - <a href="https://man7.org/linux/man-pages/man3/chdir.html">chdir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/stat.html">stat()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/fstat.html">fstat()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/unlink.html">unlink()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/execve.html">execve()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/dup2.html">dup2()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pipe.html">pipe()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/opendir.html">opendir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/readdir.html">readdir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/closedir.html">closedir()</a>
  - <a href="https://man7.org/linux/man-pages/man3/isatty.html">isatty()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyname.html">ttyname()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ttyslot.html">ttyslot()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/ioctl.html">ioctl()</a>
  - <a href="https://man7.org/linux/man-pages/man3/getenv.html">getenv()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tcsetattr.html">tcsetattr()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tcgetattr.html">tcgetattr()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetent.html">tgetent()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetflag.html">tgetflag()</a>
  - <a href="https://man7.org/linux/man-pages/man3/tgetstr.html">tgetstr()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tgoto.html">tgoto()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/tputs.html">tputs()</a> 
  
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
