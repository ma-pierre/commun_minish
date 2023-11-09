int	main(int ac, char **av, char **env)
{
	char	*start_line;
	t_cmds	*data_exec;
    t_env   *backup_env;
    int exit;

    (void)ac;
    (void)av;
	init_signal();
    env_init(&backup_env, env);
    exit = 0;
    while (exit == 0)
	{
		start_line = readline("Minishell> ");
		if (!start_line)
			ft_exit();
        data_exec = do_parsing(start_line, backup_env);
        // printf("%s\n", data_exec->cmd);
        if (data_exec)
            exit = dothis(data_exec, backup_env);
	}
    ft_free_lst(backup_env);
	return (g_exstatus);
}