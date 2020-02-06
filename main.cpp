#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct user
{
    int ID;//�û����
    char user_name[10];
    char user_psw[10];
    double money;//���
} users[61];
void welcome();//��ӭ����
void filewrite();//�˻���Ϣд���ļ�
void fileread();//��ȡ�ļ��е��˻���Ϣ
void login();//����Ա��¼����
void mainmenu();//���˵�
void new_count();//����
void take();//ȡ��
void save();//���
void check();//��ѯ�˻�
void clean();//����
int N_new = 0;//�˻�����
int N_wrong;//����������
int flag1;//���
int i;
/*Copyright [1998-2017] by SDUT,jk1606,[WZZ]. All rights reserved.*/
/*������*/
int main()
{
    system("color 1E");
    welcome();
    fileread();
    login();
    mainmenu();
    return 0;
}
/*��ӭ����*/
void welcome()
{
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****           ɽ������ѧ����            ****\n");
    printf("           ****              ��ӭ����O(��_��)O~       ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
}
/*���ļ�����*/
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
/*д�ļ�����*/
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
/*ϵͳ��¼����*/
void login()
{
    char cname[10] = {"admin"};
    N_wrong = 0;
    while(1)
    {
        printf("���������Ա�˺ţ�");
        char s1[10];
        gets(s1);
        if(s1[0] == '\0')
            printf("�û�������Ϊ�գ�\n");
        else if(!strcmp(s1,cname))
            break;
        else
        {
            int i;
            printf("�ù���Ա�����ڣ����� 3 ����������룡");
            Sleep(1000);
            for(i = 2; i > 0; i--)
            {
                printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%d ����������룡", i);
                Sleep(1000);
            }
            system("cls");
            welcome();
        }
    }
    while(1)
    {
        printf("���������룺");
        char s2[10];
        gets(s2);
        if(s2[0] == '\0')
            printf("���벻��Ϊ�գ�\n");
        else if(!strcmp(s2,cname))//������ȷ���˳�ѭ��
            break;
        else
        {
            if(N_wrong >= 2)//��������������
            {
                printf("�������������࣬ϵͳ�Զ��رգ�\n");
                exit(0);
            }
            printf("��������� 3 ����������룡");
            Sleep(1000);
            for(i = 2; i > 0; i--)
            {
                printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%d ����������룡", i);
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
/*���˵�����*/
void mainmenu()
{
    while(1)
    {
        printf("-----------------------------\n");
        printf("��������Ҫ���в����ı�ţ�\n");
        printf("-----------------------------\n");
        printf("����<1>    ���<2>    ȡ��<3>\n");
        printf("��ѯ<4>    ����<5>    �˳�<0>\n");
        printf("-----------------------------\n");
        int select;
        scanf("%d", &select);
        switch(select)
        {
        case 0:
        {
            printf("ϵͳ�����رգ���л����ʹ�ã��ڴ��´ι��٣�");
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
            printf("��������ȷ��ָ�\n");
            Sleep(2000);
            system("cls");
            welcome();
        }
    }
    return;
}
/*��������*/
void new_count()
{
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               ��������                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
    if(N_new >= 60)
    {
        printf("��Ǹ��ע���˺����Ѵﵽ���ޣ�����Ϊ����ת�����˵�");
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
            printf("�����������˻�����");
            scanf("%s", s3);
            len = strlen(s3);
            if(len > 6)
            {
                printf("��������˻���������������6λ�˻�����\n");
                Sleep(2000);
                continue;
            }
            else if(len < 6)
            {
                printf("��������˻������̣�������6λ�˻�����\n");
                Sleep(2000);
                continue;
            }
            flag1 = 0;
            for(i = 0; i < 6; i++)
            {
                if(s3[i] < 48 || (s3[i] < 65 && s3[i] > 57) || (s3[i] > 90 && s3[i] < 97)||s3[i] > 122)
                {
                    printf("�˻����в��ܰ��������ַ������������룡\n");
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
                    printf("���˻����Ѵ��ڣ����������룡\n");
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
            printf("�������������룺");
            scanf("%s", s4);
            len = strlen(s4);
            if(len > 6)
            {
                printf("����������������������6λ�����룡\n");
                Sleep(2000);
                continue;
            }
            else if(len < 6)
            {
                printf("�������������̣�������6λ�����룡\n");
                Sleep(2000);
                continue;
            }
            flag1 = 0;
            for(i = 0; i < 6; i++)
            {
                if(s4[i] < 48 || (s4[i] < 65 && s4[i] > 57) || (s4[i] > 90 && s4[i] < 97)||s4[i] > 122)
                {
                    printf("�����в��ܰ��������ַ������������룡\n");
                    flag1 = 1;
                    Sleep(2000);
                    break;
                }
            }
            if(!flag1)break;
        }
        strcpy(users[N_new].user_psw, s4);
        printf("��������Ҫ���Ľ����ݲ���������0����");
        scanf("%lf", &users[N_new].money);
        users[N_new].ID = N_new + 1;
        printf("�����ɹ���������ʾ�����˻���Ϣ��\n");
        Sleep(1000);
        printf("-----------------------------------------------\n");
        printf("ID:%d �˻�����%s ���룺%s ��%.4lf\n", users[N_new].ID,users[N_new].user_name,users[N_new].user_psw,users[N_new].money);
        printf("-----------------------------------------------\n");
        N_new++;
        printf("����Ϊ����ת�����˵�\n");
        filewrite();
        system("pause");
        system("cls");
        welcome();
        return;
    }
}
/*����*/
void save()
{
    if(N_new == 0)
    {
        printf("�޿ɲ����˻��������������˵�\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               ������                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
save1:
    printf("��������Ҫ�����˻�����");
    char s5[10];
    scanf("%s", s5);
    double n;
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s5, users[i].user_name) == 0)
        {
            flag1 = 1;
            printf("��������Ҫ���Ľ�");
            scanf("%lf", &n);
            users[i].money += n;
            printf("���ɹ���������ʾ�����˻���Ϣ��\n");
            Sleep(1000);
            printf("--------------------------------------------------\n");
            printf("ID:%d �˻�����%s ��%.4lf\n", users[i].ID,users[i].user_name,users[i].money);
            printf("--------------------------------------------------\n");
            printf("����Ϊ����ת�����˵�\n");
            filewrite();
            system("pause");
            system("cls");
            welcome();
            return;
        }
    }
    if(flag1 == 0)
    {
        printf("���˻������ڣ����������룡\n");
        Sleep(1000);
        goto save1;
    }
}
/*ȡ���*/
void take()
{
    if(N_new == 0)
    {
        printf("�޿ɲ����˻��������������˵�\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               ȡ�����                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
take1:
    printf("��������Ҫȡ����˻�����");
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
            printf("���������룺");
            scanf("%s", s9);
            if(strcmp(s9, users[i].user_psw) == 0)
            {
                printf("-----------------------------------\n");
                printf("�����˻��������Ϊ��%.4lf\n", users[i].money);
                printf("-----------------------------------\n");
                while(1)
                {
                    printf("����������ȡ���");
                    scanf("%lf", &n1);
                    if(n1 > users[i].money)
                    {
                        printf("���㣬���������룡\n");
                        Sleep(1000);
                    }
                    else
                    {
                        printf("ȡ��ɹ������պ������ֽ�\n");
                        users[i].money -= n1;
                        printf("-----------------------------------\n");
                        printf("�����˻���ǰ�������Ϊ��%.4lf\n", users[i].money);
                        printf("-----------------------------------\n");
                        break;
                    }
                }
                printf("����Ϊ����ת�����˵�\n");
                filewrite();
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else
            {
                if(N_wrong >= 2)//��������������
                {
                    printf("�������������࣬����Ϊ����ת�����˵�\n");
                    Sleep(1000);
                    system("cls");
                    welcome();
                    return;
                }
                printf("����������������룡\n");
                N_wrong++;
                Sleep(1000);
                goto take2;
            }
        }
    }
    if(flag1 == 0)
    {
        printf("���˻������ڣ����������룡\n");
        Sleep(1000);
        goto take1;
    }
}
/*��ѯ����*/
void check()
{
    if(N_new == 0)
    {
        printf("�޿ɲ����˻��������������˵�\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               ��ѯ����                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
check1:
    printf("��������Ҫ��ѯ���˻�����");
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
            printf("���������룺");
            scanf("%s", s11);
            if(strcmp(s11, users[i].user_psw) == 0)
            {
                printf("-----------------------------------------------\n");
                printf("ID:%d �˻�����%s ��%.4lf\n", users[i].ID,users[i].user_name,users[i].money);
                printf("-----------------------------------------------\n");
                printf("����Ϊ����ת�����˵�\n");
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else
            {
                if(N_wrong >= 2)//��������������
                {
                    printf("�������������࣬����Ϊ����ת�����˵�\n");
                    Sleep(1000);
                    system("cls");
                    welcome();
                    return;
                }
                printf("����������������룡\n");
                N_wrong++;
                Sleep(1000);
                goto check2;
            }
        }
    }
    if(flag1 == 0)
    {
        printf("���˻������ڣ����������룡\n");
        Sleep(1000);
        goto check1;
    }
}
/*��������*/
void clean()
{
    if(N_new == 0)
    {
        printf("�޿ɲ����˻��������������˵�\n");
        Sleep(1000);
        system("cls");
        welcome();
        return;
    }
    system("cls");
    printf("           ***********************************************\n");
    printf("           ****                                       ****\n");
    printf("           ****               ��������                ****\n");
    printf("           ****                                       ****\n");
    printf("           ***********************************************\n");
    char s6[10], s7[10];
clean1:
    printf("��������Ҫע�����˻���ע���˻��������㣬�������������");
    scanf("%s", s6);
    flag1 = 0;
    for(i = 0; i < N_new; i++)
    {
        if(strcmp(s6, users[i].user_name) == 0)
        {
            N_wrong = 0;
            flag1 = 1;
clean2:
            printf("���������룺");
            scanf("%s", s7);
            if(strcmp(s7, users[i].user_psw) == 0)
            {
                printf("����ע�������˻�\n");
                Sleep(2000);
                printf("ע���ɹ���\n");
                for(int j = i+1; j < N_new; j++)
                {
                    users[j].ID--;
                }
                for(int j = i; j+1 < N_new; j++)
                {
                    users[j] = users[j+1];
                }
                N_new--;
                printf("����Ϊ����ת�����˵�\n");
                filewrite();
                system("pause");
                system("cls");
                welcome();
                return;
            }
            else if(N_wrong >= 2)//��������������
            {
                printf("�������������࣬����Ϊ����ת�����˵�\n");
                Sleep(1000);
                system("cls");
                welcome();
                return;
            }
            printf("����������������룡\n");
            N_wrong++;
            Sleep(1000);
            goto clean2;
        }
    }
    if(flag1 == 0)
    {
        printf("���˻������ڣ����������룡\n");
        Sleep(1000);
        goto clean1;
    }
}
