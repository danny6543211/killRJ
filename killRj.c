#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int kill_process(int PID)
{
    char cmd[30] = "taskkill /pid ";
    char pid[10];
    itoa(PID, pid, 10);
    strcat(cmd, pid);
    strcat(cmd, " -f");

    system(cmd);
}

int find_PID(char *process_name)
{
    // 刷新tasklist
    char cmd[30] = "tasklist | findstr ";
    strcat(cmd, process_name);
    strcat(cmd, " > tasklist.txt");
    system(cmd);

    // 讀取tasklist
    FILE *file;
    char buffer[100];
    file = fopen("tasklist.txt", "r");

    fgets(buffer, sizeof(buffer), file);
    char *pid = strstr(buffer, "exe");
    // 沒查到
    if (pid == NULL)
        return -1;
    
    // 查到了
    // 跳到exe後面
    pid += 3;
    // 跳過空格
    while (*pid == ' ')
        pid++;
    // 寫入pid
    char res[10];
    for (int i = 0; i < 5; i++)
    {
        res[i] = pid[i];
    }
    return atoi(res);
}

int main()
{

    int pid_8021 = find_PID("8021x.exe");
    kill_process(pid_8021);
    Sleep(1000);
    
    int pid_suservice = find_PID("suservice.exe");
    kill_process(pid_suservice);
    Sleep(1000);
    
    pid_8021 = find_PID("8021x.exe");
    kill_process(pid_8021);
    Sleep(1000);

    system("pause");

    return 0;
}
