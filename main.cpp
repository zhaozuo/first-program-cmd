#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct user
{
    int ID;//用户编号
    char user_name[10];
    char user_psw[10];
    double money;//余额
} users[61];
void welcome();//欢迎界面
void filewrite();//账户信息写入文件
void fileread();//读取文件中的账户信息
void login();//管理员登录界面
void mainmenu();//主菜单
void new_count();//开户
void take();//取款
void save();//存款
void check();//查询账户
void clean();//销户
int N_new = 0;//账户数量
int N_wrong;//密码错误次数
int flag1;//标记
int i;
/*Copyright [1998-2017] by SDUT,jk1606,[WZZ]. All rights reserved.*/
/*主函数*/
int main()
{
    system("color 1E");
    welcome();
    fileread();
    login();
    mainmenu();
    return 0;
}
/*欢迎界面*/
void welcome()
{
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****           山东理工大学银行            ****\n");
    printf("           ****              欢迎您！O(∩_∩)O~       ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
}
/*读文件函数*/
void fileread()
{
    FILE *fp;
    fp = fopen("users_information.txt", "rt+");
    i = 0;
    while(fscanf(fp, "%d %s %s %lf", &users[i].ID, users[i].user_name, users[i].user_psw, &users[i].money) != EOF)
    {
        i++;
        N_new++;
    }
    fclose(fp);
}
/*写文件函数*/
void filewrite()
{
    FILE *fp;
    fp = fopen("users_information.txt", "wt+");
    for(i = 0; i < N_new; i++)
    {
        fprintf(fp, "%d %s %s %.4lf\n", users[i].ID, users[i].user_name, users[i].user_psw, users[i].money);
    }
    fclose(fp);
}
/*系统登录函数*/
void login()
{
    char cname[10] = {"admin"};
    N_wrong = 0;
    while(1)
    {
        printf("请输入管理员账号：");
        char s1[10];
        gets(s1);
        if(s1[0] == '\0')
            printf("用户名不能为空！\n");
        else if(!strcmp(s1,cname))
            break;
        else
        {
            int i;
            printf("该管理员不存在，请在 3 秒后重新输入！");
            Sleep(1000);
            for(i = 2; i > 0; i--)
            {
                printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%d 秒后重新输入！", i);
                Sleep(1000);
            }
            system("cls");
            welcome();
        }
    }
    while(1)
    {
        printf("请输入密码：");
        char s2[10];
        gets(s2);
        if(s2[0] == '\0')
            printf("密码不能为空！\n");
        else if(!strcmp(s2,cname))//密码正确，退出循环
            break;
        else
        {
            if(N_wrong >= 2)//密码错误次数限制
            {
                printf("密码错误次数过多，系统自动关闭！\n");
                exit(0);
            }
            printf("密码错误，请 3 秒后重新输入！");
            Sleep(1000);
            for(i = 2; i > 0; i--)
            {
                printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%d 秒后重新输入！", i);
                Sleep(1000);
            }
            system("cls");
            N_wrong++;
            welcome();
        }
    }
    system("cls");
    welcome();
    return;
}
/*主菜单函数*/
void mainmenu()
{
    while(1)
    {
        printf("-----------------------------\n");
        printf("请输入您要进行操作的编号：\n");
        printf("-----------------------------\n");
        printf("开户<1>    存款<2>    取款<3>\n");
        printf("查询<4>    销户<5>    退出<0>\n");
        printf("-----------------------------\n");
        int select;
        scanf("%d", &select);
        switch(select)
        {
        case 0:
        {
            printf("系统即将关闭，感谢您的使用，期待下次光临！");
            Sleep(1500);
            return;
        }
        case 1:
            new_count();
            break;
        case 2:
            save();
            break;
        case 3:
            take();
            break;
        case 4:
            check();
            break;
        case 5:
            clean();
        default:
            printf("请输入正确的指令！\n");
            Sleep(2000);
            system("cls");
            welcome();
        }
    }
    return;
}
/*开户函数*/
void new_count()
{
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               开户界面                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
    if(N_new >= 60)
    {
        printf("抱歉，注册账号数已达到上限，即将为您跳转到主菜单");
        Sleep(2000);
        system("cls");
        welcome();
        return;
    }
    else
    {
        int len;
        char s3[10], s4[10];
        while(1)
        {
            printf("请输入您的账户名：");
            scanf("%s", s3);
            len = strlen(s3);
            if(len > 6)
            {
                printf("您输入的账户名过长，请输入6位账户名！\n");
                Sleep(2000);
                continue;
            }
            else if(len < 6)
            {
                printf("您输入的账户名过短，请输入6位账户名！\n");
                Sleep(2000);
                continue;
            }
            flag1 = 0;
            for(i = 0; i < 6; i++)
            {
                if(s3[i] < 48 || (s3[i] < 65 && s3[i] > 57) || (s3[i] > 90 && s3[i] < 97)||s3[i] > 122)
                {
                    printf("账户名中不能包含特殊字符，请重新输入！\n");
                    flag1 = 1;
                    Sleep(2000);
                    break;
                }
            }
            if(flag1)continue;
            flag1 = 0;
            for(i = 0; i < N_new; i++)
            {
                if(strcmp(s3, users[i].user_name) == 0)
                {
                    printf("该账户名已存在，请重新输入！\n");
                    flag1 = 1;
                    Sleep(2000);
                    break;
                }
            }
            if(flag1)continue;
            else break;
        }
        strcpy(users[N_new].user_name, s3);
        while(1)
        {
            printf("请输入您的密码：");
            scanf("%s", s4);
            len = strlen(s4);
            if(len > 6)
            {
                printf("您输入的密码过长，请输入6位数密码！\n");
                Sleep(2000);
                continue;
            }
            else if(len < 6)
            {
                printf("您输入的密码过短，请输入6位数密码！\n");
                Sleep(2000);
                continue;
            }
            flag1 = 0;
            for(i = 0; i < 6; i++)
            {
                if(s4[i] < 48 || (s4[i] < 65 && s4[i] > 57) || (s4[i] > 90 && s4[i] < 97)||s4[i] > 122)
                {
                    printf("密码中不能包含特殊字符，请重新输入！\n");
                    flag1 = 1;
                    Sleep(2000);
                    break;
                }
            }
            if(!flag1)break;
        }
        strcpy(users[N_new].user_psw, s4);
        printf("请输入您要存款的金额（如暂不存款，请输入0）：");
        scanf("%lf", &users[N_new].money);
        users[N_new].ID = N_new + 1;
        printf("开户成功，即将显示您的账户信息：\n");
        Sleep(1000);
        printf("-----------------------------------------------\n");
        printf("ID:%d 账户名：%s 密码：%s 余额：%.4lf\n", users[N_new].ID,users[N_new].user_name,users[N_new].user_psw,users[N_new].money);
        printf("-----------------------------------------------\n");
        N_new++;
        printf("即将为你跳转到主菜单\n");
        filewrite();
        system("pause");
        system("cls");
        welcome();
        return;
    }
}
/*存款函数*/
void save()
{
    if(N_new == 0)
    {
        printf("无可操作账户，即将返回主菜单\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               存款界面                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
save1:
    printf("请输入您要存款的账户名：");
    char s5[10];
    scanf("%s", s5);
    double n;
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s5, users[i].user_name) == 0)
        {
            flag1 = 1;
            printf("请输入您要存款的金额：");
            scanf("%lf", &n);
            users[i].money += n;
            printf("存款成功，即将显示您的账户信息：\n");
            Sleep(1000);
            printf("--------------------------------------------------\n");
            printf("ID:%d 账户名：%s 余额：%.4lf\n", users[i].ID,users[i].user_name,users[i].money);
            printf("--------------------------------------------------\n");
            printf("即将为你跳转到主菜单\n");
            filewrite();
            system("pause");
            system("cls");
            welcome();
            return;
        }
    }
    if(flag1 == 0)
    {
        printf("该账户不存在，请重新输入！\n");
        Sleep(1000);
        goto save1;
    }
}
/*取款函数*/
void take()
{
    if(N_new == 0)
    {
        printf("无可操作账户，即将返回主菜单\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               取款界面                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
take1:
    printf("请输入您要取款的账户名：");
    char s8[10], s9[10];
    scanf("%s", s8);
    double n1;
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s8, users[i].user_name) == 0)
        {
            N_wrong = 0;
            flag1 = 1;
take2:
            printf("请输入密码：");
            scanf("%s", s9);
            if(strcmp(s9, users[i].user_psw) == 0)
            {
                printf("-----------------------------------\n");
                printf("您的账户可用余额为：%.4lf\n", users[i].money);
                printf("-----------------------------------\n");
                while(1)
                {
                    printf("请输入您的取款金额：");
                    scanf("%lf", &n1);
                    if(n1 > users[i].money)
                    {
                        printf("余额不足，请重新输入！\n");
                        Sleep(1000);
                    }
                    else
                    {
                        printf("取款成功，请收好您的现金\n");
                        users[i].money -= n1;
                        printf("-----------------------------------\n");
                        printf("您的账户当前可用余额为：%.4lf\n", users[i].money);
                        printf("-----------------------------------\n");
                        break;
                    }
                }
                printf("即将为你跳转到主菜单\n");
                filewrite();
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else
            {
                if(N_wrong >= 2)//密码错误次数限制
                {
                    printf("密码错误次数过多，即将为你跳转到主菜单\n");
                    Sleep(1000);
                    system("cls");
                    welcome();
                    return;
                }
                printf("密码错误，请重新输入！\n");
                N_wrong++;
                Sleep(1000);
                goto take2;
            }
        }
    }
    if(flag1 == 0)
    {
        printf("该账户不存在，请重新输入！\n");
        Sleep(1000);
        goto take1;
    }
}
/*查询余额函数*/
void check()
{
    if(N_new == 0)
    {
        printf("无可操作账户，即将返回主菜单\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               查询界面                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
check1:
    printf("请输入您要查询的账户名：");
    char s10[10], s11[10];
    scanf("%s", s10);
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s10, users[i].user_name) == 0)
        {
            N_wrong = 0;
            flag1 = 1;
check2:
            printf("请输入密码：");
            scanf("%s", s11);
            if(strcmp(s11, users[i].user_psw) == 0)
            {
                printf("-----------------------------------------------\n");
                printf("ID:%d 账户名：%s 余额：%.4lf\n", users[i].ID,users[i].user_name,users[i].money);
                printf("-----------------------------------------------\n");
                printf("即将为你跳转到主菜单\n");
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else
            {
                if(N_wrong >= 2)//密码错误次数限制
                {
                    printf("密码错误次数过多，即将为你跳转到主菜单\n");
                    Sleep(1000);
                    system("cls");
                    welcome();
                    return;
                }
                printf("密码错误，请重新输入！\n");
                N_wrong++;
                Sleep(1000);
                goto check2;
            }
        }
    }
    if(flag1 == 0)
    {
        printf("该账户不存在，请重新输入！\n");
        Sleep(1000);
        goto check1;
    }
}
/*销户函数*/
void clean()
{
    if(N_new == 0)
    {
        printf("无可操作账户，即将返回主菜单\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               销户界面                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
    char s6[10], s7[10];
clean1:
    printf("请输入您要注销的账户（注销账户余额将被清零，请谨慎操作）：");
    scanf("%s", s6);
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s6, users[i].user_name) == 0)
        {
            N_wrong = 0;
            flag1 = 1;
clean2:
            printf("请输入密码：");
            scanf("%s", s7);
            if(strcmp(s7, users[i].user_psw) == 0)
            {
                printf("正在注销您的账户\n");
                Sleep(2000);
                printf("注销成功！\n");
                for(int j = i+1; j < N_new; j++)
                {
                    users[j].ID--;
                }
                for(int j = i; j+1 < N_new; j++)
                {
                    users[j] = users[j+1];
                }
                N_new--;
                printf("即将为你跳转到主菜单\n");
                filewrite();
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else if(N_wrong >= 2)//密码错误次数限制
            {
                printf("密码错误次数过多，即将为你跳转到主菜单\n");
                Sleep(1000);
                system("cls");
                welcome();
                return;
            }
            printf("密码错误，请重新输入！\n");
            N_wrong++;
            Sleep(1000);
            goto clean2;
        }
    }
    if(flag1 == 0)
    {
        printf("该账户不存在，请重新输入！\n");
        Sleep(1000);
        goto clean1;
    }
}
