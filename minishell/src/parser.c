void    parser(char *input)
{
    int     i;
    int     ti;
    int     tj;
    char    token[1000][1000];
    
    i = 0;
    tj = 0;
    ti = 0;
    while (input[i])
    {
        data()->token = malloc(sizeof(t_token));
        while (input[i] && input[i] == ' ')
            i++;
        if (input[i] == '"')
        {
            i += 1;
            while (input[i] && input[i] != '"')
            {
                token [ti][tj] = input[i];
                i += 1;
                tj += 1;
            }
            i += 1;
        }
        else if (input[i] == 39)
        {
            i += 1;
            while (input[i] && input[i] != 39)
            {
                token [ti][tj] = input[i];
                i += 1;
                tj += 1;
            }
            i += 1;
        }
        else
        {
            while (input[i] && input[i] != ' ')
            {
                token [ti][tj] = input[i];
                i += 1;
                tj += 1;
            } 
        }
        token [ti][tj] = '\0';
        data()->token->word = token[ti];
        data()->token = data()->token->next;
        tj = 0;
        ti++;
    }
}
